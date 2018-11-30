#pragma once
#include "Token.h"

class IExpression
{
public:
	IExpression();
	~IExpression();
	virtual void* interpret(void* context) = 0;
};

