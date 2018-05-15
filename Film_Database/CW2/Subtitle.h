#ifndef SUBTITLES_H
#define SUBTITLES_H

#include <string>
#include <vector>

using namespace std;
class Subtitle
{
public:
	virtual void addSubtitle(string SubtitleLanguage) = 0;
	virtual vector<string> getSubtitle() const = 0;
};

#endif //SUBTITLES_H



