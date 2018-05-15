#include "VHS.h"
#include <sstream>

VHS::VHS(string vhsDetails)
{
	language = new SingleLanguage;
	subtitle = new SingleSubtitle;
	contanerPackaging.setPackagingType("CARDBOARD");

	setProperties(vhsDetails);

}

void VHS::setProperties(string details)
{
	setMaterialType("VHS");
	stringstream stream(details);
	string filmDetail;
	vector<string> filmDetails;
	while (getline(stream, filmDetail, ','))
	{
		filmDetails.push_back(filmDetail);
	}

	setID(atoi(filmDetails[0].c_str()));
	//setProjectID(atoi(filmDetails[1].c_str()));
	setFilmTitle(filmDetails[1]);
	setVideoFormat(filmDetails[2]);
	setAudioFormat(filmDetails[3]);
	setRunTime(atoi(filmDetails[4].c_str()));
	setRetailPrice(atoi(filmDetails[5].c_str()));
	setFrameAspects(filmDetails[6]);
	
	setPackagingType(filmDetails[7]);
	setPackagingHeight(stod(filmDetails[8].c_str()));
	setPackagingDepth(stod(filmDetails[9].c_str()));
	setPackagingWidth(stod(filmDetails[10].c_str()));
	
	addALanguage(filmDetails[11]);
	addASubtitle(filmDetails[12]);

	for (unsigned int i = 13; i < filmDetails.size(); i++)
	{
		addContent(filmDetails[i]);
	}

}

string VHS::getSubtitle()
{
	vector<string> tempVector;
	tempVector = subtitle->getSubtitle();
	string tempString = tempVector[0];
	return tempString;
}

string VHS::getLanguage()
{
	vector<string> tempVector;
	tempVector = language->getLanguage();
	string tempString = tempVector[0];
	return tempString;
}

vector<vector<string>> VHS::getProperties()
{
	vector<string> materialProperties;
	//materialProperties.push_back(to_string(getID()));
	materialProperties.push_back(getMaterialType() + "\\" + to_string(getID()));
	materialProperties.push_back(getFilmTitle());
	materialProperties.push_back(getVideoFormat());
	materialProperties.push_back(getAudioFormat());
	materialProperties.push_back(to_string(getRunTime()));
	materialProperties.push_back(to_string(getRetailPrice()));
	materialProperties.push_back(getFrameAspects());
	materialProperties.push_back(contanerPackaging.getTypeOfPackaging());
	materialProperties.push_back(to_string(contanerPackaging.getPackagingHeight()));
	materialProperties.push_back(to_string(contanerPackaging.getPackagingWidth()));
	materialProperties.push_back(to_string(contanerPackaging.getPackagingDepth()));

	vector<string> tempVector = language->getLanguage();
	for (unsigned int i = 0; i < tempVector.size(); i++)
		materialProperties.push_back(tempVector[i]);

	tempVector = subtitle->getSubtitle();
	for (unsigned int i = 0; i < tempVector.size(); i++)
		materialProperties.push_back(tempVector[i]);

	tempVector = getContents();
	for (unsigned int i = 0; i < tempVector.size(); i++)
		materialProperties.push_back(tempVector[i]);


	vector<vector<string>> materialPropertiesALL;
	materialPropertiesALL.push_back(materialProperties);


	return materialPropertiesALL;

}

