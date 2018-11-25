#pragma once

#include <string>

class Token
{
private:
	bool writable, needsNewType, needsNewString, needsNewlineNumber;
	std::string tokenType;
	std::string input;
	int lineNumber;
public:
	Token();
	bool isWritable();
	bool getNeedsNewType();
	bool getNeedsNewString();
	bool getNeedsNewLineNumber();
	void flush();
	std::string getInput()const;
	void setTokenType(std::string);
	void setInput(std::string);
	void setLineNumber(int);
	std::string output() const;
	bool operator==(const std::string&)const;
};