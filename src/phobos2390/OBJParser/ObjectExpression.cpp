#include "ObjectExpression.h"
#include <vector>
#include "TokenTypes.h"
#include "Parser.h"

#include <iostream>

using namespace std;

ObjectExpression::ObjectExpression()
{
}

ObjectExpression::~ObjectExpression()
{
}

void ObjectExpression::addVertex(vector<float> vertex)
{
	if (vertex.size() == 3)
	{
		this->currentObject.addVertex(vertex[0], vertex[1], vertex[2]);
	}
	else if (vertex.size() == 4)
	{
		this->currentObject.addVertex(vertex[0], vertex[1], vertex[2],vertex[3]);
	}
}

void ObjectExpression::addUV(vector<float> uv)
{
	if (uv.size() == 2)
	{
		this->currentObject.addUV(uv[0], uv[1]);
	}
	else if (uv.size() == 3)
	{
		this->currentObject.addUV(uv[0], uv[1], uv[2]);
	}
}

void ObjectExpression::addNormal(vector<float> normal)
{
	this->currentObject.addNormal(normal[0], normal[1], normal[2]);
}

void ObjectExpression::addGroup(Group group)
{
	this->currentObject.addGroup(group);
}

void ObjectExpression::addLine(pair<int,int> line)
{
	this->currentObject.setLine(line);
}

void* ObjectExpression::interpret(void* context)
{
	Parser* parser = (Parser*)context;
	bool continuing = true;
	while (continuing)
	{
		if (parser->currentTokenTypeIs(MTLLIB))
		{
			parser->match(MTLLIB);
			while (parser->currentTokenTypeIs(IDENTIFIER))
			{
				parser->addMaterialFileName(parser->getCurrentTokenInput());
				parser->match(IDENTIFIER);
			}
		}
		else if (parser->currentTokenTypeIs(MAPLIB))
		{
			parser->match(MAPLIB);
			while (parser->currentTokenTypeIs(IDENTIFIER))
			{
				parser->addTextureFileName(parser->getCurrentTokenInput());
				parser->match(IDENTIFIER);
			}
		}
		else if (parser->currentTokenTypeIs(OBJECT))
		{
			cout << "Parsing object: ";
			while (parser->currentTokenTypeIs(OBJECT))
			{
				parser->match(OBJECT);
				this->currentObject.setIdentifier(parser->getCurrentTokenInput());
				cout << this->currentObject.getIdentifier() << endl;
				parser->match(IDENTIFIER);
				for (vector<IExpression*>::iterator j = this->getSubExpressionsStart(); j != this->getSubExpressionsEnd(); ++j)
				{
					(*j)->interpret(context);
				}
				parser->addObject(this->currentObject);
				cout << "Done! " << endl;
			}
		}
		else
		{
			continuing = false;
			parser->match(END_OF_FILE);
		}
	}
	return parser;
}
