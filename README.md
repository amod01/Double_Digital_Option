# Double Digital Option Pricing in C++

This repository provides a C++ implementation for pricing **Double Digital Options** and also includes functions for pricing **European Call** and **European Put** options.

## Overview

- **Double Digital Option**: A type of exotic option that pays a fixed amount if the underlying asset price is between two specified barriers at maturity.
- **European Call Option**: A standard financial option that gives the holder the right, but not the obligation, to buy an underlying asset at a specified strike price on the option's expiration date.
- **European Put Option**: A standard financial option that gives the holder the right, but not the obligation, to sell an underlying asset at a specified strike price on the option's expiration date.

## Features

- Pricing for **Double Digital Option** using various models like Black-Scholes or Monte Carlo simulations.
- Functions to calculate the price of **European Call** and **European Put** options based on the Black-Scholes model.

## Prerequisites

- C++ compiler supporting C++11 or later.
- Libraries for numerical operations (such as the standard C++ library or any third-party libraries for randomness or probability functions, if used).

## Usage

### Double Digital Option Pricing

To calculate the price of a Double Digital Option, use the following function:

```cpp
double price_double_digital(double S, double K1, double K2, double T, double r, double sigma);
