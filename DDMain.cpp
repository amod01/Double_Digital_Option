//DDMain.cpp

#include <iostream>
#include <vector>

#include "PayOff.h"
#include "Random.h"
#include "SimpleMC.h"
#include "DoubleDigital.h"

int main() {
    // Define option parameters
    double Expiry = 1.0;      // Time to expiration (in years)
    double Spot = 50.0;       // Current stock price
    double k1 = 43.0;         // Lower strike price for Double Digital option
    double k2 = 57.0;         // Upper strike price for Double Digital option
    double Vol = 0.30;        // Volatility (sigma)
    double r = 0.05;          // Risk-free interest rate
    unsigned long NumberOfPath = 200; // Number of Monte Carlo simulation paths

    // Create parameter object for the double digital option
    DoubleDigitalPayOffParameters PayOffParams(k1, k2);

    // Initialize PayOffDoubleDigital object with defined parameters
    PayOffDoubleDigital PayOff(PayOffParams);

    // Run Monte Carlo simulation to estimate the option price for Double Digital
    double price = SimpleMonteCarlo(PayOff, Spot, Vol, r, Expiry, NumberOfPath);

    // Call Option Parameters
    PayOffParameters callParams(Spot);  // Strike price of 50 for the Call option
    PayOffCall callPayOff(callParams);
    double callResult = SimpleMonteCarlo(callPayOff, Spot, Vol, r, Expiry, NumberOfPath);
    std::cout << "The price of the Call option is: " << callResult << std::endl;

    // Put Option Parameters
    PayOffParameters putParams(Spot);  // Strike price of 50 for the Put option
    PayOffPut putPayOff(putParams);
    double putResult = SimpleMonteCarlo(putPayOff, Spot, Vol, r, Expiry, NumberOfPath);
    std::cout << "The price of the Put option is: " << putResult << std::endl;

    // Output the calculated Double Digital option price
    std::cout << "Double Digital Option Price: " << price << std::endl;

    return 0;
}
