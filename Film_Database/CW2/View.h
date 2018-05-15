#ifndef VIEW_H
#define VIEW_H

#include "Controller.h"
#include <iostream>
#include <istream>

class View
{
private:


	static string getData(string question, string numString);
	
	
	static vector<string> addProject();
	

	static vector<string> addCrew();
	

public:


	static void welcomeScreen();
	

	static char addOrSearch();
	

	static char chosenToAdd();
	

	static char chosenToSearch();

	static vector<vector<string>> addOpticalDiscProperties(string typeName);
	

	static vector<vector<string>> addDoubleSided(string typeName);
	

	static vector<vector<string>> addSingleSided(string typeName);
	
	static vector<string> getProperty(string projectID);

	static vector<string> addVHS();
	

	static vector<string> addComboBox(string typeName);
	

	static string askToAddMaterials();
	

	static string getMaterialType();
	

	static vector<vector<string>> addAProjectCrew();
	

	static string askForProjectID();
	

	static void displayMessage(string displayMessage);
	
};

#endif //VIEW_H



