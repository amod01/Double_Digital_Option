#include "PayOff.h"

// Constructor for BasePayOffParameters (empty)
BasePayOffParameters::BasePayOffParameters() {}

// Constructor for PayOffParameters, initializes K (strike price)
PayOffParameters::PayOffParameters(const double& K) : K(K) {}

// Getter for strike price
double PayOffParameters::GetStrike() const {
    return K;
}

// Constructor for PayOff (abstract class)
PayOff::PayOff() {}

// Constructor for PayOffCall, initializes strike price from PayOffParameters
PayOffCall::PayOffCall(const PayOffParameters& Param_) : K(Param_.GetStrike()) {}

// Constructor for PayOffPut, initializes strike price from PayOffParameters
PayOffPut::PayOffPut(const PayOffParameters& Param_) : K(Param_.GetStrike()) {}

// Payoff for Call option: max(Spot - Strike, 0)
double PayOffCall::operator()(const double& S) const {
    return std::max(S - K, 0.0); // Call option payoff is max(Spot - Strike, 0)
}

// Payoff for Put option: max(Strike - Spot, 0)
double PayOffPut::operator()(const double& S) const {
    return std::max(K - S, 0.0); // Put option payoff is max(Strike - Spot, 0)
}
