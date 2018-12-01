#pragma once
#include "IExpression.h"
#include "ObjectExpression.h"
class MaterialExpression :
	public IExpression
{
public:
	MaterialExpression();
	virtual ~MaterialExpression();
	void* interpret(void* context);
};

