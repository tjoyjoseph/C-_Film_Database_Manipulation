#include "View.h"

string View::getData(string question, string numString)
{
	string returnString;

	bool isCorrectFormat = false;
	while (isCorrectFormat == false)
	{
		int i = 0;
		cout << question;
		cin >> returnString;

		while (returnString[i])
		{
			if (numString == "STRING")
			{

				if (isdigit(returnString[i]))
				{
					isCorrectFormat = false;
					break;
				}
				else
				{
					isCorrectFormat = true;
					i++;
				}

			}
			else if (numString == "NUM")
			{
				if (!(isdigit(returnString[i])))
				{
					isCorrectFormat = false;
					break;
				}
				else
				{
					isCorrectFormat = true;
					i++;
				}

			}

		}
	}

	return returnString;
}

vector<string> View::addProject()
{
	vector<string> projectDetails;

	string filmTitle;
	cout << "Film Title - ";
	cin.get();
	getline(cin, filmTitle);
	projectDetails.push_back(filmTitle);

	string summary;
	cout << "Project Summary - ";
	cin.get();
	getline(cin, summary);
	projectDetails.push_back(summary);

	string genre = getData("Genre <only alphabets> - ", "STRING");
	projectDetails.push_back(genre);
	string date = getData("Release Date <only Numbers> <DDMMYY> - ", "NUM");
	projectDetails.push_back(date);
	string language = getData("Langauge <only alphabets> - ", "STRING");
	projectDetails.push_back(language);
	string runTime = getData("Run Time <only Numbers> - ", "NUM");
	projectDetails.push_back(runTime);

	return projectDetails;
}

vector<string> View::addCrew()
{
	vector<string> crewDetails;
	string producer = getData("Producer Name <only alphabets> - ", "STRING");
	crewDetails.push_back(producer);
	string director = getData("Director Name <only alphabets> - ", "STRING");
	crewDetails.push_back(director);
	string writer = getData("Writer Name <only alphabets> - ", "STRING");
	crewDetails.push_back(writer);
	string editor = getData("Editor Name <only alphabets> - ", "STRING");
	crewDetails.push_back(editor);
	string productionDesigner = getData("Production Designer Name <only alphabets> - ", "STRING");
	crewDetails.push_back(productionDesigner);
	string setDecorator = getData("Set Decorator Name <only alphabets> - ", "STRING");
	crewDetails.push_back(setDecorator);
	string costumerDesigner = getData("Costume Designer Name <only alphabets> - ", "STRING");
	crewDetails.push_back(costumerDesigner);

	return crewDetails;
}

void View::welcomeScreen()
{
	cout << "\t\t         TREK START PRODUCTIONS" << endl;
	cout << "*******************************************************************************" << endl;
	cout << "\t\t            PROJECT DATABASE" << endl;
	cout << "*******************************************************************************\n\n" << endl;
}

char View::addOrSearch()
{
	string choice = "z";

	while (((choice != "a") && (choice != "s") && (choice != "c")) || (choice.length() > 1))
	{
		cout << "Would you like to add data or search for data, in the database?" << endl;
		cout << "<a for add, s for search, c for cancel> - ";
		cin >> choice;
		cout << endl;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	}

	return choice[0];

}

char View::chosenToAdd()
{
	string choice;
	choice = "z";
	while (((choice != "p") && (choice != "m") && (choice != "c")) || (choice.length() > 1))
	{
		cout << "Would you like to add a project, or add material to an existing project?" << endl;
		cout << "<p for project, m for material, c for cancel> - ";
		cin >> choice;
		cout << endl;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	}

	return choice[0];
}

char View::chosenToSearch()
{
	char choice = 'z';

	cout << "Find which projects are currently in the datastore ? <a>" << endl;
	cout << "Find details of a project? <b>" << endl;
	cout << "Find which projects are currently released ?<c>" << endl;
	cout << "Change project details based on ID <d>" << endl;
	cout << "Find which projects are currently un-released ?<e>" << endl;
	cout << "Delete project <f>" << endl;
	cout << "Find which projects are currently playing ?<g>" << endl;
	cout << "Find which materials a project has?<h>" << endl;

	cin >> choice;
	tolower(choice);

	return choice;
};

vector<vector<string>> View::addOpticalDiscProperties(string typeName)
{
	string choice = "z";
	string materialType = typeName, filmTitle, videoFormat, audioFormat, runTime, retailPrice, frameAspects;
	string packagingType = "PLASTIC", packagingHeight, packagingWidth, packagingDepth;
	vector<string> materialProperties, langauges, subtitles;

	materialProperties.push_back(materialType);

	cout << "Film Title - ";
	cin.get();
	getline(cin, filmTitle);
	materialProperties.push_back(filmTitle);

	videoFormat = getData("Video Format <only alphabets> - ", "STRING");
	materialProperties.push_back(videoFormat);

	audioFormat = " ";
	while ((audioFormat != "DOLBY") && (audioFormat != "DOLBY_DIGITAL") && (audioFormat != "MPEG-1") && (audioFormat != "PCM") && (audioFormat != "DTS"))
	{
		cout << "Audio Format <DOLBY, DOLBY_DIGITAL, MPEG-1, PCM or DTS> - ";
		cin >> audioFormat;
		transform(audioFormat.begin(), audioFormat.end(), audioFormat.begin(), ::toupper);
	}
	materialProperties.push_back(audioFormat);


	runTime = getData("Run Time <only Numbers> - ", "NUM");
	materialProperties.push_back(runTime);
	retailPrice = getData("Retail Price <only Numbers> - ", "NUM");
	materialProperties.push_back(retailPrice);

	cout << "Frame Aspects - ";
	cin.get();
	getline(cin, frameAspects);
	materialProperties.push_back(frameAspects);

	materialProperties.push_back(packagingType);
	packagingHeight = getData("Packaging Height <only Numbers> - ", "NUM");
	materialProperties.push_back(packagingHeight);
	packagingWidth = getData("Packaging Width <only Numbers> - ", "NUM");
	materialProperties.push_back(packagingWidth);
	packagingDepth = getData("Packaging Depth <only Numbers> - ", "NUM");
	materialProperties.push_back(packagingDepth);

	cout << endl;

	while ((choice != "y") && (choice != "n"))
	{
		cout << "Would you like to add a Langauge? <y for yes, n for no>";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		if (choice == "y")
		{
			string language = getData("Langauge <only alphabets> - ", "STRING");
			langauges.push_back(language);
			choice = "z";
		}
	}
	if (langauges.size() == 0)
	{
		langauges.push_back(" ");
	}
	cout << endl;

	cout << endl;
	choice = "z";
	while ((choice != "y") && (choice != "n"))
	{
		cout << "Would you like to add a Subtitle? <y for yes, n for no>";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		if (choice == "y")
		{
			string subtitle = getData("Subtitle <only alphabets> - ", "STRING");
			subtitles.push_back(subtitle);
			choice = "z";
		}
	}
	if (subtitles.size() == 0)
	{
		subtitles.push_back(" ");
	}
	cout << endl;

	vector<vector<string>> allMaterialProperties;

	allMaterialProperties.push_back(materialProperties);
	allMaterialProperties.push_back(langauges);
	allMaterialProperties.push_back(subtitles);


	return allMaterialProperties;

}

vector<vector<string>> View::addDoubleSided(string typeName)
{
	vector <string> contentsSideA;
	vector<vector<string>> allMaterialProperties = addOpticalDiscProperties(typeName);

	cout << endl;
	string choice = "z";
	while ((choice != "y") && (choice != "n"))
	{
		cout << "Would you like to add a Content to Side A? <y for yes, n for no>";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		if (choice == "y")
		{
			string word = getData("Content <only alphabets> - ", "STRING");
			contentsSideA.push_back(word);
			choice = "z";
		}
	}
	if (contentsSideA.size() == 0)
	{
		contentsSideA.push_back(" ");
	}
	allMaterialProperties.push_back(contentsSideA);

	vector <string> contentsSideB;
	cout << endl;
	choice = "z";
	while ((choice != "y") && (choice != "n"))
	{
		cout << "Would you like to add a Content to Side B? <y for yes, n for no>";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		if (choice == "y")
		{
			string word = getData("Content <only alphabets> - ", "STRING");
			contentsSideB.push_back(word);
			choice = "z";
		}
	}
	if (contentsSideB.size() == 0)
	{
		contentsSideB.push_back(" ");
	}
	allMaterialProperties.push_back(contentsSideB);
	cout << endl;

	return allMaterialProperties;
}

vector<vector<string>> View::addSingleSided(string typeName)
{
	vector <string> contents;
	vector<vector<string>> allMaterialProperties = addOpticalDiscProperties(typeName);

	cout << endl;
	string choice = "z";
	while ((choice != "y") && (choice != "n"))
	{
		cout << "Would you like to add a Content? <y for yes, n for no>";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		if (choice == "y")
		{
			string word = getData("Content <only alphabets> - ", "STRING");
			contents.push_back(word);
			choice = "z";
		}
	}
	if (contents.size() == 0)
	{
		contents.push_back(" ");
	}
	cout << endl;

	allMaterialProperties.push_back(contents);
	return allMaterialProperties;
}

vector<string> View::getProperty(string projectID)
{
	vector<string> propertyChangeTo;
	string property;
	string changeTo;

	cout << "What property of "+ projectID +" would you like to change?" << endl;
	cout << "<FILM_TITLE, SUMMARY, GENRE, RELEASE_DATE, LANGAUGE, RUN_TIME, TICKET_SALE, PROJECT_STATUS>" << endl;
	property = getData("Property <only alphabets> - ", "STRING");

	transform(property.begin(), property.end(), property.begin(), ::toupper);

	cout << "Property to change to: ";
	cin >> changeTo;
	

	propertyChangeTo.push_back(property);
	propertyChangeTo.push_back(changeTo);

	return propertyChangeTo;


}

vector<string> View::addVHS()
{
	string choice = "z";
	string materialType = "VHS", filmTitle, videoFormat, audioFormat, runTime, retailPrice, frameAspects;
	string packagingType, packagingHeight, packagingWidth, packagingDepth;
	vector<string> materialProperties, contents;
	string langauges, subtitles;
	materialProperties.push_back(materialType);
	cout << "Film Title - ";
	cin.get();
	getline(cin, filmTitle);
	materialProperties.push_back(filmTitle);

	videoFormat = getData("Video Format <only alphabets> - ", "STRING");
	materialProperties.push_back(videoFormat);

	audioFormat = " ";
	while ((audioFormat != "DOLBY") && (audioFormat != "DOLBY_DIGITAL") && (audioFormat != "MPEG-1") && (audioFormat != "PCM") && (audioFormat != "DTS"))
	{
		cout << "Audio Format <DOLBY, DOLBY_DIGITAL, MPEG-1, PCM or DTS> - ";
		cin >> audioFormat;
		transform(audioFormat.begin(), audioFormat.end(), audioFormat.begin(), ::toupper);
	}
	materialProperties.push_back(audioFormat);


	runTime = getData("Run Time <only Numbers> - ", "NUM");
	materialProperties.push_back(runTime);
	retailPrice = getData("Retail Price <only Numbers> - ", "NUM");
	materialProperties.push_back(retailPrice);

	cout << "Frame Aspects - ";
	cin.get();
	getline(cin, frameAspects);
	materialProperties.push_back(frameAspects);

	while ((packagingType != "CARDBAORD") && (packagingType != "PLASTIC"))
	{
		cout << "Packaging Type <CARDBAORD, PLASTIC> - ";
		cin >> packagingType;
		transform(packagingType.begin(), packagingType.end(), packagingType.begin(), ::toupper);
	}
	materialProperties.push_back(packagingType);
	packagingHeight = getData("Packaging Height <only Numbers> - ", "NUM");
	materialProperties.push_back(packagingHeight);
	packagingWidth = getData("Packaging Width <only Numbers> - ", "NUM");
	materialProperties.push_back(packagingWidth);
	packagingDepth = getData("Packaging Depth <only Numbers> - ", "NUM");
	materialProperties.push_back(packagingDepth);

	langauges = getData("Langauge <only Alpahabets> - ", "STRING");
	materialProperties.push_back(langauges);
	subtitles = getData("Subtitles <only Alpahabets> - ", "STRING");
	materialProperties.push_back(subtitles);

	cout << endl;
	choice = "z";
	while ((choice != "y") && (choice != "n"))
	{
		cout << "Would you like to add a Content? <y for yes, n for no>";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		if (choice == "y")
		{
			string word = getData("Content <only alphabets> - ", "STRING");
			materialProperties.push_back(word);
			choice = "z";
		}
	}
	if (contents.size() == 0)
	{
		contents.push_back(" ");
	}
	cout << endl;

	/*vector<vector<string>> allMaterialProperties;

	allMaterialProperties.push_back(materialProperties);*/
	//allMaterialProperties.push_back(contents);

	return materialProperties;

}

vector<string> View::addComboBox(string typeName)
{
	string choice = "z";
	string materialType = typeName, filmTitle, retailPrice;
	string packagingType = "CARDBAORD", packagingHeight, packagingWidth, packagingDepth;
	vector<string> materialProperties;

	materialProperties.push_back(typeName);

	cout << "Film Title - ";
	cin.get();
	getline(cin, filmTitle);
	materialProperties.push_back(filmTitle);

	retailPrice = getData("Retail Price <only Numbers> - ", "NUM");
	materialProperties.push_back(retailPrice);

	materialProperties.push_back(packagingType);
	packagingHeight = getData("Packaging Height <only Numbers> - ", "NUM");
	materialProperties.push_back(packagingHeight);
	packagingWidth = getData("Packaging Width <only Numbers> - ", "NUM");
	materialProperties.push_back(packagingWidth);
	packagingDepth = getData("Packaging Depth <only Numbers> - ", "NUM");
	materialProperties.push_back(packagingDepth);

	return materialProperties;


}

string View::askToAddMaterials()
{
	string choice = "z";
	string materialType = "c";
	cout << "Would you like to add materials to Combo Box? <y for yes, n for no> - ";
	cin >> choice;
	transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
	if (choice == "y")
	{

		while ((materialType != "DOUBLE-SIDED_DVD") && (materialType != "SINGLE-SIDED_DVD") && (materialType != "VHS") && (materialType != "COMBO-BOX"))
		{
			cout << "Material Type <DOUBLE-SIDED_DVD, SINGLE-SIDED_DVD> - ";
			cin >> materialType;
			transform(materialType.begin(), materialType.end(), materialType.begin(), ::toupper);
		}
	}

	return materialType;
}

string View::getMaterialType()
{
	string choice = "z";
	string materialType, filmTitle, videoFormat, audioFormat, runTime, retailPrice, frameAspects;
	string packagingType, packagingHeight, packagingWidth, packagingDepth;
	vector<string> materialProperties, langauges, subtitles, contents;

	materialType = "";
	while ((materialType != "DOUBLE-SIDED_DVD") && (materialType != "DOUBLE-SIDED_BLUERAY") && (materialType != "SINGLE-SIDED_BLUERAY") && (materialType != "SINGLE-SIDED_DVD") && (materialType != "VHS") && (materialType != "COMBO-BOX"))
	{
		cout << "Material Type <DOUBLE-SIDED_DVD, DOUBLE-SIDED_BLUERAY, SINGLE-SIDED_BLUERAY, SINGLE-SIDED_DVD, COMBO-BOX or VHS> - ";
		cin >> materialType;
		transform(materialType.begin(), materialType.end(), materialType.begin(), ::toupper);
	}
	return materialType;



}

vector<vector<string>> View::addAProjectCrew()
{
	string choice = "z";
	cout << "                            CREATE A PROJECT" << endl;
	cout << "*******************************************************************************\n\n" << endl;

	vector<string> projectDetails = addProject();

	string projectStatus = "";
	while ((projectStatus != "RELEASED") && (projectStatus != "NOW_PLAYING") && (projectStatus != "UN-RELEASED"))
	{
		cout << "Project Status <RELEASED, NOW_PLAYING or UN-RELEASED> - ";
		cin >> projectStatus;
		transform(projectStatus.begin(), projectStatus.end(), projectStatus.begin(), ::toupper);
	}
	projectDetails.push_back(projectStatus);

	string ticketSale = "";
	if (projectStatus == "NOW_PLAYING")
		ticketSale = getData("Weekle Ticket Sale <only Numbers> - ", "NUM");
	projectDetails.push_back(ticketSale);


	cout << endl;
	vector<string> keyWords;
	choice = "z";
	while ((choice != "y") && (choice != "n"))
	{
		cout << "Would you like to add a Key Word? <y for yes, n for no>";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		if (choice == "y")
		{
			string word = getData("Key Word <only alphabets> - ", "STRING");
			keyWords.push_back(word);
			choice = "z";
		}
	}
	if (keyWords.size() == 0)
	{
		keyWords.push_back(" ");
	}
	cout << endl;


	cout << endl;
	vector<string> filmingLocations;
	choice = "z";
	while ((choice != "y") && (choice != "n"))
	{
		cout << "Would you like to add a Filming Location? <y for yes, n for no>";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		if (choice == "y")
		{
			string filmingLocation = getData("Filming Locations <only alphabets> - ", "STRING");
			filmingLocations.push_back(filmingLocation);
			choice = "z";
		}
	}
	if (filmingLocations.size() == 0)
	{
		filmingLocations.push_back(" ");
	}
	cout << endl;

	vector<string> crewDetails = addCrew();


	cout << endl;
	vector<string> castOfActors;
	choice = "z";
	while ((choice != "y") && (choice != "n"))
	{
		cout << "Would you like to add an Actor? <y for yes, n for no>";
		cin >> choice;
		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
		if (choice == "y")
		{
			string actor = getData("Actor's name <only alphabets> - ", "STRING");
			castOfActors.push_back(actor);
			choice = "z";
		}
	}
	if (castOfActors.size() == 0)
	{
		castOfActors.push_back(" ");
	}
	cout << endl;

	vector<string> materialIDs;
	materialIDs.push_back("");

	vector<vector<string>> projectCrew;

	projectCrew.push_back(projectDetails);
	projectCrew.push_back(keyWords);
	projectCrew.push_back(filmingLocations);
	projectCrew.push_back(crewDetails);
	projectCrew.push_back(castOfActors);
	projectCrew.push_back(materialIDs);

	return projectCrew;

}

string View::askForProjectID()
{
	string projectID;
	cout << "What is the Project ID ? <c for cancel> - ";
	cin >> projectID;

	return projectID;
}

void View::displayMessage(string displayMessage)
{
	cout << displayMessage << endl;
}
