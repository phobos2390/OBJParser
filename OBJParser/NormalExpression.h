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
	~NormalExpression();
	void* interpret(void* context);
};

