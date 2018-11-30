#ifndef SCANNER_DEFINED
#define SCANNER_DEFINED
#include "Stream.h"
#include "Parser.h"
#include "IScannerState.h"
#include "Token.h"
#include <vector>
#include <sstream>

class Scanner
{
private:
	bool eof, invalidError;
	std::vector<Token> allTokens;
	int numTokens;
	Stream iofstream;
	Token currentToken;
	stringstream buffer;
	stringstream ss;
	IScannerState* currentState;
	IScannerState* standardState;
	IScannerState* commentState;
	IScannerState* numberState;
	IScannerState* identifierState;
	IScannerState* symbolState;
	IScannerState* errorState;
	IScannerState* endState;
	Parser& parser;
public:
	Scanner(Stream, Parser &);
	~Scanner();
	IScannerState* getStandardState();
	IScannerState* getCommentState();
	IScannerState* getNumberState();
	IScannerState* getIdentifierState();
	IScannerState* getSymbolState();
	IScannerState* getErrorState();
	IScannerState* getEndState();
	void passIntoBuffer(char);
	string getStringFromBuffer();
	void flushBuffer();
	void start();
	void end();
	void error();
	void setState(IScannerState*);
	void readNext();
	bool endOfFile();
	char getNext();
	char peek();
	void output(string);
	int inputLineNumber();
	void outputToken(std::string type,std::string input,int lineNumber);
	vector<Token>::iterator getTokensBegin();
	vector<Token>::iterator getTokensEnd();
};
#endif