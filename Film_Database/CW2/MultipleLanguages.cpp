#include "MultipleLanguages.h"

void MultipleLanguage::addLanaguage(string lanaguageType)
{
	langages.push_back(lanaguageType);
}

vector<string> MultipleLanguage::getLanguage() const
{
	return langages;
}
