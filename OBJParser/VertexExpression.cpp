#include "VertexExpression.h"
#include "Parser.h"
#include "TokenTypes.h"
#include <vector>
#include <sstream>
#include <string>

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
			string input = parser->getCurrentTokenInput();
			stringstream ss(input);
			float vertexValue;
			ss >> vertexValue;
			parser->match(NUMBER);
			vectorValues.push_back(vertexValue);
		}
		this->expression->addVertex(vectorValues);
	}
	return parser;
}