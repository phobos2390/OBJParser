#pragma once

#include <vector>
#include "Group.h"

using namespace std;

class ModelObject
{
private:
	string identifier;
	string material;
	string texture;
	bool smooth;
	vector<float*> vertices;
	vector<float*> uvs;
	vector<float*> normals;
	vector<Group> groups;
	vector<pair<int, int>> lines;
	string printVectors(string innerTabAmount, int sizeOfVec, vector<float*>::iterator begin, vector<float*>::iterator end);
public:
	ModelObject();
	~ModelObject();
	void addVertex(float x, float y, float z);
	void addVertex(float x, float y, float z, float w);
	void addUV(float x, float y);
	void addUV(float x, float y, float z);
	void addNormal(float x, float y, float z);
	void addGroup(Group group);
	void setLine(pair<int, int> line);
	void setIdentifier(const string&);
	string getIdentifier();
	void setMaterial(string material);
	void setSmoothLighting(bool isSmooth);
	void setTexture(string texture);
	string toString();
	vector<float*> getVertices();
	vector<float*> getUVs();
	vector<float*> getNormals();
	vector<pair<int, int>> getLines();
	vector<Group> getGroups();
};

