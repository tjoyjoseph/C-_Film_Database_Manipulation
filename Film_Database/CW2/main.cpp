
#include "Controller.h"
//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost\serialization/binary_object.hpp>
#include "VHS.h"



int main()
{
	/*View view("VHS.csv");
	view.displayProperties();
	view.saveMaterialToFile();
	cout << endl;
	View view2("SingleDVD.csv");
	view2.displayProperties();
	view2.saveMaterialToFile();
	cout << endl;

	View view4("DoubleBlueRay.csv");
	view4.displayProperties();
	view4.saveMaterialToFile();
	cout << endl;
	View view3("DoubleDVD.csv");
	view3.displayProperties();
	view3.saveMaterialToFile();
	cout << endl;
	
	View view5("ComboBox.csv");
	view5.displayProperties();
	view5.saveMaterialToFile();*/

	Controller::run();


	/*ifstream file;
	string lineFromFile;
	vector<string> fileLines;
	file.open("VHS.csv");
	string line;
	getline(file, line);
	file.close();

	stringstream materialStream(line);
	vector<string> materialDetails;

	materialDetails.push_back("");
	int i = 0;
	while (getline(materialStream, materialDetails[i], '\\'))
	{
		materialDetails.push_back("");
		i++;
	}

	ofstream ofs("filename.txt");

	VHS v(materialDetails[1]);

	boost::archive::text_oarchive oa(ofs);

	oa << (v);*/

}