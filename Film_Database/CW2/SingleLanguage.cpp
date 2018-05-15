#include "SingleLanguage.h"

void SingleLanguage::addLanaguage(string lanaguageType)
{
	language = lanaguageType;
}

vector<string> SingleLanguage::getLanguage() const
{
	vector<string> tempVector;
	tempVector.push_back(language);
	return tempVector;
}
