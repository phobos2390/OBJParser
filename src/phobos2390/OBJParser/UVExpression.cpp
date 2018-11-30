#include "UVExpression.h"
#include "Parser.h"
#include <vector>
#include "Token.h"
#include "TokenTypes.h"
#include <sstream>

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
			string input = parser->getCurrentTokenInput();
			stringstream ss(input);
			float vertexValue;
			ss >> vertexValue;
			parser->match(NUMBER);
			vectorValues.push_back(vertexValue);
		}
		this->expression->addUV(vectorValues);
	}
	return parser;
}