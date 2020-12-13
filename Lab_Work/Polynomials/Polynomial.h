#pragma once

#include <iostream>
using namespace std;

 // Max degree for a single polynomial = 10. Multiplying 2 Polynomials requires max degree of 10 + 10 + 1, 0 -20
#define MAX_DEGREE 20+1


class Polynomial
{
private:
	int fDegree; 
	double cCoeffs[MAX_DEGREE]; 

public:
	Polynomial();
	
	Polynomial operator*(const Polynomial& aRight) const;

	// input operator for polynomials
	friend std::istream& operator>>(std::istream& aIStream, Polynomial& aObject);

	// output operator for polynomials
	friend std::ostream& operator<<(std::ostream& aOStream, const Polynomial& aObject);
};
