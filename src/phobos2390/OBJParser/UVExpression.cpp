#include "UVExpression.h"
#include "Parser.h"
#include <vector>
#include "Token.h"
#include "TokenTypes.h"
#include <sstream>
#include "conversionFuncs.h"

using namespace std;

UVExpression::UVExpression(ObjectExpression* expression) :expression(expression)
{
}


UVExpression::~UVExpression()
{
}

void* UVExpression::interpret(void* context)
{
	Parser* parser = (Parser*)context;
	while (parser->currentTokenTypeIs(TEXTURE_COORD))
	{
		parser->match(TEXTURE_COORD);
		vector<float> vectorValues;
		while (parser->currentTokenTypeIs(NUMBER))
		{
			vectorValues.push_back(myAtof(parser->getCurrentTokenInput()));
			parser->match(NUMBER);
		}
		this->expression->addUV(vectorValues);
	}
	return parser;
}