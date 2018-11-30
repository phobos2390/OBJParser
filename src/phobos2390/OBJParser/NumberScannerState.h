#include "IScannerState.h"

class Scanner;

class NumberScannerState :public IScannerState
{
private:
	Scanner* scanner;
	void outputToken();
public:
	NumberScannerState(Scanner*);
	~NumberScannerState();
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
