#ifndef MATERIAL_H
#define MATERIAL_H


#include <string>
//#include "OpticalDisc.h"
#include "MultipleLanguages.h"
#include "SingleLanguage.h"
#include "MultipleSubtitles.h"
#include "SingleSubtitle.h"
#include "Packaging.h"

using namespace std;

class Material
{
private:
	
	int identificationNumber;
	//int projectID;
	string materialType;
	string filmTitle;
	string videoFormat;
	string audioFormat;
	int runTime;
	string frameAspects;
	int retailPrice;

protected:
	Language *language;
	Subtitle *subtitle;
	Packaging contanerPackaging;


public:
	Material();
	void setID(int id);
	//void setProjectID(int id);	
	void setMaterialType(string type);
	void setFilmTitle(string title);
	void setVideoFormat(string videoType);
	void setAudioFormat(string audioType);
	void setRunTime(int runT);
	void setRetailPrice(int retailP);
	void setFrameAspects(string fAspects);
	void setPackagingType(string type);
	void setPackagingHeight(double height);
	void setPackagingDepth(double depth);
	void setPackagingWidth(double width);
	void addALanguage(string languageToAdd);
	void addASubtitle(string subtitleToAdd);
	virtual void addContent(string aContent){};


	int getID() const;
	//int getProjectID()const;
	string getMaterialType() const;
	string getFilmTitle() const;
	string getVideoFormat() const;
	string getAudioFormat() const;
	int getRunTime() const;
	int getRetailPrice() const;
	string getFrameAspects() const;
	//virtual vector<string> getAllProperties() = 0;
	virtual vector<string> getContents(string side = "");
	
	virtual vector<vector<string>> getProperties();
	

};

#endif // !MATERIAL_H






