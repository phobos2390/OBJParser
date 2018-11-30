#include "IScannerState.h"

class Scanner;

class CommentScannerState :public IScannerState
{
private:
	Scanner* scanner;
public:
	CommentScannerState(Scanner*);
	~CommentScannerState();
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
