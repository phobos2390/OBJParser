#pragma once

#include <string>
#include "Token.h"
#include <vector>
#include "OBJData.h"
#include "IExpression.h"

using namespace std;

class Parser
{
private:
	vector<Token>::iterator iterator;
	OBJData data;
	IExpression* expression;
public:
	Parser(vector<Token>::iterator);
	~Parser();
	void match(const std::string&);
	void addObject(const ModelObject);
	vector<Token>::iterator getIterator();
	void addMaterialFileName(string fileName);
	void addTextureFileName(string fileName);
	void parse();
	OBJData getData();
	bool currentTokenTypeIs(string test);
	string getCurrentTokenInput();
};
