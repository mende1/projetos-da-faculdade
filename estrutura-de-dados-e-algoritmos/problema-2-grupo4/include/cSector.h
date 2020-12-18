#pragma once

#include "cPoint.h"
#include "cQuad.h"

typedef enum 	{	INTERN,
					EXTERN,
					CROSS,
					NONE
				} eSectorClass;

class cSector {

	cQuad			sector;
	eSectorClass	sectorClass;

public:

	cSector();
	cSector(cQuad qd);

	void classifySector(float (*f)(cPoint p));

	cQuad	getSector();

};
