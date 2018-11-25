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
	~UVExpression();
	void* interpret(void* context);
};

