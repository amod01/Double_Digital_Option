// Random.cpp

#include "Random.h"
#include <cstdlib>
#include <cmath>

#if !defined(_MSC_VER)
using namespace std;
#endif

// Generate a Gaussian random variable using the summation method
double GetOneGaussianBySummation()
{
    double result = 0;
    
    for(unsigned long j = 0; j < 12; j++)
        result += rand() / static_cast<double>(RAND_MAX);
    
    result -= 6.0;
    
    return result;
}

// Generate a Gaussian random variable using the Box-Muller transform
double GetOneGaussianByBoxMuller()
{
    double result;
    double x, y;
    double sizeSquared;
    
    do
    {
        // Generate two independent random variables in the range [-1, 1]
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        sizeSquared = x * x + y * y;
    }
    while (sizeSquared >= 1.0);
    
    // Box-Muller transform: generate a Gaussian random variable
    result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);
    
    return result;
}
