#ifndef MULTIPLE_LANGUAGES_H
#define MULTIPLE_LANGUAGES_H


#include "Langauge.h"


class MultipleLanguage : public virtual Language
{
	vector<string> langages;
public:	
	void addLanaguage(string lanaguageType);

	vector<string> getLanguage() const;

};

#endif // !MULTIPLE_LANGUAGES_H