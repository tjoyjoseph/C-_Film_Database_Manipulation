#include "Packaging.h"

Packaging::Packaging()
{
	typeOfPackaging = "";
	height = 0;
	depth = 0;
	width = 0;

}

void Packaging::setPackagingType(string pacakagingType)
{
	typeOfPackaging = pacakagingType;
}

void Packaging::setHeight(double packagingHeight)
{
	height = packagingHeight;
}

void Packaging::setDepth(double packagingDepth)
{
	depth = packagingDepth;
}

void Packaging::setWidth(double packagingWidth)
{
	width = packagingWidth;
}

string Packaging::getTypeOfPackaging() const
{
	return typeOfPackaging;
}

double Packaging::getPackagingHeight() const
{
	return height;
}

double Packaging::getPackagingWidth() const
{
	return width;
}

double Packaging::getPackagingDepth() const
{
	return depth;
}
