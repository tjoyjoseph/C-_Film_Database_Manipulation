#include "Project.h"
#include <sstream>

Project::Project(string projectDetails)
{
	stringstream projectStream(projectDetails);
	string tempProjectValue;
	vector<string> projectValues;

	
	//int i = 0;
	while (getline(projectStream, tempProjectValue, ','))
		projectValues.push_back(tempProjectValue);

	id = atoi(projectValues[0].c_str());
	title = projectValues[1];
	summary = projectValues[2];
	genre = projectValues[3];
	releaseDate = atoi(projectValues[4].c_str());
	language = projectValues[5];
	runtime = atoi(projectValues[6].c_str());
	projectStatus = projectValues[7];
	weeklyTicketSale = atoi(projectValues[8].c_str());

	stringstream keyWordStream(projectValues[9]);
	string tempKeyWord;
	while (getline(keyWordStream, tempKeyWord, '-'))
		addKeyWords(tempKeyWord);
	
	
	stringstream filmingLocationStream(projectValues[10]);
	string tempLocation;
	while (getline(filmingLocationStream, tempLocation, '-'))
		addFilmingLocations(tempLocation);

	theCrew.setProducer(projectValues[11]);
	theCrew.setDirector(projectValues[12]);
	theCrew.setWriter(projectValues[13]);
	theCrew.setEditor(projectValues[14]);
	theCrew.setProductionDesigner(projectValues[15]);
	theCrew.setSetDecorator(projectValues[16]);
	theCrew.setCostumerDesigner(projectValues[17]);

	stringstream actorsStream(projectValues[18]);
	string tempActor;
	while (getline(actorsStream, tempActor, '-'))
		theCrew.addActors(tempActor);

	if (projectValues.size() == 20)
	{
		stringstream MaterialIDStream(projectValues[19]);
		string tempID;
		while (getline(MaterialIDStream, tempID, '-'))
			addMaterial(atoi(tempID.c_str()));
	}
	
}

vector<string> Project::getProjectDetails()
{
	vector<string> projectDetails;
	projectDetails.push_back(title);
	projectDetails.push_back(summary);
	projectDetails.push_back(genre);
	projectDetails.push_back(to_string(releaseDate));
	//projectDetails.push_back(filmingLocations);
	projectDetails.push_back(language);
	projectDetails.push_back(to_string(runtime));
	//projectDetails.push_back(keyWords);
	projectDetails.push_back(to_string(weeklyTicketSale));
	//projectDetails.push_back(theCrew);
	projectDetails.push_back(projectStatus);


	return projectDetails;
}

void Project::setID(int ID)
{
	this->id = ID;
}

void Project::setTitle(string title)
{
	this->title = title;
}

void Project::setSummary(string summary)
{
	this->summary = summary;
	
}

void Project::setGenre(string genre)
{
	this->genre = genre;
}

void Project::setReleaseDate(int releaseDate)
{
	this->releaseDate = releaseDate;
}

void Project::addFilmingLocations(string filmingLocations)
{
	this->filmingLocations.push_back(filmingLocations);
}

void Project::setLanguage(string language)
{
	this->language = language;
}

void Project::setRunTime(int runTime)
{
	this->runtime = runTime;
}

void Project::addKeyWords(string keyWords)
{
	this->keyWords.push_back(keyWords);
}

void Project::setWeeklyTicketSale(int weeklyTicketSale)
{
	this->weeklyTicketSale = weeklyTicketSale;
}

void Project::setProjectStatus(string status)
{
	this->projectStatus = status;
}

void Project::addMaterial(int materialDetails)
{
	this->materials.push_back(materialDetails);
}

int Project::getID() const
{
	return id;
}

string Project::getTitle() const
{
	return title;
}

string Project::getSummary() const
{
	return summary;
}

string Project::getGenre() const
{
	return genre;
}

int Project::getReleaseDate() const
{
	return releaseDate;
}

vector<string> Project::getFilmingLocations() const
{
	return filmingLocations;
}

string Project::getLanguage() const
{
	return language;
}

int Project::getRunTime() const
{
	return runtime;
}

vector<string> Project::getKeyWords() const
{
	return keyWords;
}

int Project::getWeeklyTicketSale() const
{
	return weeklyTicketSale;
}



string Project::getProjectStatus() const
{
	return projectStatus;
}

vector<int> Project::getMaterial()
{

	return materials;
}

vector<vector<string>> Project::getProjectCrewProperties()
{

	vector<string> projectDetails;
	projectDetails.push_back(to_string(id));
	projectDetails.push_back(title);
	projectDetails.push_back(summary);
	projectDetails.push_back(genre);
	projectDetails.push_back(to_string(releaseDate));
	projectDetails.push_back(language);
	projectDetails.push_back(to_string(runtime));
	projectDetails.push_back(projectStatus);
	projectDetails.push_back(to_string(weeklyTicketSale));

	vector<string> keyWords = getKeyWords();

	vector<string> filmingLocations = getFilmingLocations();

	vector<string> crewDetails;
	crewDetails.push_back(theCrew.getProducer());
	crewDetails.push_back(theCrew.getDirector());
	crewDetails.push_back(theCrew.getWriter());
	crewDetails.push_back(theCrew.getEditor());
	crewDetails.push_back(theCrew.getProductionDesigner());
	crewDetails.push_back(theCrew.getSetDecorator());
	crewDetails.push_back(theCrew.getCostumerDesigner());

	vector<int> materialIDs = getMaterial();
	vector<string> materials;

	for (int i = 0; i < materialIDs.size(); i++)
		materials.push_back(to_string(materialIDs[i]));

	vector<string> castOfActors = theCrew.getActors();

	vector<vector<string>> projectCrew;

	projectCrew.push_back(projectDetails);
	projectCrew.push_back(keyWords);
	projectCrew.push_back(filmingLocations);
	projectCrew.push_back(crewDetails);
	projectCrew.push_back(castOfActors);
	projectCrew.push_back(materials);

	return projectCrew;


}
