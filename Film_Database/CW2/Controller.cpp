#include "Controller.h"


static vector<Project> projects;
static vector<string> materialProperties;
static vector<Material*> materials;

static const string projectFileName = "Projects.txt"; ;
static const string materialFileName = "Materials.txt"; 

void Controller::saveProjectsMaterialsToFile()
{
	if (projects.size() > 0)
	{
		vector<string> serializedProjectCrewProperties;
		for (unsigned int i = 0; i < projects.size(); i++)
		{
			serializedProjectCrewProperties.push_back(serializeProjectCrew(projects[i].getProjectCrewProperties()));
		}

		FileManager::saveProperties(projectFileName, serializedProjectCrewProperties);
	}
	else
	{
		vector<string> blank;
		blank.push_back("");
		FileManager::saveProperties(projectFileName, blank);
	}



	if (materials.size() > 0)
	{
		vector<string> serializedMaterialProperties;
		for (unsigned int i = 0; i < materials.size(); i++)
		{
			if (materials[i]->getMaterialType() == "VHS")
				serializedMaterialProperties.push_back(serializeVHS(materials[i]->getProperties()));
			else if ((materials[i]->getMaterialType() == "SINGLE-SIDED_BLUERAY")|| (materials[i]->getMaterialType() == "SINGLE-SIDED_DVD"))
				serializedMaterialProperties.push_back(serializeSingle_Sided(materials[i]->getProperties()));
			else if ((materials[i]->getMaterialType() == "DOUBLE-SIDED_BLUERAY") || (materials[i]->getMaterialType() == "DOUBLE-SIDED_DVD"))
				serializedMaterialProperties.push_back(serializeDouble_Sided(materials[i]->getProperties()));
			else if (materials[i]->getMaterialType() == "COMBO-BOX")
			{
				vector<vector<string>> tempProp = materials[i]->getProperties();
				serializedMaterialProperties.push_back(serializeComboBox(tempProp));
			}
				
			
		}

		FileManager::saveProperties(materialFileName, serializedMaterialProperties);
	}
	else
	{
		vector<string> blank;
		blank.push_back("");
		FileManager::saveProperties(materialFileName, blank);

	}

}


string Controller::serializeVHS(vector<vector<string>> material)
{
	string serializedString = "";

	serializedString = serialize(material[0], ',');

	serializedString.pop_back();

	return serializedString;

}

string Controller::serialize(vector<string> forSerializing, char key)
{
	string serializeString;
	for (unsigned int i = 0; i < forSerializing.size(); i++)
		serializeString += forSerializing[i] + key;
	serializeString.back() = ',';

	return serializeString;
}

bool Controller::isProjectValid(int projectID)
{
	if (projects.size() != 0)
	{
		for (unsigned int i = 0; i < projects.size(); i++)
		{
			string pStatus = projects[i].getProjectStatus();
			transform(pStatus.begin(), pStatus.end(), pStatus.begin(), ::toupper);
			if ((projects[i].getID() == projectID)&&(pStatus == "RELEASED"))
			{
				return true;
			}
		}

	}

	return false;
}

string Controller::serializeSingle_Sided(vector<vector<string>> material)
{
	vector<string> materialProperties, languages, subtitles, contents;
	string serializedString = "";

	materialProperties = material[0];

	serializedString = serialize(materialProperties, ',');

	languages = material[1];
	serializedString += serialize(languages, '-');

	subtitles = material[2];
	serializedString += serialize(subtitles, '-');

	contents = material[3];
	serializedString += serialize(contents, '-');

	serializedString.pop_back();

	return serializedString;


	return string();
}

string Controller::serializeDouble_Sided(vector<vector<string>> material)
{
	vector<string> materialProperties, languages, subtitles, contentsSideA, contentsSideB;
	string serializedString = "";

	materialProperties = material[0];

	serializedString = serialize(materialProperties, ',');

	languages = material[1];
	serializedString += serialize(languages, '-');

	subtitles = material[2];
	serializedString += serialize(subtitles, '-');

	contentsSideA = material[3];
	if (contentsSideA.size() != 0)
	{
		contentsSideA[0] = "Side A -" + contentsSideA[0];
		serializedString += serialize(contentsSideA, '-');
		serializedString.back() = ',';
	}
	if (contentsSideB.size() != 0)
	{
		contentsSideB = material[4];
		contentsSideB[0] = "Side B -" + contentsSideB[0];
		serializedString += serialize(contentsSideA, '-');
	}

	serializedString.pop_back();

	return serializedString;

}

string Controller::serializeComboBox(vector<vector<string>> material)
{
	string serializedString = serialize(material[0],',');
	if (material[1].size() > 0)
	{
		serializedString = serializedString + serialize(material[1], '-');
	}

	return serializedString;
}

void Controller::makeMaterial(string serializedString = "")
{
	Material* tempMaterial;
	stringstream materialStream(serializedString);
	vector<string> materialDetails;

	materialDetails.push_back("");
	int i = 0;
	while (getline(materialStream, materialDetails[i], '\\'))
	{
		materialDetails.push_back("");
		i++;
	}

	if (materialDetails[0] == "VHS")
	{
		
		tempMaterial = new VHS(materialDetails[1]);
	}
	else if ((materialDetails[0] == "SINGLE-SIDED_DVD")|| (materialDetails[0] == "SINGLE-SIDED_BLUERAY"))
	{
		tempMaterial = new Single_SidedOpticalDisc(materialDetails[0],materialDetails[1]);
	}
	else if ((materialDetails[0] == "DOUBLE-SIDED_DVD") || (materialDetails[0] == "DOUBLE-SIDED_BLUERAY"))
	{
		tempMaterial = new Double_SidedOpticalDisc(materialDetails[0],materialDetails[1]);
	}
	else if (materialDetails[0] == "COMBO-BOX")
	{
		tempMaterial = new ComboBox(materialDetails[1]);
	}


	materials.push_back(tempMaterial);

};

void Controller::askForMaterials()
{
	string serializedMaterials;
	string projectID = "z";
	bool projectExists = false;
	while ((projectExists == false) && (projectID != "c"))
	{
		projectID = View::askForProjectID();
		projectExists = isProjectValid(atoi(projectID.c_str()));
		if (projectExists == true)
		{
			string materialType = View::getMaterialType();
			
			if (materialType == "VHS")
			{
				vector<string> materialProperties = View::addVHS();
				string ID = (materials.empty() == true) ? "00" : to_string(materials.back()->getID() + 1);
				materialProperties[0] = materialProperties[0] + "\\" + ID;
				vector<vector<string>> overallMaterialProperties;
				overallMaterialProperties.push_back(materialProperties);
				serializedMaterials = serializeVHS(overallMaterialProperties);
				makeMaterial(serializedMaterials);
			}
			else if ((materialType == "SINGLE-SIDED_DVD") || (materialType == "SINGLE-SIDED_BLUERAY"))
			{
				vector<vector<string>> materialProperties = View::addSingleSided(materialType);
				string ID = (materials.empty() == true) ? "00" : to_string(materials.back()->getID() + 1);
				materialProperties[0][0] = materialProperties[0][0] + "\\" + ID;
				serializedMaterials = serializeSingle_Sided(materialProperties);
				makeMaterial(serializedMaterials);
			}
			else if ((materialType == "DOUBLE-SIDED_DVD") || (materialType == "DOUBLE-SIDED_BLUERAY"))
			{
				vector<vector<string>> materialProperties = View::addDoubleSided(materialType);
				string ID = (materials.empty() == true) ? "00" : to_string(materials.back()->getID() + 1);
				materialProperties[0][0] = materialProperties[0][0] + "\\" + ID;
				serializedMaterials = serializeDouble_Sided(materialProperties);
				makeMaterial(serializedMaterials);
			}
			else if (materialType == "COMBO-BOX")
			{
				string serializedSubMaterial;
				vector<string> comboBoxProperties = View::addComboBox(materialType);
				string ID = (materials.empty() == true) ? "00" : to_string(materials.back()->getID() + 1);
				comboBoxProperties[0] = comboBoxProperties[0] + "\\" + ID;
				int count = 0;
				vector<string> materialID;
				vector<string> subMaterials;
				while ((materialType != "c")&&(count < 3)&&(!(count > 2)))
				{					
					materialType = View::askToAddMaterials();
					if (materialType == "DOUBLE-SIDED_DVD")
					{
						count++;
						vector<vector<string>> materialProperties = View::addDoubleSided(materialType);
						materialProperties[0][0] = materialProperties[0][0] + "\\" + to_string(atoi(ID.c_str()) + count);
						serializedSubMaterial = serializeDouble_Sided(materialProperties);
						
						subMaterials.push_back(serializedSubMaterial);
						materialID.push_back(to_string(atoi(ID.c_str()) + count));
					}
					else if (materialType == "SINGLE-SIDED_DVD")
					{
						count++;
						vector<vector<string>> materialProperties = View::addSingleSided(materialType);
						materialProperties[0][0] = materialProperties[0][0] + "\\" + to_string(atoi(ID.c_str())+ count);
						serializedSubMaterial = serializeSingle_Sided(materialProperties);
						
						subMaterials.push_back(serializedSubMaterial);
						materialID.push_back(to_string(atoi(ID.c_str()) + count));
					}
					
				}
				vector<vector<string>> materialProperties;
				materialProperties.push_back(comboBoxProperties);
				materialProperties.push_back(materialID);
				serializedMaterials = serializeComboBox(materialProperties);
				
				makeMaterial(serializedMaterials);
				for (unsigned int i = 0; i < subMaterials.size(); i++)
				{
					makeMaterial(subMaterials[i]);
				}
					
			}

			for (unsigned int i = 0; i < projects.size(); i++)
			{
				if (projects[i].getID() == atoi(projectID.c_str()))
				{
					map<int, string> materialIDandProperties;
					projects[i].addMaterial(materials.back()->getID());
					break;
				}
			}
		}


	}
}

string Controller::serializeProjectCrew(vector<vector<string>> projectCrew)
{
	vector<string> projectDetails, keyWords, filmingLocations, crewDetails, castOfActors, materialIDs;
	string serializedString = "";

	if (projectCrew[0].size() > 0)
	{
		projectDetails = projectCrew[0];
		serializedString = serialize(projectDetails, ',');
	}

	if (projectCrew[1].size() > 0)
	{
		keyWords = projectCrew[1];
		serializedString += serialize(keyWords, '-');
	}

	if (projectCrew[2].size() > 0)
	{
		filmingLocations = projectCrew[2];
		serializedString += serialize(filmingLocations, '-');
	}

	if (projectCrew[3].size() > 0)
	{
		crewDetails = projectCrew[3];
		serializedString += serialize(crewDetails, ',');
	}

	if (projectCrew[4].size() > 0)
	{
		castOfActors = projectCrew[4];
		serializedString += serialize(castOfActors, '-');
	}

	if (projectCrew[5].size() > 0)
	{
		materialIDs = projectCrew[5];
		serializedString += serialize(materialIDs, '-');
	}



	return serializedString;
}

void Controller::makeProjectAndCrew()
{

	vector<vector<string>> projectCrew = View::addAProjectCrew();

	string serializedString = serializeProjectCrew(projectCrew);

	serializedString = ',' + serializedString;
	if (projects.empty() == true)
		serializedString = "00" + serializedString;
	else
		serializedString = to_string((projects.back().getID() + 1)) + serializedString;

	Project tempProject(serializedString);
	projects.push_back(tempProject);

}

void Controller::parseProjectsMaterials()
{
	vector<string> projectsFromFile = FileManager::loadFile(projectFileName);
	if (projectsFromFile.size() != 0)
	{
		if (projectsFromFile[0] != "")
		{
			for (unsigned int i = 0; i < projectsFromFile.size(); i++)
			{
				Project tempProject(projectsFromFile[i]);
				projects.push_back(tempProject);
			}
		}
	}

	vector<string> materialsFromFile = FileManager::loadFile(materialFileName);
	if (materialsFromFile.size() != 0)
	{
		if (projectsFromFile[0] != "")
		{
			for (unsigned int i = 0; i < materialsFromFile.size(); i++)
			{
				makeMaterial(materialsFromFile[i]);
			}
		}
	}
}

void Controller::reviewOption(char option)
{
	string projectID;
	switch (option)
	{
	case 'a':
		View::displayMessage("ID\t   Film Title\t\t\t\t    Summary\t\t     Status");
		for (unsigned int i = 0; i < projects.size(); i++)
			View::displayMessage(to_string(projects[i].getID()) + "  " + projects[i].getTitle() +"\t\t"+ projects[i].getSummary() + "\t\t" + projects[i].getProjectStatus());
		break;
	case 'b':
		projectID = View::askForProjectID();
		for (unsigned int i = 0; i < projects.size(); i++)
		{
			if (to_string(projects[i].getID()) == projectID)
			{
				View::displayMessage(to_string(projects[i].getID()) + "  " + projects[i].getTitle() + "\t" + projects[i].getSummary() + "\t\t" + projects[i].getGenre() + "\t" + to_string(projects[i].getReleaseDate()) + "\t" + projects[i].getLanguage() + "\t" + to_string(projects[i].getRunTime()) + "\t" + to_string(projects[i].getWeeklyTicketSale()) + "\t" + projects[i].getProjectStatus());
			}
		}
		break;
	case 'c':
		View::displayMessage("ID\t   Film Title\t\t\t\t    Summary\t\t");
		for (unsigned int i = 0; i < projects.size(); i++)
		{
			if (projects[i].getProjectStatus() == "RELEASED")
				View::displayMessage(to_string(projects[i].getID()) + "  " + projects[i].getTitle() + "\t\t" + projects[i].getSummary());
		}
		break;
	case 'e':
		View::displayMessage("ID\t   Film Title\t\t\t\t    Summary\t\t");
		for (unsigned int i = 0; i < projects.size(); i++)
		{
			if (projects[i].getProjectStatus() == "UN-RELEASED")
				View::displayMessage(to_string(projects[i].getID()) + "  " + projects[i].getTitle() + "\t\t" + projects[i].getSummary());
		}
		break;
	case 'f':
		projectID = View::askForProjectID();
		for (unsigned int l = 0; l < projects.size(); l++)
		{
			if (projects[l].getID() == atoi(projectID.c_str()))
			{
				vector<int> materialIDs = projects[l].getMaterial();
				for (unsigned int i = 0; i < materialIDs.size(); i++)
				{
					for (unsigned int m = 0; m < materials.size(); m++)
					{
						if (materials[m]->getID() == materialIDs[i])
						{
							materials.erase(materials.begin() + m);
						}
					}
				}
				projects.erase(projects.begin() + l);
				View::displayMessage("PROJECT AND ALL ITS MATERIALS REMOVED");
			}
		}
		saveProjectsMaterialsToFile();
		break;
	case 'g':
		View::displayMessage("ID\t   Film Title\t\t\t\t    Summary\t\t");
		for (unsigned int i = 0; i < projects.size(); i++)
		{
			if (projects[i].getProjectStatus() == "NOW_PLAYING")
				View::displayMessage(to_string(projects[i].getID()) + "  " + projects[i].getTitle() + "\t\t" + projects[i].getSummary());
		}
		break;
	case 'h':
		projectID = View::askForProjectID();
		View::displayMessage("ID\t   Material Type \t\t\t Film Title\t\t\t\t");
		for (unsigned int i = 0; i < projects.size(); i++)
		{
			if (to_string(projects[i].getID()) == projectID)
			{
				vector<int> materialIDs = projects[i].getMaterial();
				for (unsigned int m = 0; m < materialIDs.size(); m++)
				{
					for (unsigned int y = 0; y < materials.size(); y++)
					{
						if (materials[y]->getID() == materialIDs[m])
						{
							View::displayMessage(to_string(materials[y]->getID()) + "\t\t             " + materials[y]->getMaterialType() + "\t\t " + materials[y]->getFilmTitle());
							break;
						}
					}
				}
				break;
			}
		}
		break;	
	case 'd':
		projectID = View::askForProjectID();
		vector<string> propertyDetails = View::getProperty(projectID);
		if (projects.size() >= (unsigned int)atoi(projectID.c_str()))
		{
			if (propertyDetails[0] == "FILM_TITLE") projects[atoi(projectID.c_str())].setTitle(propertyDetails[1]);
			else if (propertyDetails[0] == "SUMMARY") projects[atoi(projectID.c_str())].setSummary(propertyDetails[1]);
			else if (propertyDetails[0] == "GENRE") projects[atoi(projectID.c_str())].setGenre(propertyDetails[1]);
			else if (propertyDetails[0] == "RELEASE_DATE") projects[atoi(projectID.c_str())].setReleaseDate(atoi(propertyDetails[1].c_str()));
			else if (propertyDetails[0] == "LANGAUGE") projects[atoi(projectID.c_str())].setLanguage(propertyDetails[1]);
			else if (propertyDetails[0] == "RUN_TIME") projects[atoi(projectID.c_str())].setRunTime(atoi(propertyDetails[1].c_str()));
			else if (propertyDetails[0] == "TICKET_SALE") projects[atoi(projectID.c_str())].setWeeklyTicketSale(atoi(propertyDetails[1].c_str()));
			else if (propertyDetails[0] == "PROJECT_STATUS") projects[atoi(projectID.c_str())].setProjectStatus(propertyDetails[1]);
		}
		break;

	}
}

void Controller::run()
{
	parseProjectsMaterials();

	View::welcomeScreen();
	char addOrSearchChoice;
	bool endProgram = false;
	char searchOption;
	while (endProgram != true)
	{
		string confirmationText = "";
		addOrSearchChoice = View::addOrSearch();

		switch (addOrSearchChoice)
		{
		case 'a':
		{
			char projectOrMaterial = View::chosenToAdd();
			switch (projectOrMaterial)
			{
			case 'p':
				makeProjectAndCrew();
				saveProjectsMaterialsToFile();
				confirmationText = "Project has been added successfully. Project ID is " + to_string(projects.back().getID());
				View::displayMessage(confirmationText);
				break;
			case 'm':
				askForMaterials();
				saveProjectsMaterialsToFile();
				confirmationText = "Material Successfully added" + materials.back()->getID();
				View::displayMessage(confirmationText);
				break;
			}
			break;
		}
		case 's':
			searchOption = View::chosenToSearch();
			reviewOption(searchOption);
			break;
		case 'c':
			endProgram = true;
			break;
		}
		cout << endl;
		saveProjectsMaterialsToFile();
	}
}

