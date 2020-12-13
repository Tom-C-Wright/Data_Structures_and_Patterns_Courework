#include "InsertionSort.h"


InsertionSort::InsertionSort(int aArrayOfNumbers[], unsigned int aArraySize) : ArraySorter(aArrayOfNumbers, aArraySize)
{
}

void InsertionSort::sort(std::ostream & aOStream)
{
	stepCompleted(aOStream);

	for (int i = 1; i < getRange(); i++)
	{
		int current = at(i);

		while (at(i - 1) > current) {
			swapElements(i, i - 1);
				}
		
		// print out current progress
		stepCompleted(aOStream);
	}
}
