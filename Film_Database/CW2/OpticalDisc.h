#ifndef OpticalDisc_H
#define OpticalDisc_H

#include <sstream>

#include "Medium.h"

class OpticalDisc : public Medium
{
	bool isBlueRay = false;
protected:
	virtual void setProperties(string details) = 0;

	void setBlueRay(bool blueRayis);


	void setAdditionalProperties(string details);
	
	
public:
	OpticalDisc();

	
	bool getBlueRay();
	
	

	
	
};

#endif //OpticalDisc
