#pragma once

#include <string>

using namespace std;

class FaceVertex
{
private:
	int vertexIndex;
	int uvIndex;
	int normalIndex;
	bool hasUVIndex;
	bool hasNormalIndex;
public:
	FaceVertex(int);
	FaceVertex(int, int, int);
	~FaceVertex();
	int getVertexIndex();
	int getUVIndex();
	int getNormalIndex();
	void setVertexIndex(int);
	void setUVIndex(int);
	void setNormalIndex(int);
	string toString();
};

