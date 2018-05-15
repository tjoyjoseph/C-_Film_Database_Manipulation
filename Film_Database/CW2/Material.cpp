#include "Material.h"

//vector<string> Material::getBasicMaterialProperties()
//{
//	vector<string>initialProperties;
//
//	initialProperties.push_back(to_string(getID()));
//	initialProperties.push_back(getFilmTitle());
//	initialProperties.push_back(getVideoFormat());
//	initialProperties.push_back(getAudioFormat());
//	initialProperties.push_back(to_string(getRunTime()));
//	initialProperties.push_back(to_string(getRetailPrice()));
//	initialProperties.push_back(getFrameAspects());
//	initialProperties.push_back(contanerPackaging.getTypeOfPackaging());
//	initialProperties.push_back(to_string(contanerPackaging.getPackagingHeight()));
//	initialProperties.push_back(to_string(contanerPackaging.getPackagingWidth()));
//	initialProperties.push_back(to_string(contanerPackaging.getPackagingDepth()));
//
//	return initialProperties;
//
//}

Material::Material()
{
	identificationNumber = 0;
	filmTitle = "";
	videoFormat = "";
	audioFormat = "";
	runTime = 0;
	retailPrice = 0;
	frameAspects = "";
}

void Material::setID(int id) {
	identificationNumber = id;
}

//void Material::setProjectID(int id)
//{
//	projectID = id;
//}

void Material::setMaterialType(string type)
{
	materialType = type;
}

void Material::setFilmTitle(string title)
{
	filmTitle = title;
}

void Material::setVideoFormat(string videoType)
{
	videoFormat = videoType;
}

void Material::setAudioFormat(string audioType)
{
	audioFormat = audioType;
}

void Material::setRunTime(int runT)
{
	runTime = runT;
}

void Material::setRetailPrice(int retailP)
{
	retailPrice = retailP;
}

void Material::setFrameAspects(string fAspects)
{
	frameAspects = fAspects;
}

void Material::setPackagingType(string type)
{
	contanerPackaging.setPackagingType(type);
}

void Material::setPackagingHeight(double height)
{
	contanerPackaging.setHeight(height);
}

void Material::setPackagingDepth(double depth)
{
	contanerPackaging.setDepth(depth);
}

void Material::setPackagingWidth(double width)
{
	contanerPackaging.setWidth(width);
}

void Material::addALanguage(string languageToAdd)
{
	language->addLanaguage(languageToAdd);
}

void Material::addASubtitle(string subtitleToAdd)
{
	subtitle->addSubtitle(subtitleToAdd);
}

int Material::getID() const
{
	return identificationNumber;
}

//int Material::getProjectID() const
//{
//	return projectID;
//}

string Material::getMaterialType() const
{
	return materialType;
}

string Material::getFilmTitle() const
{
	return filmTitle;
}

string Material::getVideoFormat() const
{
	return videoFormat;
}

string Material::getAudioFormat() const
{
	return audioFormat;
}

int Material::getRunTime() const
{
	return runTime;
}

int Material::getRetailPrice() const
{
	return retailPrice;
}

string Material::getFrameAspects() const
{
	return frameAspects;
}

vector<string> Material::getContents(string side)
{
	return vector<string>();
}

vector<vector<string>> Material::getProperties()
{
	{
		vector<string> materialProperties;
		//materialProperties.push_back(to_string(getID()));
		materialProperties.push_back(getMaterialType() + "\\" + to_string(getID()));
		materialProperties.push_back(getFilmTitle());
		materialProperties.push_back(getVideoFormat());
		materialProperties.push_back(getAudioFormat());
		materialProperties.push_back(to_string(getRunTime()));
		materialProperties.push_back(to_string(getRetailPrice()));
		materialProperties.push_back(getFrameAspects());
		materialProperties.push_back(contanerPackaging.getTypeOfPackaging());
		materialProperties.push_back(to_string(contanerPackaging.getPackagingHeight()));
		materialProperties.push_back(to_string(contanerPackaging.getPackagingWidth()));
		materialProperties.push_back(to_string(contanerPackaging.getPackagingDepth()));

		vector<vector<string>> allMaterialProperties;

		allMaterialProperties.push_back(materialProperties);
		allMaterialProperties.push_back(language->getLanguage());
		allMaterialProperties.push_back(subtitle->getSubtitle());
		allMaterialProperties.push_back(getContents());

		return allMaterialProperties;

	}
}
