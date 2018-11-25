#pragma once
#include <string>
#include "Face.h"
#include <vector>

using namespace std;

class Group
{
private:
	string useMtl;
	string useMap;
	bool smooth;
	bool hasTexture;
	bool hasMaterial;
	bool smoothBeenSet;
	vector<Face> faces;
public:
	Group();
	~Group();
	string getMaterial();
	string getTexture();
	bool isSmooth();
	bool hasTextureBeenSet();
	bool hasMaterialBeenSet();
	bool hasSmoothBeenSet();
	vector<Face> getFaces();
	void setMaterial(string material);
	void setTexture(string texture);
	void setSmooth(bool smooth);
	void setFaces(vector<Face> faces);
	void addFace(Face face);
	string toString();
};

