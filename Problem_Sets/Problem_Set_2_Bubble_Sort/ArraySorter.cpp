#include <stdexcept>
#include <iostream>
#include "ArraySorter.h"

using namespace std;

// Constructor
ArraySorter::ArraySorter(const int aArrayOfNumbers[], unsigned int aArraySize)
{
	// copy array into sorter
	fArrayOfNumbers = new int[aArraySize];
	for (unsigned int i = 0; i < aArraySize; i++)
	{
		fArrayOfNumbers[i] = aArrayOfNumbers[i];
	}
	fArraySize = aArraySize;
}

// Destructor
ArraySorter::~ArraySorter()
{
	// delete memory associated with array
	delete[] fArrayOfNumbers;
}

// prints out the current state of the array after each step of the sorting
void ArraySorter::stepCompleted(std::ostream &aOStream)
{
	ArraySorter tmp = ArraySorter(fArrayOfNumbers, fArraySize);
	aOStream << "State: [" << tmp << "]" << endl;
}

// Swap the values of two elements in the array
void ArraySorter::swapElements(unsigned int aSourceIndex, unsigned int aTargetIndex)
{
	unsigned int* temp = new unsigned int[1];
	temp[0] = at(aSourceIndex);

	fArrayOfNumbers[aSourceIndex] = at(aTargetIndex);
	fArrayOfNumbers[aTargetIndex] = temp[0];
}

// Throw an error if attempting to access an out of bounds array element
const unsigned int ArraySorter::at(unsigned int aIndex) const
{

	try {
		if (aIndex >= 0 && aIndex < getRange())
			return fArrayOfNumbers[aIndex];
		else
			throw out_of_range("Index is out of range");
	}
	catch (const out_of_range& error) {
		// Tell the user what the error is
		cout << error.what();
	}
}


const unsigned int ArraySorter::getRange() const
{
	return fArraySize;
}


// Sorts an array in order from lowest to highest
void ArraySorter::sort(std::ostream &aOStream)
{
	swapElements(0, 1);
	stepCompleted(aOStream);
}

// Creates a text representation of the numbers being sorted
std::ostream & operator<<(std::ostream & aOStream, const ArraySorter &aObject)
{
	int i;
	
	for (i = 0; i < (int)aObject.fArraySize - 1; i++)
	{
		aOStream << aObject.at(i) << ", ";
	}

	// print the last one out of the loop so the final no. doesnt have a comma"
	aOStream << aObject.at(i);
	
	return aOStream;
}
