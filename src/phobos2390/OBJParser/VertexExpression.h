#pragma once
#include "IExpression.h"
#include "ObjectExpression.h"

class VertexExpression :
	public IExpression
{
private:
	ObjectExpression* expression;
public:
	VertexExpression(ObjectExpression* expression);
	virtual ~VertexExpression();
	void* interpret(void* context);
};

