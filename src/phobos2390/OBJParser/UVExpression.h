#pragma once
#include "IExpression.h"
#include "ObjectExpression.h"

class UVExpression :
	public IExpression
{
private:
	ObjectExpression* expression;
public:
	UVExpression(ObjectExpression* expression);
	virtual ~UVExpression();
	void* interpret(void* context);
};

