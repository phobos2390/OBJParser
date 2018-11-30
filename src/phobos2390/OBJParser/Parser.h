#pragma once

#include <string>
#include "Token.h"
#include <vector>
#include <queue>
#include "OBJData.h"
#include "IExpression.h"
//#include <condition_variable>
//#include <mutex>

using namespace std;

class Parser
{
private:
	queue<Token> availableTokens;
	Data::OBJData* data;
	IExpression* expression;
	IExpression* materialExpression;
	//condition_variable tokensInBuff;
	int hundreds;
	int cnt;
	//mutex lock;
public:
	Parser();
	~Parser();
	void addToken(Token toAdd);
	void match(const std::string&);
	void addObject(const Data::ModelObject);
	queue<Token> getBuffer();
	int getBufferSize();
	void addMaterialFileName(string fileName);
	void addMaterial(Material);
	void addTextureFileName(string fileName);
	void parse();
	Data::OBJData* getData();
	bool currentTokenTypeIs(string test);
	string getCurrentTokenInput();
};
