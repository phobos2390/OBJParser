#include "IScannerState.h"

class Scanner;

class EndScannerState :public IScannerState
{
private:
	Scanner* scanner;
public:
	EndScannerState(Scanner*);
	~EndScannerState();
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