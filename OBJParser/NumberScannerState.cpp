#include "NumberScannerState.h"
#include "Scanner.h"

void NumberScannerState::outputToken()
{
	std::string buffer = this->scanner->getStringFromBuffer();
	scanner->outputToken("NUMBER", buffer, scanner->inputLineNumber());
	scanner->flushBuffer();
}

NumberScannerState::NumberScannerState(Scanner*scanner) :scanner(scanner){}

NumberScannerState::~NumberScannerState(){}

void NumberScannerState::readNegative()
{
	readDigit();
}

void NumberScannerState::readDigit()
{
	this->scanner->passIntoBuffer(this->scanner->getNext());
}

void NumberScannerState::readCapitalAlphaChar()
{
	scanner->setState(scanner->getErrorState());
	scanner->error();
}

void NumberScannerState::readPeriod()
{
	readDigit();
}

void NumberScannerState::readDash()
{
	outputToken();
	this->scanner->setState(this->scanner->getSymbolState());
}

void NumberScannerState::readAlphaChar()
{
	this->scanner->passIntoBuffer(this->scanner->getNext());
}

void NumberScannerState::readWhiteSpace()
{
	outputToken();
	this->scanner->setState(this->scanner->getStandardState());
}

void NumberScannerState::readOtherSymbol()
{
	readCapitalAlphaChar();
}

void NumberScannerState::readEndOfFile()
{
	readWhiteSpace();
}

void NumberScannerState::readNewLine()
{
	readWhiteSpace();
}

void NumberScannerState::readPoundSign()
{
	readWhiteSpace();
}