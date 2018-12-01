#pragma once
#include "IExpression.h"
#include "ObjectExpression.h"

class LineExpression :
	public IExpression
{
private:
	ObjectExpression* expression;
public:
	LineExpression(ObjectExpression* expression);
	virtual ~LineExpression();
	void* interpret(void* context);
};

