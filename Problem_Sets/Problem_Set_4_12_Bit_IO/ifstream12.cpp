#include "ifstream12.h"


void ifstream12::init()
{
	for (unsigned int i = 0; i < fBufferSize; i++)
	{
		fBuffer[i] = 0;
	}

	fByteIndex = 0;
	fBitIndex = 7;
	fBytesAvailable = 0;
}

void ifstream12::reload()
{
	init();

	fIStream.read((char*)fBuffer,fBufferSize);

	fBytesAvailable = fIStream.gcount();
}

int ifstream12::readBit()
{
	if (eof())
		return -1;

	if (fBytesAvailable == 0)
		reload();




	unsigned int nextBit = (fBuffer[fByteIndex] & (1 << fBitIndex)) != 0;

	fBitIndex--;

	if (fBitIndex < 0)
	{
		fByteIndex++;
		fBytesAvailable--;
		fBitIndex = 7;
	}

	return nextBit;
}

ifstream12::ifstream12(const char * aFileName, unsigned int aBufferSize)
{
	fBufferSize = aBufferSize;
	fBuffer = new unsigned char[fBufferSize];

	init(); // Initialize the variables

	open(aFileName); // Open the File

	
}

ifstream12::~ifstream12()
{
	close();
	delete [] fBuffer;
}

void ifstream12::open(const char * aFileName)
{
	if (aFileName)
		fIStream.open(aFileName, std::ifstream::binary);
}

void ifstream12::close()
{
	fIStream.close();
}

bool ifstream12::isOpen() const
{
	return fIStream.is_open();
}

bool ifstream12::good() const
{
	return fIStream.good();
}

bool ifstream12::eof() const
{
	return (fBytesAvailable == 0 && fIStream.eof());
}

ifstream12 & ifstream12::operator>>(int & a12BitValue)
{
	a12BitValue = 0;

	for (int i = 1; i <= 12; i++)	// read 12 Bits
	{
		int nextBit = readBit();

		if (nextBit == 1)	    // The current lowest bit is set.
		{
			a12BitValue = (1 << (i - 1)) + a12BitValue;
		}
		else if (nextBit == -1)
		{
			break;
		}
		
	}

	return *this;
}
