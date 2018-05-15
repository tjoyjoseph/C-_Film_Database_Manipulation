#ifndef VHS_H
#define VHS_H
#include "Medium.h"
#include <map>


class VHS : public Medium
{
	vector<map<string, int>> contents;

	void setProperties(string details);
public:
	VHS(string vhsDetails);

	string getSubtitle();

	string getLanguage();


	vector<vector<string>> getProperties();

	
};

#endif //VHS_H

