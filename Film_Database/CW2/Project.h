#ifndef PROJECT_H
#define PROJECT_H
#include <map>

#include "Material.h"
#include "Crew.h"


class Project
{
	int id;
	string title;
	string summary;
	string genre;
	int releaseDate;
	vector<string> filmingLocations;
	string language;
	int runtime;
	vector<string> keyWords;
	int weeklyTicketSale;
	Crew theCrew;
	string projectStatus;

	vector<int> materials;

public:
	Project(string projectDetails);

	vector<string> getProjectDetails();

	void setID(int ID);
	void setTitle(string title);
	void setSummary(string summary);
	void setGenre(string genre);
	void setReleaseDate(int releaseDate);
	void addFilmingLocations(string filmingLocations);
	void setLanguage(string language);
	void setRunTime(int runTime);
	void addKeyWords(string keyWords);
	void setWeeklyTicketSale(int weeklyTicketSale);
	void setProjectStatus(string status);
	void addMaterial(int materialDetails);

	int getID()const;
	string getTitle()const;
	string getSummary()const;
	string getGenre()const;
	int getReleaseDate()const;
	vector<string> getFilmingLocations()const;
	string getLanguage()const;
	int getRunTime()const;
	vector<string> getKeyWords()const;
	int getWeeklyTicketSale()const;
	string getProjectStatus()const;
	vector<int> getMaterial();

	vector<vector<string>> getProjectCrewProperties();
	
	
		
};








#endif //PROJECT_H