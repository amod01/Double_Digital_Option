// DoubleDigital.cpp

#include "DoubleDigital.h"

// Constructor: Initializes lower and upper strike prices
DoubleDigitalPayOffParameters::DoubleDigitalPayOffParameters(const double& K_1, const double& K_2)
    : K1(K_1), K2(K_2) {}

// Getter for lower strike price
double DoubleDigitalPayOffParameters::GetLowerStrike() const {
    return K1;
}

// Getter for upper strike price
double DoubleDigitalPayOffParameters::GetUpperStrike() const {
    return K2;
}

// Constructor: Initializes payoff object with strike boundaries
PayOffDoubleDigital::PayOffDoubleDigital(const DoubleDigitalPayOffParameters& Param_)
    : K1(Param_.GetLowerStrike()), K2(Param_.GetUpperStrike()) {}

// Payoff function: Returns 1 if the spot price is within the strike boundaries, otherwise 0
double PayOffDoubleDigital::operator()(const double& S) const {
    return (S >= K1 && S <= K2) ? 1.0 : 0.0;
}
