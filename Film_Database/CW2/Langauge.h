#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <string>
#include <vector>

using namespace std;

class Language
{
public:
	virtual void addLanaguage(string lanaguageType) = 0;

	//virtual string getLanguage() = 0;

	virtual vector<string> getLanguage() const = 0;
};
#endif 





