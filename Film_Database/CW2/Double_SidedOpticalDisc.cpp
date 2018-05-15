#include "Double_SidedOpticalDisc.h"
#include <sstream>




void Double_SidedOpticalDisc::setProperties(string details)
{

	setAdditionalProperties(details);
}

Double_SidedOpticalDisc::Double_SidedOpticalDisc(string type, string double_SidedDetails)
{
	setMaterialType(type);
	if (type == "DOUBLE-SIDED_BLUERAY")
	{
		setBlueRay(true);
	}
	else
	{
		setMaterialType("DOUBLE-SIDED_DVD");
	}
	setProperties(double_SidedDetails);
	
}

void Double_SidedOpticalDisc::addContent(string aContent)
{
	stringstream contentStream(aContent);
	string content;
	getline(contentStream, content, '-');
	string side = content;
	vector<string> contents;
	while (getline(contentStream, content, '-'))
	{
		//contents.push_back(content);


	/*int halfway = (contents.size() / 2);

	for (int i = 0; i < halfway; i++)
	{*/
		/*stringstream contentDetailsStream(content);
		string contentDetails[2];
		getline(contentDetailsStream, contentDetails[0], '/');*/
		//getline(contentDetailsStream, contentDetails[1], '/');

		transform(side.begin(), side.end(), side.begin(), ::toupper);

		if (side == "SIDE A")
		{
			/*map<string, int> contentToAdd;
			contentToAdd[contentDetails[0]] = atoi(contentDetails[1].c_str())*/;
			contentSideA.push_back(content);
		}
		else if (side == "SIDE B")
		{
			/*map<string, int> contentToAdd;
			contentToAdd[contentDetails[0]] = atoi(contentDetails[1].c_str());*/
			contentSideB.push_back(content);
		}
		/*}*/

		/*for (int i = halfway + 1; i < contents.size(); i++)
		{*/
			/*stringstream contentDetailsStream(contents[i]);
			string contentDetails[2];
			getline(contentDetailsStream, contentDetails[0], '/');
			getline(contentDetailsStream, contentDetails[1], '/');

			map<string, int> contentToAdd;
			contentToAdd[contentDetails[0]] = atoi(contentDetails[1].c_str());
			contentSideB.push_back(contentToAdd);*/

		/*}*/
	}
	

}

vector<string> Double_SidedOpticalDisc::getContents(string side)
{
	
	transform(side.begin(), side.end(), side.begin(), ::toupper);
	if (side == "SIDE A")
	{
		
		return contentSideA;
		
	}
	else if (side == "SIDE B")
	{
		return contentSideB;
	}
	else
	{
		vector<string> allContents = contentSideA;

		for (int i = 0; i < contentSideB.size();i++)
			allContents.push_back(contentSideB[i]);

		return allContents;

	}

}

//vector<string> Double_SidedOpticalDisc::getAllProperties()
//{
//	vector<string> allProperties = getMaterialProperties();
//
//	
//	allProperties.insert(allProperties.begin(), getMaterialType());
//	vector<string>temp = getContents("Side A");
//	for (unsigned int i = 0; i < temp.size(); i++)
//	{
//		allProperties.push_back(temp[i]);
//	}
//
//	temp = getContents("Side B");
//	for (unsigned int i = 0; i < temp.size(); i++)
//	{
//		allProperties.push_back(temp[i]);
//	}
//
//	return allProperties;
//}
