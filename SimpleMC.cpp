// SimpleMC.cpp

#include <cmath>
#include "SimpleMC.h"
#include "Random.h"

double SimpleMonteCarlo(const PayOff& ThePayOff, double Spot, double Vol, double r, double Expiry, unsigned long NumberOfPaths)
{
    // Calculate the variance of the asset price over the expiry period
    double variance = Vol * Vol * Expiry;
    
    // Calculate the square root of the variance for later use
    double rootVariance = sqrt(variance);
    
    // Adjust the spot price for the drift (r - 0.5 * variance) over the expiry period
    double movedSpot = Spot * exp((r - 0.5 * variance) * Expiry);
    
    // Variable to accumulate the sum of all payoffs
    double sum = 0.0;
    
    // Loop over the number of paths (simulations)
    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        // Generate a random number from a Gaussian distribution using the Box-Muller method
        double gaussian = GetOneGaussianByBoxMuller();
        
        // Simulate the final spot price by applying the random Gaussian to the adjusted spot price
        double thisSpot = movedSpot * exp(rootVariance * gaussian);
        
        // Calculate the payoff for this simulated spot price
        double thisPayOff = ThePayOff(thisSpot);
        
        // Add the payoff to the total sum
        sum += thisPayOff;
    }
    
    // Discount the average payoff by the risk-free rate and return the result
    return exp(-r * Expiry) * (sum / NumberOfPaths);
}
