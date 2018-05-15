#ifndef MULTIPLE_SUBTITLES_H
#define MULTIPLE_SUBTITLES_H


#include "Subtitle.h"


class MultipleSubtitles : public virtual Subtitle
{
	vector<string> subtitles;
public:

	void addSubtitle(string SubtitleLanguage);

	vector<string> getSubtitle() const;

};

#endif // !MULTIPLE_SUBTITLES_H