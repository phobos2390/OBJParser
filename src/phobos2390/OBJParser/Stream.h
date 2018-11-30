#ifndef STREAM_DEFINED
#define STREAM_DEFINED

#include <iostream>
#include <string>
#include "OBJParser.h"

using namespace std;

class Stream
{
private:
	bool eof;
	istream& inputStream; 
	ostream& outputStream;
	int lineNumber;
public:
	Stream(istream& inputStream, ostream& outputStream);
	char peek();
	char getNext();
	void output(string);
	int getLineNumber();
	bool endOfFile();
};
#endif