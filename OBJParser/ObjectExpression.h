#ifndef OBJECT_EXPRESSION_DEFINED
#define OBJECT_EXPRESSION_DEFINED

#include "NonTerminalExpression.h"
#include <string>
#include <vector>
#include "ModelObject.h"

using namespace std;

class ObjectExpression :
	public NonTerminalExpression
{
private:
	ModelObject currentObject;
public:
	ObjectExpression();
	~ObjectExpression();
	void addVertex(vector<float> vertex);
	void addUV(vector<float> uv);
	void addNormal(vector<float> normal);
	void addGroup(Group group);
	void addLine(pair<int, int> line);
	void* interpret(void* context);
};

#endif