#include "SymbolScannerState.h"
#include "Scanner.h"
#include "TokenTypes.h"

SymbolScannerState::SymbolScannerState(Scanner*scanner) :scanner(scanner)
{
	recognizedSymbols['/'] = DASH;
}

SymbolScannerState::~SymbolScannerState(){}

void SymbolScannerState::outputToken()
{
	char firstOfString = this->scanner->getStringFromBuffer()[0];
	std::map<char, std::string>::iterator check = this->recognizedSymbols.find(firstOfString);
	if (check != recognizedSymbols.end())
	{
		stringstream ss;
		ss << firstOfString;
		scanner->outputToken(recognizedSymbols[firstOfString], ss.str(), scanner->inputLineNumber());
	}
	else
	{
		scanner->setState(scanner->getErrorState());
		scanner->error();
	}
	scanner->flushBuffer();
}

void SymbolScannerState::readNegative()
{
	readDigit();
}

void SymbolScannerState::readDigit()
{
	scanner->setState(scanner->getNumberState());
}

void SymbolScannerState::readCapitalAlphaChar()
{
	scanner->setState(scanner->getErrorState());
	scanner->error();
}

void SymbolScannerState::readAlphaChar()
{
	readCapitalAlphaChar();
}

void SymbolScannerState::readDash()
{
	scanner->passIntoBuffer(scanner->getNext());
	outputToken();
}

void SymbolScannerState::readUnderscore()
{
	readCapitalAlphaChar();
}

void SymbolScannerState::readPeriod()
{
	scanner->setState(scanner->getNumberState());
}

void SymbolScannerState::readWhiteSpace()
{
	scanner->setState(scanner->getStandardState());
}

void SymbolScannerState::readOtherSymbol()
{
	scanner->setState(scanner->getStandardState());
}

void SymbolScannerState::readEndOfFile()
{
	scanner->setState(scanner->getStandardState());
}

void SymbolScannerState::readNewLine()
{
	scanner->setState(scanner->getStandardState());
}

void SymbolScannerState::readPoundSign()
{
	scanner->setState(scanner->getCommentState());
}