#include "NormalExpression.h"
#include "Parser.h"
#include "TokenTypes.h"
#include <sstream>
#include <vector>

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
			string input = parser->getCurrentTokenInput();
			stringstream ss(input);
			float vertexValue;
			ss >> vertexValue;
			parser->match(NUMBER);
			vectorValues.push_back(vertexValue);
		}
		this->expression->addNormal(vectorValues);
	}
	return parser;
}