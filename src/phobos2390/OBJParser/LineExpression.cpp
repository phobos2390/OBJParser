#include "LineExpression.h"
#include "Parser.h"
#include "TokenTypes.h"
#include <vector>
#include <sstream>
#include <string>

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
		pair<int, int> vectorValues;
		string input = parser->getCurrentTokenInput();
		stringstream ss;
		pair<int, int> lineVertices;
		ss << parser->getCurrentTokenInput();
		ss >> lineVertices.first;
		ss.clear();
		parser->match(NUMBER);
		ss << parser->getCurrentTokenInput();
		ss >> lineVertices.second;
		ss.clear();
		parser->match(NUMBER);
		this->expression->addLine(lineVertices);
	}
	return parser;
}