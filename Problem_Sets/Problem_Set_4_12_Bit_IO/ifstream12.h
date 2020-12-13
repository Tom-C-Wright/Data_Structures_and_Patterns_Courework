#pragma once
#include <fstream>
class ifstream12
{
private:
	std::ifstream fIStream;
	unsigned char* fBuffer; // input buffer
	unsigned int fBufferSize; // input buffer size
	int fByteIndex; // current byte index
	int fBitIndex; // current bit index
	int fBytesAvailable; // number of bytes available in fBuffer
	void init(); // initialize data members
	void reload(); // fetch data
	int readBit(); // read a Bit, returns 0 of 1, or -1 for EOF
public:
	ifstream12(const char* aFileName = nullptr, unsigned int aBufferSize = 128);
	~ifstream12();
	void open(const char* aFileName);
	void close();
	bool isOpen() const;
	bool good() const;
	bool eof() const; // returns true if stream is eof
	// and no bytes available
	operator bool() const // conversion operator:
	{ // - allows ifstream12 to be used as bool
		return !eof(); // - returns true if ifstream12 is eof
	}
	ifstream12& operator>>(int& a12BitValue);
};