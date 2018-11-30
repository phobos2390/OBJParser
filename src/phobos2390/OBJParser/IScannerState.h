#ifndef ISCANNERSTATE_DEF
#define ISCANNERSTATE_DEF

class IScannerState
{
 public:
	 virtual ~IScannerState() = 0;
	 virtual void readNegative() = 0;
	 virtual void readDigit() = 0;
	 virtual void readPeriod() = 0;
	 virtual void readDash() = 0;
	 virtual void readCapitalAlphaChar() = 0;
	 virtual void readAlphaChar() = 0;
	 virtual void readWhiteSpace() = 0;
	 virtual void readOtherSymbol() = 0;
	 virtual void readEndOfFile() = 0;
	 virtual void readNewLine() = 0;
	 virtual void readPoundSign() = 0;
};

#endif