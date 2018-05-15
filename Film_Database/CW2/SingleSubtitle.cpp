#include "SingleSubtitle.h"

void SingleSubtitle::addSubtitle(string SubtitleLanguage)
{
	subtitle = SubtitleLanguage;
}

vector<string> SingleSubtitle::getSubtitle() const
{
	vector<string> tempVector;
	tempVector.push_back(subtitle);
	return tempVector;
}
