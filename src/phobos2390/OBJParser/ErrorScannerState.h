#include "IScannerState.h"

class Scanner;

class ErrorScannerState :public IScannerState
{
private:
	Scanner* scanner;
public:
	ErrorScannerState(Scanner*);
	~ErrorScannerState();
	void readNegative();
	void readDigit();
	void readPeriod();
	void readDash(); 
	void readUnderscore();
	void readCapitalAlphaChar();
	void readAlphaChar();
	void readWhiteSpace();
	void readOtherSymbol();
	void readEndOfFile();
	void readNewLine();
	void readPoundSign();
};