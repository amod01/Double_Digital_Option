# Option Pricing: Double Digital, European Call, and European Put

This repository provides a C++ implementation for pricing **Double Digital Options**, **European Call**, and **European Put** options using **Monte Carlo Simulation**.

## Overview

- **Double Digital Option**: A type of exotic option that pays a fixed amount if the underlying asset price lies between two specified barriers (k1 and k2) at maturity.
- **European Call Option**: A standard financial option that gives the holder the right to buy an underlying asset at a specified strike price on the option's expiration date.
- **European Put Option**: A standard financial option that gives the holder the right to sell an underlying asset at a specified strike price on the option's expiration date.

The pricing is done using **Monte Carlo Simulation**.

## Project Structure

- **DDMain.cpp**: Main program where all option pricing (Double Digital, European Call, and European Put) occurs using Monte Carlo simulations.
- **PayOff.h/cpp**: Defines the payoff structures for the options.
- **Random.h/cpp**: Implements random number generation for simulations.
- **SimpleMC.h/cpp**: Implements the Monte Carlo simulation logic.
- **DoubleDigital.h/cpp**: Contains the logic specific to Double Digital option pricing.

## Features

- Price calculation for **Double Digital Option** using Monte Carlo simulation.
- Price calculation for **European Call Option** using the Black-Scholes formula.
- Price calculation for **European Put Option** using the Black-Scholes formula.

## Prerequisites

- C++ compiler supporting C++11 or later.
- Libraries for numerical operations (such as the standard C++ library or any third-party libraries for randomness or probability functions, if used).

## Usage

### Double Digital Option Pricing

To calculate the price of a **Double Digital Option**, the program runs a Monte Carlo simulation to estimate the price based on the spot price, volatility, risk-free rate, expiry, and barrier levels (k1 and k2).

### European Call and Put Options Pricing

For **European Call** and **European Put Options**, the program also uses Monte Carlo simulations to estimate the option price. The strike price is set, and the payoff functions for both call and put options are defined.

Refer to DDMain.cpp for a demonstration of how to implement this repository.
