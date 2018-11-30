#include "CommentScannerState.h"
#include "Scanner.h"

CommentScannerState::CommentScannerState(Scanner*scanner) :scanner(scanner){}

CommentScannerState::~CommentScannerState(){}

void CommentScannerState::readNegative()
{
	readDigit();
}

void CommentScannerState::readPeriod()
{
	readDigit();
}

void CommentScannerState::readDigit()
{
	scanner->getNext();
}

void CommentScannerState::readCapitalAlphaChar()
{
	readDigit();
}

void CommentScannerState::readDash()
{
	readDigit();
}

void CommentScannerState::readAlphaChar()
{
	readDigit();
}

void CommentScannerState::readWhiteSpace()
{
	readDigit();
}

void CommentScannerState::readOtherSymbol()
{
	readDigit();
}

void CommentScannerState::readEndOfFile()
{
	readDigit();
}

void CommentScannerState::readNewLine()
{
	scanner->setState(scanner->getStandardState());
}

void CommentScannerState::readPoundSign()
{
	readDigit();
}