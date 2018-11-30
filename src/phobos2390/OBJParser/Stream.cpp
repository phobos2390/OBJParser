#include "Stream.h"

Stream::Stream(istream& inputStream, ostream& outputStream):inputStream(inputStream), outputStream(outputStream),eof(false),lineNumber(1){}
	
char Stream::peek()
{
	return inputStream.peek();
}

char Stream::getNext()
{
	char returnChar = inputStream.get();
	eof = inputStream.eof();
	if('\n' == returnChar)
	{
		lineNumber++;
	}
	return returnChar;
}

void Stream::output(string outputString)
{
	outputStream << outputString;
}

int Stream::getLineNumber()
{
	return lineNumber;
}

bool Stream::endOfFile()
{
	return eof;
}