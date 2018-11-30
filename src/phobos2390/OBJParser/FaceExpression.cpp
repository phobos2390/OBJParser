#include "FaceExpression.h"
#include "Parser.h"
#include "TokenTypes.h"
#include <sstream>
#include <vector>

using namespace std;

FaceExpression::FaceExpression(ObjectExpression* expression) :expression(expression)
{
}


FaceExpression::~FaceExpression()
{
}

void* FaceExpression::interpret(void* context)
{
	Parser* parser = (Parser*)context;
	Group currentGroup;
	while (parser->currentTokenTypeIs(FACE) 
		|| parser->currentTokenTypeIs(USEMAP) 
		|| parser->currentTokenTypeIs(USEMTL) 
		|| parser->currentTokenTypeIs(SMOOTH))
	{
		bool setNewGroup = false;
		if (parser->currentTokenTypeIs(USEMAP))
		{
			parser->match(USEMAP);
			currentGroup.setTexture(parser->getCurrentTokenInput());
			parser->match(IDENTIFIER);
		}
		if (parser->currentTokenTypeIs(USEMTL))
		{
			parser->match(USEMTL);
			currentGroup.setMaterial(parser->getCurrentTokenInput());
			parser->match(IDENTIFIER);
		}
		if (parser->currentTokenTypeIs(SMOOTH))
		{
			parser->match(SMOOTH);
			if (parser->currentTokenTypeIs(OFF))
			{
				currentGroup.setSmooth(false);
				parser->match(OFF);
			}
			else
			{
				currentGroup.setSmooth(true);
				parser->match(NUMBER);
			}
		}
		while (parser->currentTokenTypeIs(FACE))
		{
			parser->match(FACE);
			vector<FaceVertex> vertices;
			while (parser->currentTokenTypeIs(NUMBER))
			{
				string input = parser->getCurrentTokenInput();
				stringstream ss;
				ss << input;
				int vertexValue;
				ss >> vertexValue;
				ss.clear();
				FaceVertex addVertex(vertexValue);
				parser->match(NUMBER);
				parser->match(DASH);
				if (parser->currentTokenTypeIs(NUMBER))
				{
					ss << parser->getCurrentTokenInput();
					ss >> vertexValue;
					ss.clear();
					addVertex.setUVIndex(vertexValue);
					parser->match(NUMBER);
				}
				parser->match(DASH);
				if (parser->currentTokenTypeIs(NUMBER))
				{
					ss << parser->getCurrentTokenInput();
					ss >> vertexValue;
					ss.clear();
					addVertex.setNormalIndex(vertexValue);
					parser->match(NUMBER);
				}
				vertices.push_back(addVertex);
			}
			Face newFace(vertices);
			currentGroup.addFace(newFace);
		}
		expression->addGroup(currentGroup);
	}
	return parser;
}