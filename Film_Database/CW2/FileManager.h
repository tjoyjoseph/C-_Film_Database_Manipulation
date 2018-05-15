#include <fstream>
#include <sstream>
#include <string>
#include<vector>
#include <algorithm>
#include "Material.h"

//using namespace boost;

//#include <boost/archive/text_oarchive.hpp>
//#include <boost/archive/text_iarchive.hpp>


class FileManager
{
private:
	FileManager();

public:
	
	static vector<string> loadFile(string nameOfFile);
	

	static void saveProperties(string fileName, vector<string> properties);
	


};