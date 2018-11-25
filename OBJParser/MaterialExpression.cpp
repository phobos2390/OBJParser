#include "MaterialExpression.h"
#include "Parser.h"
#include "TokenTypes.h"
#include <sstream>
#include "conversionFuncs.h"

using namespace std;

MaterialExpression::MaterialExpression()
{
}


MaterialExpression::~MaterialExpression()
{
}

void* MaterialExpression::interpret(void* context)
{
	Parser* parser = (Parser*)context;
	while (parser->currentTokenTypeIs(NEWMTL))
	{
		parser->match(NEWMTL);
		Material addMat;
		addMat.setIdentifier(parser->getCurrentTokenInput());
		parser->match(IDENTIFIER);
		stringstream ss;

		while (!parser->currentTokenTypeIs(NEWMTL) && !parser->currentTokenTypeIs(END_OF_FILE))
		{
			if (parser->currentTokenTypeIs(SPECULAR_EXP))
			{
				parser->match(SPECULAR_EXP);
				addMat.setSpecularExp(myAtof(parser->getCurrentTokenInput()));
				parser->match(NUMBER);
			}
			else if (parser->currentTokenTypeIs(REFRACTION))
			{
				parser->match(REFRACTION);
				addMat.setRefraction(myAtof(parser->getCurrentTokenInput()));
				parser->match(NUMBER);
			}
			else if (parser->currentTokenTypeIs(COLOR_AMBIENT))
			{
				parser->match(COLOR_AMBIENT);
				float red, green, blue;
				red = myAtof(parser->getCurrentTokenInput());
				parser->match(NUMBER);
				green = myAtof(parser->getCurrentTokenInput());
				parser->match(NUMBER);
				blue = myAtof(parser->getCurrentTokenInput());
				parser->match(NUMBER);
				Color setColor(red, green, blue);
				addMat.setAmbient(setColor);
			}
			else if (parser->currentTokenTypeIs(COLOR_SPECULAR))
			{
				parser->match(COLOR_SPECULAR);
				float red, green, blue;
				red = myAtof(parser->getCurrentTokenInput());
				parser->match(NUMBER);
				green = myAtof(parser->getCurrentTokenInput());
				parser->match(NUMBER);
				blue = myAtof(parser->getCurrentTokenInput());
				parser->match(NUMBER);
				Color setColor(red, green, blue);
				addMat.setSpecular(setColor);
			}
			else if (parser->currentTokenTypeIs(COLOR_DIFFUSE))
			{
				parser->match(COLOR_DIFFUSE);
				float red, green, blue;
				red = myAtof(parser->getCurrentTokenInput());
				parser->match(NUMBER);
				green = myAtof(parser->getCurrentTokenInput());
				parser->match(NUMBER);
				blue = myAtof(parser->getCurrentTokenInput());
				parser->match(NUMBER);
				Color setColor(red, green, blue);
				addMat.setDiffuse(setColor);
			}
			else if (parser->currentTokenTypeIs(ILLUMINATION))
			{
				parser->match(ILLUMINATION);
				addMat.setIllumination(myAtoi(parser->getCurrentTokenInput()));
				parser->match(NUMBER);
			}
			else if (parser->currentTokenTypeIs(TRANSPARENCY))
			{
				parser->match(TRANSPARENCY);
				addMat.setTransparency(myAtof(parser->getCurrentTokenInput()));
				parser->match(NUMBER);
			}
		}
		parser->addMaterial(addMat);
	}
	return parser;
}