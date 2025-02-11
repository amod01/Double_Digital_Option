// DoubleDigital.h

#ifndef __PayOffDoubleDigital__
#define __PayOffDoubleDigital__

#include "PayOff.h"

// Class representing parameters for a double digital option
class DoubleDigitalPayOffParameters : public BasePayOffParameters {
public:
    // Constructor: Initializes lower and upper strike prices
    DoubleDigitalPayOffParameters(const double& K_1, const double& K_2);
    virtual ~DoubleDigitalPayOffParameters() {}; // Destructor

    // Getter functions for strike prices
    double GetLowerStrike() const;  // Returns lower strike price
    double GetUpperStrike() const;  // Returns upper strike price

private:
    double K1; // Lower strike price
    double K2; // Upper strike price
};

// Class representing the payoff structure for a double digital option
class PayOffDoubleDigital : public PayOff {
public:
    // Constructor: Initializes payoff structure using given parameters
    PayOffDoubleDigital(const DoubleDigitalPayOffParameters& Param_);
    virtual ~PayOffDoubleDigital() {}; // Destructor

    // Overloaded operator(): Determines payoff based on spot price
    virtual double operator()(const double& S) const override; // Payoff function

private:
    double K1; // Lower strike price
    double K2; // Upper strike price
};

#endif
