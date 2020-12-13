#include "ArraySorter.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include <iostream>
using namespace std;

int main()
{
	int lArray[] = { 34, 2, 890, 40, 16, 218, 20, 49, 10, 29 };
	unsigned int lArrayLength = sizeof(lArray) / sizeof(int);
	
	BubbleSort lBubbleSorter(lArray, lArrayLength);

//	cout << "Test bubble sort:" << endl;
//	cout << lBubbleSorter << endl;

//	lBubbleSorter.sort(cout);
	
	InsertionSort lInsertionSorter(lArray, lArrayLength);

	cout << "Test insertion sort:" << endl;
	cout << lInsertionSorter << endl;

	lInsertionSorter.sort(cout);
	

	return 0;
}