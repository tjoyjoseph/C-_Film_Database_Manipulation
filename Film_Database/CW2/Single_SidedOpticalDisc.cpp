#include "Single_SidedOpticalDisc.h"
#include <sstream>

Single_SidedOpticalDisc::Single_SidedOpticalDisc(string materialType,string single_SidedDetails)
{
	setMaterialType(materialType);
	if (materialType == "SINGLE-SIDED_BLUERAY")
	{
		setBlueRay(true);
	}
	setProperties(single_SidedDetails);
}

void Single_SidedOpticalDisc::setProperties(string details)
{
	
	setAdditionalProperties(details);

}

//void Single_SidedOpticalDisc::addContent(string aContent)
//{
//	map<string, int> contentToAdd;
//
//	stringstream contentsStream(aContent);
//	string content;
//	vector<string> contentDetails;
//	while (getline(contentsStream, content, '/'))
//	{
//		contentDetails.push_back(content);
//	}
//
//	contentToAdd[contentDetails[0]] = atoi(contentDetails[1].c_str());
//	contents.push_back(contentToAdd);
//}
//
//
//vector<string> Single_SidedOpticalDisc::getContents(string side)
//{
//	vector<string> contentNames;
//	for (unsigned int i = 0; i < contents.size(); i++)
//	{
//		map<string, int> tempMap = contents[i];
//		contentNames.push_back(tempMap.begin()->first);
//	}
//	return contentNames;
//
//}

//vector<string> Single_SidedOpticalDisc::getAllProperties()
//{
//	vector<string> allProperties = getMaterialProperties();
//
//
//	allProperties.insert(allProperties.begin(), getMaterialType());
//	vector<string>temp = getContents();
//	for (unsigned int i = 0; i < temp.size(); i++)
//	{
//		allProperties.push_back(temp[i]);
//	}
//
//	return allProperties;
//}