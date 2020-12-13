#pragma once
#include "ArraySorter.h"
class BubbleSort : public ArraySorter
{
public:
	BubbleSort(int aArrayOfNumbers[], unsigned int aArraySize);
	void sort(std::ostream& aOStream) override;
};