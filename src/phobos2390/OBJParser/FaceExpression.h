#pragma once
#include "IExpression.h"
#include "ObjectExpression.h"

class FaceExpression :
	public IExpression
{
private:
	ObjectExpression* expression;
public:
	FaceExpression(ObjectExpression* expression);
	~FaceExpression();
	void* interpret(void* context);
};
