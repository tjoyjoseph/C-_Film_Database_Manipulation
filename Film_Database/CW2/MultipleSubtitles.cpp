#include "MultipleSubtitles.h"

void MultipleSubtitles::addSubtitle(string SubtitleLanguage)
{
	subtitles.push_back(SubtitleLanguage);
}

vector<string> MultipleSubtitles::getSubtitle() const
{
	return subtitles;
}
