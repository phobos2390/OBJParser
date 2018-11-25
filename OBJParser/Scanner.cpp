#include "Scanner.h"
#include "ScannerStates.h"
#include <cstdio>
#include "TokenTypes.h"

Scanner::Scanner(Stream iofstream):iofstream(iofstream),eof(false),invalidError(false),numTokens(0)
{
    this->standardState = new StandardScannerState(this);
	this->errorState = new ErrorScannerState(this);
	this->identifierState = new IdentifierScannerState(this);
	this->numberState = new NumberScannerState(this);
	this->commentState = new CommentScannerState(this);
	this->symbolState = new SymbolScannerState(this);
	this->endState = new EndScannerState(this);
	this->currentState = standardState;
}

Scanner::~Scanner()
{
	delete standardState;
	delete errorState;
	delete identifierState;
	delete numberState;
	delete commentState;
	delete symbolState;
	delete endState;
}

IScannerState* Scanner::getErrorState()
{
	return this->errorState;
}

IScannerState* Scanner::getStandardState()
{
	return this->standardState;
}

IScannerState* Scanner::getIdentifierState()
{
	return this->identifierState;
}

IScannerState* Scanner::getCommentState()
{
	return commentState;
}

IScannerState* Scanner::getSymbolState()
{
	return this->symbolState;
}

IScannerState* Scanner::getEndState()
{
	return this->endState;
}

IScannerState* Scanner::getNumberState()
{
	return this->numberState;
}

void Scanner::passIntoBuffer(char passInCharacter)
{
	buffer << passInCharacter;
}

string Scanner::getStringFromBuffer()
{
	return buffer.str();
}

void Scanner::flushBuffer()
{
	this->buffer.str(std::string());
}

void Scanner::start()
{
	while(currentState != endState && currentState != errorState)
	{
		readNext();
	}
}

void Scanner::end()
{
	outputToken(END_OF_FILE,"",iofstream.getLineNumber());
	//ss << "Total Tokens = " << numTokens;
	//iofstream.output(ss.str());
}

void Scanner::error()
{
	invalidError = true;
	outputToken("ERROR",buffer.str(), iofstream.getLineNumber());
	/*stringstream out;
	out << "Error on line " << iofstream.getLineNumber();
	iofstream.output(out.str());*/
}

void Scanner::setState(IScannerState* value)
{
	if(!invalidError)
	{
		this->currentState = value;
	}
}

void Scanner::readNext()
{
	char character = iofstream.peek();
	if('0' <= character && character <= '9')
	{
		currentState->readDigit();
	}
	else if('A' <= character && character <= 'Z')
	{
		currentState->readCapitalAlphaChar();
	}
	else if('a' <= character && character <= 'z')
	{
		currentState->readAlphaChar();
	}
	else
	{
	    switch(character)
		{
		case '-':
			currentState->readNegative();
			break;
		case '/':
			currentState->readDash();
			break;
		case '.':
			currentState->readPeriod();
			break;
		case ' ':
		case '\t':
			currentState->readWhiteSpace();
			break;
		case'#':
			currentState->readPoundSign();
			break;
		case'\n':
		case'\v':
		case'\r':
		case'\f':
			currentState->readNewLine();
			break;
		case EOF:
			eof = true;
			currentState->readEndOfFile();
			break;
		default:
			currentState->readOtherSymbol();
			break;
		}
	}
}

bool Scanner::endOfFile()
{
	return this->iofstream.endOfFile();
}

char Scanner::getNext()
{
	return iofstream.getNext();
}

char Scanner::peek()
{
	return iofstream.peek();
}

void Scanner::output(string data)
{
	ss << data;
}

int Scanner::inputLineNumber()
{
	return iofstream.getLineNumber();
}

void Scanner::outputToken(std::string type,std::string input,int lineNumber)
{
	currentToken.setTokenType(type);
	currentToken.setInput(input);
	currentToken.setLineNumber(lineNumber);
	allTokens.push_back(currentToken);
	//ss << currentToken.output() << '\n';
	numTokens++;
	currentToken.flush();
}

vector<Token>& Scanner::getTokens()
{
	return allTokens;
}

//End of Scanner functions