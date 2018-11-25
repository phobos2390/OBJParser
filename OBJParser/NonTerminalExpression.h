#pragma once
#include "IExpression.h"
#include <vector>

class NonTerminalExpression:public IExpression
{
private:
	std::vector<IExpression*> subExpressions;
protected:
	std::vector<IExpression*>::iterator getSubExpressionsStart();
	std::vector<IExpression*>::iterator getSubExpressionsEnd();
public:
	NonTerminalExpression();
	NonTerminalExpression(std::vector<IExpression*> subExpressions);
	virtual ~NonTerminalExpression();
	void addSubExpression(IExpression* subExpression);
};

