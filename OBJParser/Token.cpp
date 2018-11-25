#include "Token.h"
#include <sstream>

Token::Token():writable(true),needsNewType(true), needsNewString(true), needsNewlineNumber(true){}

bool Token::isWritable()
{
	return this->writable;
}

bool Token::getNeedsNewType()
{
	return this->needsNewType;
}

bool Token::getNeedsNewString()
{
	return this->needsNewString;
}

bool Token::getNeedsNewLineNumber()
{
	return this->needsNewlineNumber;
}

void Token::flush()
{
	writable = needsNewlineNumber = needsNewString = needsNewType = true;
}

std::string Token::getInput()const
{
	return this->input;
}

void Token::setTokenType(std::string tokenType)
{
	this->tokenType = tokenType;
}

void Token::setInput(std::string input)
{
	this->input = input;
}

void Token::setLineNumber(int lineNumber)
{
	this->lineNumber = lineNumber;
}

std::string Token::output()const
{
	std::stringstream ss;
	ss << "(" << tokenType << ",\"" << input << "\","<< lineNumber << ")";
	return ss.str();
}

bool Token::operator==(const std::string& type)const
{
	return type == this->tokenType;
}