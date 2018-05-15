#ifndef PACKAGING_H
#define PACKAGING_H

#include "Subtitle.h"

using namespace std;

class Packaging
{
private:
	string typeOfPackaging;
	double width;
	double height;
	double depth;

public:
	Packaging();
	void setPackagingType(string pacakagingType);

	void setHeight(double pacakagingHeight);
	void setDepth(double pacakagingDepth);
	void setWidth(double pacakagingWidth);

	string getTypeOfPackaging() const;

	double getPackagingHeight() const;

	double getPackagingWidth() const;

	double getPackagingDepth() const;
};
#endif
