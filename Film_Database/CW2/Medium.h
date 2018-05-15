#ifndef MEDIUM_H
#define MEDIUM_H

#include "Material.h"
#include <map>
#include <sstream>

class Medium : public Material
{
private:
	vector<string> contents;

public:
	vector<string> getContents(string side = "");
	

	void addContent(string aContent);
	



};








#endif
