#include "IdentifierScannerState.h"
#include "TokenTypes.h"
#include "Scanner.h"
#include <map>

IdentifierScannerState::IdentifierScannerState(Scanner* scanner) :scanner(scanner)
{
	this->keyWords["v"] = VERTEX;
	this->keyWords["vt"] = TEXTURE_COORD;
	this->keyWords["vn"] = NORMAL;
	this->keyWords["s"] = SMOOTH;
	this->keyWords["o"] = OBJECT;
	this->keyWords["f"] = FACE;
	this->keyWords["usemtl"] = USEMTL;
	this->keyWords["mtllib"] = MTLLIB;
	this->keyWords["usemap"] = USEMAP;
	this->keyWords["maplib"] = MAPLIB;
	this->keyWords["vp"] = PSV;
	this->keyWords["l"] = LINE;
	this->keyWords["off"] = OFF;
	this->keyWords["newmtl"] = NEWMTL;
	this->keyWords["Ns"] = SPECULAR_EXP;
	this->keyWords["Ni"] = REFRACTION;
	this->keyWords["Ka"] = COLOR_AMBIENT;
	this->keyWords["Kd"] = COLOR_DIFFUSE;
	this->keyWords["Ks"] = COLOR_SPECULAR;
	this->keyWords["d"] = TRANSPARENCY;
	this->keyWords["illum"] = ILLUMINATION;
	this->keyWords["g"] = GROUP;
}

IdentifierScannerState::~IdentifierScannerState(){}

void IdentifierScannerState::outputToken()
{
	std::string buffer = scanner->getStringFromBuffer();
	std::map<std::string, std::string>::iterator check = this->keyWords.find(buffer);
	if (check != keyWords.end())
	{
		scanner->outputToken(keyWords[buffer], buffer, scanner->inputLineNumber());
	}
	else
	{
		scanner->outputToken(IDENTIFIER, buffer, scanner->inputLineNumber());
	}
	scanner->flushBuffer();
}

void IdentifierScannerState::readNegative()
{
	readWhiteSpace();
}

void IdentifierScannerState::readDigit()
{
	readAlphaChar();
}

void IdentifierScannerState::readCapitalAlphaChar()
{
	readAlphaChar();
}

void IdentifierScannerState::readAlphaChar()
{
	this->scanner->passIntoBuffer(this->scanner->getNext());
}

void IdentifierScannerState::readUnderscore()
{
	readAlphaChar();
}

void IdentifierScannerState::readPeriod()
{
	readAlphaChar();
}

void IdentifierScannerState::readDash()
{
	readWhiteSpace();
}

void IdentifierScannerState::readWhiteSpace()
{
	this->outputToken();
	scanner->setState(scanner->getStandardState());
}

void IdentifierScannerState::readOtherSymbol()
{
	this->outputToken();
	scanner->setState(scanner->getSymbolState());
}

void IdentifierScannerState::readEndOfFile()
{
	outputToken();
	scanner->setState(scanner->getEndState());
	scanner->end();
}

void IdentifierScannerState::readNewLine()
{
	readWhiteSpace();
}

void IdentifierScannerState::readPoundSign()
{
	this->outputToken();
	scanner->setState(scanner->getCommentState());
}