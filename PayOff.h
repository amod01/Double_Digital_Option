// Header guard to prevent multiple inclusions
#ifndef __PAY_OFF__
#define __PAY_OFF__

#include <algorithm> // This is needed for the std::max comparison function, used in the pay-off calculations

// Abstract base class for PayOff options
class PayOff {
public:
    PayOff(); // Default constructor
    virtual ~PayOff() {}; // Virtual destructor
    virtual double operator()(const double& S) const = 0; // Pure virtual function for PayOff calculation
};

// Base class for PayOff parameters
class BasePayOffParameters {
public:
    BasePayOffParameters(); // Default constructor
    virtual ~BasePayOffParameters() {}; // Virtual destructor
};

// Derived class for PayOff parameters, stores the strike price
class PayOffParameters : public BasePayOffParameters {
public:
    PayOffParameters(const double& K); // Constructor with strike price
    virtual ~PayOffParameters() {}; // Virtual destructor
    double GetStrike() const; // Function to get the strike price
private:
    double K; // Strike price
};

// Class representing the PayOff for a Call option
class PayOffCall : public PayOff {
private:
    double K; // Strike price
public:
    PayOffCall(const PayOffParameters& Param_); // Constructor with PayOffParameters
    virtual ~PayOffCall() {}; // Virtual destructor
    virtual double operator()(const double& S) const; // Call option pay-off function
};

// Class representing the PayOff for a Put option
class PayOffPut : public PayOff {
private:
    double K; // Strike price
public:
    PayOffPut(const PayOffParameters& Param_); // Constructor with PayOffParameters
    virtual ~PayOffPut() {}; // Virtual destructor
    virtual double operator()(const double& S) const; // Put option pay-off function
};

#endif /* defined(__PAY_OFF__) */
