//SimpleMC.h

#ifndef __Option_Class__SimpleMonteCarlo__
#define __Option_Class__SimpleMonteCarlo__

#include <iostream>
#include "DoubleDigital.h"
 
double SimpleMonteCarlo(const PayOff& ThePayOff_,
                        double Spot,
                        double Vol,
                        double r,
                        double Expiry,
                        unsigned long NumberOfPaths);

#endif /* defined(__Option_Class__SimpleMonteCarlo__) */