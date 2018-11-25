#include "Parser.h"
#include <iostream>
#include "FaceExpression.h"
#include "ObjectExpression.h"
#include "VertexExpression.h"
#include "UVExpression.h"
#include "LineExpression.h"
#include "NormalExpression.h"

Parser::Parser(vector<Token>::iterator iterator) :iterator(iterator)
{
	ObjectExpression* rootExpression = new ObjectExpression();
	rootExpression->addSubExpression(new VertexExpression(rootExpression));
	rootExpression->addSubExpression(new UVExpression(rootExpression));
	rootExpression->addSubExpression(new NormalExpression(rootExpression));
	rootExpression->addSubExpression(new FaceExpression(rootExpression));
	rootExpression->addSubExpression(new LineExpression(rootExpression));
	this->expression = rootExpression;
}

Parser::~Parser()
{
	delete this->expression;
}

void Parser::match(const string& check)
{
	if ((*iterator) == check)
	{
		++(iterator);
	}
	else
	{
		throw (iterator);
	}
}

void Parser::addObject(const ModelObject object)
{
	this->data.addObject(object);
}

vector<Token>::iterator Parser::getIterator()
{
	return this->iterator;
}

void Parser::addMaterialFileName(string fileName)
{
	this->data.addMaterialFileName(fileName);
}

void Parser::addTextureFileName(string fileName)
{
	this->data.addTextureFileName(fileName);
}

void Parser::parse()
{
	this->expression->interpret(this);
}

OBJData Parser::getData()
{
	return this->data;
}

bool Parser::currentTokenTypeIs(string test)
{
	return (*this->iterator) == test;
}

string Parser::getCurrentTokenInput()
{
	return this->iterator->getInput();
}