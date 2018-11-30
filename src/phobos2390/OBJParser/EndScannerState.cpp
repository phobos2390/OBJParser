#include "EndScannerState.h"

EndScannerState::EndScannerState(Scanner*scanner) :scanner(scanner){}

EndScannerState::~EndScannerState(){}

void EndScannerState::readNegative(){}

void EndScannerState::readPeriod(){}

void EndScannerState::readDigit(){}

void EndScannerState::readUnderscore(){}

void EndScannerState::readCapitalAlphaChar(){}

void EndScannerState::readAlphaChar(){}

void EndScannerState::readDash(){}

void EndScannerState::readWhiteSpace(){}

void EndScannerState::readOtherSymbol(){}

void EndScannerState::readEndOfFile(){}

void EndScannerState::readNewLine(){}

void EndScannerState::readPoundSign(){}
