#include "Face.h"
#include <assert.h>
#include <sstream>

Face::Face(FaceVertex first, FaceVertex second, FaceVertex third)
{
	this->addVertex(first);
	this->addVertex(second);
	this->addVertex(third);
}

Face::Face(vector<FaceVertex> vertices) :vertices(vertices)
{
	assert(vertices.size() >= 3);
}

Face::~Face()
{
}

void Face::addVertex(FaceVertex vertex)
{
	this->vertices.push_back(vertex);
}

string Face::toString()
{
	stringstream ss;
	string outerTabAmount = "\t\t\t\t";
	string innerTabAmount = "\t\t\t\t\t";
	string separator = "\n";
	ss << "Face Vertices:";
	int count = 0;
	for (vector<FaceVertex>::iterator i = this->vertices.begin(); i != this->vertices.end(); ++i)
	{
		ss << separator << innerTabAmount << (1 + count++) << ": " << i->toString();
		separator = ",\n";
	}
	return ss.str();
}