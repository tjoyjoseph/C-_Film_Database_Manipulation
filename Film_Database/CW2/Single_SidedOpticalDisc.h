#ifndef SINGLE_SIDED_DVD_H
#define SINGLE_SIDED_DVD_H

#include "OpticalDisc.h"
#include <map>

class Single_SidedOpticalDisc : public virtual OpticalDisc
{
	vector<map<string, int>> contents;

	void setProperties(string details);
public:
	Single_SidedOpticalDisc(string materialType, string single_SidedDetails);


};

#endif // !SINGLE_SIDED_DVD_H
