#include "IdentifierScannerState.h"
#include <map>
#include <string>

class Scanner;

class SymbolScannerState :public IScannerState
{
private:
	Scanner* scanner;
	std::map<char, std::string> recognizedSymbols;
	void outputToken();
public:
	SymbolScannerState(Scanner*);
	~SymbolScannerState();
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