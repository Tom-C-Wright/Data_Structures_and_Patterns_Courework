#include "CharacterCounter.h"



	CharacterCounter :: CharacterCounter()
	{
		fTotalNumberOfCharacters = 0;
		for (int i = 0; i < 256; i++)
		{
			fCharacterCounts[i] = 0;
		}
	}

	void CharacterCounter :: count(unsigned char aCharacter)
	{
		int cCharacter = 0;
		cCharacter = aCharacter;

			fCharacterCounts[cCharacter]++;
			fTotalNumberOfCharacters++; // Update Total
	}



