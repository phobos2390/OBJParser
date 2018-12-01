#pragma once

#include <vector>
#include "ModelObject.h"
#include "Material.h"

using namespace std;

namespace Data
{
	class OBJData
	{
		vector<string> materialFileNames;
		vector<string> textureFileNames;
		vector<Material> materials;
		vector<ModelObject> objects;
	public:
		OBJData();
                OBJData(const OBJData&);
		~OBJData();
		void addMaterialFileName(string fileName);
		void addTextureFileName(string fileName);
		void addObject(ModelObject object);
		void addMaterial(Material material);
		vector<string>::iterator getMaterialFileNamesBegin();
		vector<string>::iterator getMaterialFileNamesEnd();
		vector<string>::iterator getTextureFileNamesBegin();
		vector<string>::iterator getTextureFileNamesEnd();
		vector<Material>::iterator getMaterialsBegin();
		vector<Material>::iterator getMaterialsEnd();
		Material findMaterial(string name);
		vector<ModelObject>::iterator getObjectsBegin();
		vector<ModelObject>::iterator getObjectsEnd();
		string toString();
	};
}