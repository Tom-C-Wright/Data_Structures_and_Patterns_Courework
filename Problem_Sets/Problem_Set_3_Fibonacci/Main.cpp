#include <iostream>
#include <cstdlib>
#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"
using namespace std;
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Missing argument!" << endl;
		cerr << "Usage: FibonacciIterator number" << endl;
		return 1;
	}
	cout << "Fibonacci sequence up to " << argv[1] << endl;
	FibonacciSequence lSequence(atoi(argv[1]));

	// C++11 range loop
	unsigned long i = 1;
	for (const unsigned long& n : lSequence)
	{
		cout << i++ << ":\t" << n << endl;
	}

	// Old-style loops
	cout << "Old-style:" << endl;

	FibonacciSequenceIterator lIterator = lSequence.begin();

	unsigned long j = 1;
	for (; lIterator != lIterator.end(); lIterator++)
	{
		cout << j++ << ":\t" << *lIterator << endl;
	}
	cout << "Once more, prints sequence 2..21:" << endl;

		FibonacciSequenceIterator lIterator2 = lIterator.begin();

	unsigned long k = 1;
	do
	{
		cout << ++k << ":\t" << *(++lIterator2) << endl;
	} while (lIterator2 != lIterator2.end());
	return 0;
}