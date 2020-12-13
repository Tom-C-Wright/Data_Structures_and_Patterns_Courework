#include "Polynomial.h"
#include <cmath>

// Thomas Wright 101470604 
// Problem set 1
// Takes an existing set of constants in a polynomial & calculates it with a given aX variable
double Polynomial:: operator()(double aX) const
{
	double result = 0;

	// Polynomial = a * x ^ n
	// order of operations dictates we calculate x ^ n first, looks like : a * (x ^ n)
	for (int i = 0; i <= fDegree; i++)
	{
		result += fCoeffs[i] * pow(aX, i);
	}

	return result;
}


// compute indefinite integral
// the indefinite integral is a fresh polynomial with degree fDegree+1 
// the method does not change the current object


Polynomial Polynomial :: computeIndefiniteIntegral() const
{
	Polynomial result;

	result.fDegree = fDegree + 1;

	for (int i = result.fDegree; i > 0; i--)
	{
		result.fCoeffs[i] = (fCoeffs[i - 1]) / i;
	}

	return result;
}


// calculate definite integral
// the method does not change the current object
// the method computes the indefinite integral and then calculates it // for xlow and xhigh and returns the difference

double Polynomial::calculateDefiniteIntegral(double aXLow, double aXHigh) const
{
	double low, high;
	Polynomial polynomial;

	polynomial = computeIndefiniteIntegral();

	low = polynomial(aXLow);
	high = polynomial(aXHigh);

	return high - low;
}