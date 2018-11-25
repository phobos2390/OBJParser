#pragma once

#include <vector>
#include "ModelObject.h"

using namespace std;

class OBJData
{
	vector<string> materialFileNames;
	vector<string> textureFileNames;
	vector<ModelObject> objects;
public:
	OBJData();
	~OBJData();
	void addMaterialFileName(string fileName);
	void addTextureFileName(string fileName);
	void addObject(ModelObject object);
	vector<string> getMaterialFileNames();
	vector<string> getTextureFileNames();
	vector<ModelObject> getObjects();
	string toString();
};

