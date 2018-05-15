#include "FileManager.h"

vector<string> FileManager::loadFile(string nameOfFile)
{
	ifstream file;
	string lineFromFile;
	vector<string> fileLines;
	file.open(nameOfFile);


	string line;
	while (getline(file, line))
	{
		fileLines.push_back(line);
	}
	file.close();
	return fileLines;

}

void FileManager::saveProperties(string fileName, vector<string> properties)
{
	ofstream file;
	file.open(fileName);

	for (unsigned int i = 0; i < properties.size(); i++)
	{
		file << properties[i] << endl;
	}

	file.close();

}
