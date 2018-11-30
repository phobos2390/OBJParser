#ifndef IDENTIFIER_SCANNER_STATE_DEFINED
#define IDENTIFIER_SCANNER_STATE_DEFINED
#include "IScannerState.h"
#include <map>
#include <string>

class Scanner;

class IdentifierScannerState :public IScannerState
{
private:
	Scanner* scanner;
	std::map<std::string, std::string> keyWords;
	void outputToken();
public:
	IdentifierScannerState(Scanner*);
	~IdentifierScannerState();
	void readNegative();
	void readDigit();
	void readPeriod();
	void readDash();
	void readCapitalAlphaChar();
	void readAlphaChar();
	void readWhiteSpace();
	void readOtherSymbol();
	void readEndOfFile();
	void readNewLine();
	void readPoundSign();
};

#endif