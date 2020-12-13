#include "FibonacciSequence.h"

FibonacciSequence::FibonacciSequence(unsigned long aLimit)
{
	fPrevious = 0;
	fCurrent = 1;
	fPosition = 1;
	fLimit = aLimit;
}

const unsigned long & FibonacciSequence::current() const
{
	return fCurrent;
}

void FibonacciSequence::advance()
{
	if (fPosition <= fLimit)
	{
		unsigned long fnext;
		fnext = fCurrent + fPrevious;
		fPrevious = fCurrent;
		fCurrent = fnext;
	}
	else
	{
		throw std::out_of_range("Limit exceeded");
	}
}
