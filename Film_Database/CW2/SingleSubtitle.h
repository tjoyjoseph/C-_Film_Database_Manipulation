#ifndef SINGLE_SUBTITLES_H
#define SINGLE_SUBTITLES_H

#include "Subtitle.h"

class SingleSubtitle : public virtual  Subtitle
{
	string subtitle;
public:
	
	void addSubtitle(string SubtitleLanguage);

	vector<string> getSubtitle() const;

};

#endif //SINGLE_SUBTITLES_H
