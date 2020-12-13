#include "Polynomial.h"

Polynomial::Polynomial() // initialize
{
	fDegree = 0;
	for (int i = 0; i < MAX_DEGREE; i++)
	{
		cCoeffs[i] = 0;
	}
}

Polynomial Polynomial::operator*(const Polynomial	& aRight) const
{
	Polynomial result;
	result.fDegree = fDegree + aRight.fDegree;
	
	for (int i = 0; i <= fDegree; i++)
	{
		for (int j = 0; j <= aRight.fDegree; j++)
		{
			result.cCoeffs[i + j] += cCoeffs[i] * aRight.cCoeffs[j];
		}
	}

	return result;
}

std::istream& operator>>(std::istream& aIStream, Polynomial& aObject)
{
	int degree;
	cout << "Please specify the degree of the polynomial" << endl;
	cin >> aObject.fDegree;

	cout << "You have specified " << aObject.fDegree << " Coefficents" << endl;

	cout << "Please enter your coefficients one by one" << endl;

	for (int i = 0; i <= aObject.fDegree; i++)
	{
		cin >> aObject.cCoeffs[i];
	}
	return aIStream;
}

std::ostream & operator<<(std::ostream & aOStream, const Polynomial& aObject)
{
	// Go through & print all the values in aObject
	for (int i = 0; i <= aObject.fDegree; i++)
	{
		if (aObject.cCoeffs[i] > 0)
		{
			aOStream << aObject.cCoeffs[i] << "x^" << i;

			if (i != aObject.fDegree)
			{
				aOStream << " + ";
			}
		}
	}

	return aOStream;
}

