#include "IScannerState.h"

class Scanner;

class StandardScannerState :public IScannerState
{
private:
	Scanner* scanner;
public:
	StandardScannerState(Scanner*);
	~StandardScannerState();
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