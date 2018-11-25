#include "LineExpression.h"
#include "Parser.h"
#include "TokenTypes.h"
#include <vector>
#include <sstream>
#include <string>
#include "conversionFuncs.h"

using namespace std;

LineExpression::LineExpression(ObjectExpression* expression) :expression(expression)
{
}


LineExpression::~LineExpression()
{
}

void* LineExpression::interpret(void*context)
{
	Parser* parser = (Parser*)context;
	while (parser->currentTokenTypeIs(LINE))
	{
		parser->match(LINE);
		pair<int, int> lineVertices;
		lineVertices.first = myAtoi(parser->getCurrentTokenInput());
		parser->match(NUMBER);
		lineVertices.second = myAtoi(parser->getCurrentTokenInput());
		parser->match(NUMBER);
		this->expression->addLine(lineVertices);
	}
	return parser;
}