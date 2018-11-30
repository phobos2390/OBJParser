#include "ErrorScannerState.h"

ErrorScannerState::ErrorScannerState(Scanner* scanner) :scanner(scanner){}

ErrorScannerState::~ErrorScannerState(){}

void ErrorScannerState::readNegative(){}

void ErrorScannerState::readDigit(){}

void ErrorScannerState::readPeriod(){}

void ErrorScannerState::readDash(){}

void ErrorScannerState::readUnderscore(){}

void ErrorScannerState::readCapitalAlphaChar(){}

void ErrorScannerState::readAlphaChar(){}

void ErrorScannerState::readWhiteSpace(){}

void ErrorScannerState::readOtherSymbol(){}

void ErrorScannerState::readEndOfFile(){}

void ErrorScannerState::readNewLine(){}

void ErrorScannerState::readPoundSign(){}