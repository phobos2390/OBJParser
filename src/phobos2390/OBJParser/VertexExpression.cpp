#include "VertexExpression.h"
#include "Parser.h"
#include "TokenTypes.h"
#include <vector>
#include <sstream>
#include <string>
#include "conversionFuncs.h"

using namespace std;

VertexExpression::VertexExpression(ObjectExpression* expression) :expression(expression)
{
}


VertexExpression::~VertexExpression()
{
}

void* VertexExpression::interpret(void* context)
{
	Parser* parser = (Parser*)context;
	while (parser->currentTokenTypeIs(VERTEX))
	{
		parser->match(VERTEX);
		vector<float> vectorValues;
		while (parser->currentTokenTypeIs(NUMBER))
		{
			vectorValues.push_back(myAtof(parser->getCurrentTokenInput()));
			parser->match(NUMBER);
		}
		this->expression->addVertex(vectorValues);
	}
	return parser;
}