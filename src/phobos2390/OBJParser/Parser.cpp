#include "Parser.h"
#include <iostream>
#include <fstream>
#include "FaceExpression.h"
#include "ObjectExpression.h"
#include "VertexExpression.h"
#include "UVExpression.h"
#include "LineExpression.h"
#include "NormalExpression.h"
#include "MaterialExpression.h"
#include "Scanner.h"
#include "Stream.h"

Parser::Parser():hundreds(0),cnt(0)
{
	ObjectExpression* rootExpression = new ObjectExpression();
	rootExpression->addSubExpression(new VertexExpression(rootExpression));
	rootExpression->addSubExpression(new UVExpression(rootExpression));
	rootExpression->addSubExpression(new NormalExpression(rootExpression));
	rootExpression->addSubExpression(new FaceExpression(rootExpression));
	rootExpression->addSubExpression(new LineExpression(rootExpression));
	this->expression = rootExpression;
	this->materialExpression = new MaterialExpression();
	this->data = new OBJData();
}

Parser::~Parser()
{
	delete this->expression;
	delete this->materialExpression;
        delete this->data;
}

void Parser::addToken(Token toAdd)
{
	//unique_lock<mutex> locker(this->lock);
	this->availableTokens.push(toAdd);
	//locker.unlock();
	//this->tokensInBuff.notify_all();
}

void Parser::match(const string& check)
{
	//unique_lock<mutex> locker(this->lock);
	//this->tokensInBuff.wait(locker, [this](){return this->getBufferSize() > 0;});
	if (this->availableTokens.front() == check)
	{
		this->availableTokens.pop();
	}
	else
	{
		throw (this->availableTokens.front());
	}
}

void Parser::addObject(const ModelObject object)
{
	this->data->addObject(object);
}

queue<Token> Parser::getBuffer()
{
	return this->availableTokens;
}

int Parser::getBufferSize()
{
	return this->availableTokens.size();
}

void Parser::addMaterialFileName(string fileName)
{
	this->data->addMaterialFileName(fileName);
}

void Parser::addTextureFileName(string fileName)
{
	this->data->addTextureFileName(fileName);
}

void Parser::parse()
{
	this->expression->interpret(this);
	for (vector<string>::iterator m = this->data->getMaterialFileNamesBegin(); m != this->data->getMaterialFileNamesEnd(); ++m)
	{
                /*/
		ifstream ifile;
		ifile.open(*m);
		ofstream ofile;
		ofile.open(*m + ".out");
		cout << "Parsing file: " << *m << "\n";
		Stream stream(ifile, ofile);
		Scanner scanner(stream,*this);
		//thread scan = thread(&Scanner::start, &scanner);
		scan.join();
		this->materialExpression->interpret(this);
		ifile.close();
		ofile.close();
                //*/
	}
}

void Parser::addMaterial(Material mtl)
{
	this->data->addMaterial(mtl);
}

OBJData* Parser::getData()
{
	return this->data;
}

bool Parser::currentTokenTypeIs(string test)
{
	//unique_lock<mutex> locker(this->lock);
	//this->tokensInBuff.wait(locker, [this]() {return this->getBufferSize() > 0;});
	return this->availableTokens.front() == test;
}

string Parser::getCurrentTokenInput()
{
	//unique_lock<mutex> locker(this->lock);
	//this->tokensInBuff.wait(locker, [this]() {return this->getBufferSize() > 0;});
	return this->availableTokens.front().getInput();
}
