#include "BubbleSort.h"

BubbleSort::BubbleSort(int aArrayOfNumbers[], unsigned int aArraySize) : ArraySorter(aArrayOfNumbers, aArraySize)
{
	
}

void BubbleSort::sort(std::ostream & aOStream)
{
	int x, y;
	stepCompleted(aOStream);
	for (int i = 0; i < getRange() - 1; i++)
	{
		for (int j = 0; j < (getRange() - i - 1); j++)
		{
			if (at(j) > at(j+1))
			{
			x =	 (int)at(j);
			y = (int)at(j + 1);
				swapElements(j, j + 1);
			}	
		}
		stepCompleted(aOStream);
	}
}
