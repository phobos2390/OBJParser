#include "NormalExpression.h"
#include "Parser.h"
#include "TokenTypes.h"
#include <sstream>
#include <vector>
#include "conversionFuncs.h"

NormalExpression::NormalExpression(ObjectExpression* expression) :expression(expression)
{
}


NormalExpression::~NormalExpression()
{
}

void* NormalExpression::interpret(void* context)
{
	Parser* parser = (Parser*)context;
	while (parser->currentTokenTypeIs(NORMAL))
	{
		parser->match(NORMAL);
		vector<float> vectorValues;
		while (parser->currentTokenTypeIs(NUMBER))
		{
			vectorValues.push_back(myAtof(parser->getCurrentTokenInput()));
			parser->match(NUMBER);
		}
		this->expression->addNormal(vectorValues);
	}
	return parser;
}