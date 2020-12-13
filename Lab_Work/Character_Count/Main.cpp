// Character_Count.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "CharacterCounter.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& aOStream, const CharacterCounter& aCharacterCounter)
{
	aOStream << "Character counts for " << aCharacterCounter.fTotalNumberOfCharacters << " characters:" << endl;

	for (int i = 0; i < 256; i++)
	{
		
			aOStream << (char)i << " : " << aCharacterCounter.fCharacterCounts[i] << endl;
	}

	aOStream << "test";
	return aOStream;
}
// BBBB XX - Some sybomls do not display correctly, however the character count functions correctly as 
// it will display exactly 5 capital B's and 3 capital X's from this comment
int main()
{
	CharacterCounter lCounter;
	unsigned char lChar;
	while (cin >> lChar)
	{
		lCounter.count(lChar);
	}
	
	cout << lCounter;
	
	return 0;
};

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
