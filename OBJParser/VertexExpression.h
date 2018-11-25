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
	~VertexExpression();
	void* interpret(void* context);
};

