
// COS30008, Tutorial 2, 2019

#include <iostream>

#include "Polynomial.h"

using namespace std;

int main()
{
    Polynomial A;
    cout << "Specify the degree of the polynomial:" << endl;
    cin >> A;
    cout << "A = " << A << endl;

    double x;
    cout << "Specify value of x: ";
    cin >> x;
   
    cout << "A(x) = " << A( x ) << endl;
    
    cout << "Indefinite integral of A = "
         << A.computeIndefiniteIntegral() << endl;
    
    cout << "Definite integral of A(xlow=0, xhigh=12.0) = "
         << A.calculateDefiniteIntegral( 0, 12.0 ) << endl;
    
    return 0;
}
