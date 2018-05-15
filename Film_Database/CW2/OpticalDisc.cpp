#include "OpticalDisc.h"

OpticalDisc::OpticalDisc()

{
	language = new MultipleLanguage;

	subtitle = new MultipleSubtitles;
	contanerPackaging.setPackagingType("PLASTIC");
}



void OpticalDisc::setBlueRay(bool blueRayis)
{
	isBlueRay = blueRayis;
}

void OpticalDisc::setAdditionalProperties(string details)
{
	stringstream filmStream(details);
	string filmDetail;
	vector<string> filmDetails;
	while (getline(filmStream, filmDetail, ','))
	{
		filmDetails.push_back(filmDetail);
	}

	setID(atoi(filmDetails[0].c_str()));
	//setProjectID(atoi(filmDetails[2].c_str()));
	setFilmTitle(filmDetails[1]);
	setVideoFormat(filmDetails[2]);
	setAudioFormat(filmDetails[3]);
	setRunTime(atoi(filmDetails[4].c_str()));
	setRetailPrice(atoi(filmDetails[5].c_str()));
	setFrameAspects(filmDetails[6]);

	setPackagingType(filmDetails[7]);
	setPackagingHeight(stod(filmDetails[8].c_str()));
	setPackagingDepth(stod(filmDetails[9].c_str()));
	setPackagingWidth(stod(filmDetails[10].c_str()));

	stringstream languageStream(filmDetails[11]);
	string language;
	while (getline(languageStream, language, '-'))
	{
		addALanguage(language);
	}

	stringstream subtitlesStream(filmDetails[12]);
	string subtitle;
	while (getline(subtitlesStream, subtitle, '-'))
	{
		addASubtitle(subtitle);
	}



	for (unsigned int i = 13; i < filmDetails.size(); i++)
	{
		addContent(filmDetails[12]);
	}

}


bool OpticalDisc::getBlueRay()
{
	return isBlueRay;
}
