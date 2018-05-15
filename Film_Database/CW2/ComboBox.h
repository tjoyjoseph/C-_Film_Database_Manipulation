#ifndef COMVO_BOX_H
#define COMBO_BOX_H

#include "Material.h"
#include "Single_SidedOpticalDisc.h"
#include "Double_SidedOpticalDisc.h"


class ComboBox : public Material
{
	vector<int> dvdID;
	int noOfDiscs = 0;

	void setProperties(string details);

	vector<string> getBasicMaterialProperties();

	void addDVDs(int id);

public:

	ComboBox(string details);

	
	int getNoOfDiscs() const;


	vector<vector<string>> getProperties();

	vector<string> getContents();

};

#endif

