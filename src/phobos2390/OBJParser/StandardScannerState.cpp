#include "StandardScannerState.h"
#include "Scanner.h"

StandardScannerState::StandardScannerState(Scanner* scanner) :scanner(scanner){}

StandardScannerState::~StandardScannerState(){}

void StandardScannerState::readNegative()
{
	readDigit();
}

void StandardScannerState::readDigit()
{
	scanner->setState(scanner->getNumberState());
}

void StandardScannerState::readDash()
{
	scanner->setState(scanner->getSymbolState());
}

void StandardScannerState::readCapitalAlphaChar()
{
	scanner->setState(scanner->getIdentifierState());
}

void StandardScannerState::readUnderscore()
{
	readCapitalAlphaChar();
}

void StandardScannerState::readAlphaChar()
{
	scanner->setState(scanner->getIdentifierState());
}

void StandardScannerState::readPeriod()
{
	scanner->setState(scanner->getNumberState());
}

void StandardScannerState::readWhiteSpace()
{
	this->scanner->getNext();
}

void StandardScannerState::readOtherSymbol()
{
	scanner->setState(scanner->getSymbolState());
}

void StandardScannerState::readEndOfFile()
{
	scanner->setState(scanner->getEndState());
	scanner->end();
}

void StandardScannerState::readNewLine()
{
	scanner->getNext();
}

void StandardScannerState::readPoundSign()
{
	scanner->setState(scanner->getCommentState());
}