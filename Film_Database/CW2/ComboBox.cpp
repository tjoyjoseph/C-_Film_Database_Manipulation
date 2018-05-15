#include "ComboBox.h"
#include <sstream>


void ComboBox::setProperties(string details)
{
	setMaterialType("COMBO-BOX");
	replace(details.begin(), details.end(), '=', '\\');
	stringstream allSectionsStream(details);
	string section;
	vector<string> sections;
	while (getline(allSectionsStream, section, '?'))
	{
		sections.push_back(section);	
	}
	stringstream ComboBoxStream(sections[0]);
	string ComboBoxDetail;
	vector<string> ComboBoxDetails;
	while (getline(ComboBoxStream, ComboBoxDetail, ','))
	{
		ComboBoxDetails.push_back(ComboBoxDetail);
	}

	setID(atoi(ComboBoxDetails[0].c_str()));
	setFilmTitle(ComboBoxDetails[1]);
	setRetailPrice(atoi(ComboBoxDetails[2].c_str()));
	setPackagingType(ComboBoxDetails[3]);
	setPackagingHeight(stod(ComboBoxDetails[4].c_str()));
	setPackagingDepth(stod(ComboBoxDetails[5].c_str()));
	setPackagingWidth(stod(ComboBoxDetails[6].c_str()));
	

	for (unsigned int i = 1; i < sections.size(); i++)
	{
		stringstream boxSetStream(sections[i]);
		string boxSetDetail;
		string boxSets[2];
		int m = 0;
		while (getline(boxSetStream, boxSetDetail, '-'))
		{
			boxSets[m] = boxSetDetail;
			m++;
		}
		addDVDs(atoi(boxSets[0].c_str()));
		/*if (boxSets[0] == "DOUBLE-SIDED_DVD")
		{
			OpticalDisc* DVD = new Double_SidedOpticalDisc("DOUBLE-SIDED_DVD",boxSets[1]);
			addDVDs(DVD);
		}
		else if (boxSets[0] == "SINGLE-SIDED_DVD")
		{
			OpticalDisc* DVD = new Single_SidedOpticalDisc("SINGLE-SIDED_DVD",boxSets[1]);
			addDVDs(DVD);
		}*/
	}
}

vector<string> ComboBox::getBasicMaterialProperties()
{
	vector<string>initialProperties;

	initialProperties.push_back(getMaterialType() + "\\" + to_string(getID()));
	initialProperties.push_back(getFilmTitle());
	initialProperties.push_back(to_string(getRetailPrice()));
	initialProperties.push_back(contanerPackaging.getTypeOfPackaging());
	initialProperties.push_back(to_string(contanerPackaging.getPackagingHeight()));
	initialProperties.push_back(to_string(contanerPackaging.getPackagingWidth()));
	initialProperties.push_back(to_string(contanerPackaging.getPackagingDepth()));
	

	return initialProperties;
}

ComboBox::ComboBox(string details)
{
	setProperties(details);
}

void ComboBox::addDVDs(int id)
{
	dvdID.push_back(id);
	noOfDiscs++;
}



int ComboBox::getNoOfDiscs() const
{
	return noOfDiscs;
}

vector<vector<string>> ComboBox::getProperties()
{
	vector<vector<string>>allProperties;

	allProperties.push_back(getBasicMaterialProperties());
	
	allProperties.push_back(getContents());
	
	
	return allProperties;

}

vector<string> ComboBox::getContents()
{
	vector<string> alldvdIDs;

	for (int i = 0; i < dvdID.size(); i++)
	{
		alldvdIDs.push_back(to_string(dvdID[i]));
	}
	return alldvdIDs;
}
