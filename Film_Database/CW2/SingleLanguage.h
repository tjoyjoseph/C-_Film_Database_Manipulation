#ifndef SINGLE_LANGAUGE_H
#define SINGLE_LANGUAGE_H



#include "Langauge.h"


class SingleLanguage :  public virtual Language
{
	string language;
public:
	void addLanaguage(string lanaguageType);

	vector<string> getLanguage() const;

};
#endif // !SINGLE_LANGAUGE_H
