#ifndef DOUBLE_SIDED_DVD_H
#define DOUBLE_SIDED_DVD_H

#include "OpticalDisc.h"
#include <map>
#include <algorithm>



class Double_SidedOpticalDisc :  public virtual OpticalDisc
{
private:
	vector<string> contentSideA;
	vector<string> contentSideB;

	void setProperties(string details);
public:
	Double_SidedOpticalDisc(string type, string single_SidedDetails);

	void addContent(string aContent);
	
	vector<string> getContents(string side = "");



};

#endif //DOUBLE_SIDED_DVD
