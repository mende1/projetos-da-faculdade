#include "cSector.h"


/// ***********************************************************************
/// ** 
/// ***********************************************************************
cSector::cSector() {

	sector 		= cQuad();
	sectorClass = NONE;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
cSector::cSector(cQuad qd) {

	sector 		= cQuad(qd);
	sectorClass = NONE;
}

/// ***********************************************************************
/// ** 
/// ***********************************************************************
cQuad cSector::getSector() {

	return sector;
}



/// ***********************************************************************
/// ** 
/// ***********************************************************************
void cSector::classifySector(float (*implicitFunc)(cPoint p)) {

float f[4];
cPoint P[4];

	P[0] = sector.getMinPoint(); 
	P[1] = sector.getMaxPoint(); 
	P[2] = cPoint( sector.getMinPoint().getX(), sector.getMaxPoint().getY() ); 
	P[3] = cPoint( sector.getMaxPoint().getX(), sector.getMinPoint().getY() ); 

	for (int i = 0 ; i < 4 ; i++) 		
		f[i] = (*implicitFunc)(P[i]);
	
	if ( (f[0] > 0) && (f[1] > 0) && (f[2] > 0) && (f[3] > 0) )
		sectorClass = EXTERN;
	else
		if ( (f[0] < 0) && (f[1] < 0) && (f[2] < 0) && (f[3] < 0) )
			sectorClass = INTERN;
		else
			sectorClass = CROSS;
}
