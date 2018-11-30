#include "NonTerminalExpression.h"
#include <algorithm>

NonTerminalExpression::NonTerminalExpression(){}

NonTerminalExpression::NonTerminalExpression(std::vector<IExpression*> subExpressions) :subExpressions(subExpressions){}

NonTerminalExpression::~NonTerminalExpression()
{
	for (std::vector<IExpression*>::iterator i = subExpressions.begin(); i != subExpressions.end(); ++i)
	{
		delete (*i);
	}
}

void NonTerminalExpression::addSubExpression(IExpression* subExpression)
{
	subExpressions.push_back(subExpression);
}

std::vector<IExpression*>::iterator NonTerminalExpression::getSubExpressionsStart()
{
	return this->subExpressions.begin();
}

std::vector<IExpression*>::iterator NonTerminalExpression::getSubExpressionsEnd()
{
	return this->subExpressions.end();
}