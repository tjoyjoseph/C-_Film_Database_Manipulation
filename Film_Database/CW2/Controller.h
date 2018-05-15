#ifndef CONTROLLER_H
#define CONTROLLER_H


#include <fstream>
#include <sstream>
#include "Material.h"
#include "Project.h"
#include "FileManager.h"
#include "View.h"

#include "VHS.h"
#include "Single_SidedOpticalDisc.h"
#include "Double_SidedOpticalDisc.h"
#include "ComboBox.h"

class Controller
{
private:


	static void saveProjectsMaterialsToFile();

	static string serializeProjectCrew(vector<vector<string>> projectCrew);

	static void parseProjectsMaterials();
	
	static string serializeVHS(vector<vector<string>> material);

	static string serializeSingle_Sided(vector<vector<string>> material);

	static string serializeDouble_Sided(vector<vector<string>> material);

	static string serializeComboBox(vector<vector<string>> material);

	static string serialize(vector<string> forSerializing, char key);
	
	static void reviewOption(char option);

	static void makeProjectAndCrew();
	

	static void makeMaterial(string serializedString);
	
	static bool isProjectValid(int projectID);

	static void askForMaterials();

public:
	
	static void run();
	
	

	




};

#endif //CONTROLLER_H