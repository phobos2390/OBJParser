#pragma once
#include "IExpression.h"
#include "ObjectExpression.h"

class NormalExpression :
	public IExpression
{
private:
	ObjectExpression* expression;
public:
	NormalExpression(ObjectExpression* expression);
	virtual ~NormalExpression();
	void* interpret(void* context);
};

