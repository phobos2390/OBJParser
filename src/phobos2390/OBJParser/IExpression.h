#pragma once
#include "Token.h"

class IExpression
{
public:
	IExpression();
	virtual ~IExpression();
	virtual void* interpret(void* context) = 0;
};

