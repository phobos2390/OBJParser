#include "OBJData.h"
#include <sstream>

namespace Data
{
	OBJData::OBJData()
        : materialFileNames()
	, textureFileNames()
	, materials()
	, objects()
        {
	}

	OBJData::OBJData(const OBJData& data)
        : materialFileNames(data.materialFileNames)
        , textureFileNames(data.textureFileNames)
        , materials(data.materials)
        , objects(data.objects)
	{
	}


	OBJData::~OBJData()
	{
	}

	void OBJData::addMaterialFileName(string fileName)
	{
		this->materialFileNames.push_back(fileName);
	}

	void OBJData::addTextureFileName(string fileName)
	{
		this->textureFileNames.push_back(fileName);
	}

	void OBJData::addObject(ModelObject object)
	{
		this->objects.push_back(object);
	}

	void OBJData::addMaterial(Material material)
	{
		this->materials.push_back(material);
	}

	vector<string>::iterator OBJData::getMaterialFileNamesBegin()
	{
		return this->materialFileNames.begin();
	}

	vector<string>::iterator OBJData::getMaterialFileNamesEnd()
	{
		return this->materialFileNames.end();
	}

	vector<string>::iterator OBJData::getTextureFileNamesBegin()
	{
		return this->textureFileNames.begin();
	}

	vector<string>::iterator OBJData::getTextureFileNamesEnd()
	{
		return this->textureFileNames.end();
	}

	vector<Material>::iterator OBJData::getMaterialsBegin()
	{
		return this->materials.begin();
	}

	vector<Material>::iterator OBJData::getMaterialsEnd()
	{
		return this->materials.end();
	}

	Material OBJData::findMaterial(string name)
	{
		Material retMat;
		for (vector<Material>::iterator i = getMaterialsBegin(); i != getMaterialsEnd(); ++i)
		{
			if (name == i->getIdentifier())
			{
				retMat = *i;
			}
		}
		return retMat;
	}

	vector<ModelObject>::iterator OBJData::getObjectsBegin()
	{
		return this->objects.begin();
	}

	vector<ModelObject>::iterator OBJData::getObjectsEnd()
	{
		return this->objects.end();
	}

	string OBJData::toString()
	{
		stringstream ss;
		string outerTabAmount = "";
		string innerTabAmount = "\t";
		string separator = "\n";
		int counter;
		if (this->materialFileNames.size() > 0)
		{
			ss << "Material Files (" << this->materialFileNames.size() << "):";
			counter = 0;
			for (vector<string>::iterator i = this->materialFileNames.begin(); i != this->materialFileNames.end(); ++i)
			{
				ss << separator << innerTabAmount << (1 + counter++) << ": " << (*i);
				separator = ",\n";
			}
			separator = "\n";
			ss << separator << outerTabAmount;
		}
		if (this->textureFileNames.size() > 0)
		{
			ss << "Texture Files (" << this->textureFileNames.size() << "):";
			counter = 0;
			for (vector<string>::iterator i = this->textureFileNames.begin(); i != this->textureFileNames.end(); ++i)
			{
				ss << separator << innerTabAmount << (1 + counter++) << ": " << (*i);
				separator = ",\n";
			}
			separator = "\n";
			ss << separator << outerTabAmount;
		}
		ss << "Model Objects (" << this->objects.size() << "):";
		counter = 0;
		for (vector<ModelObject>::iterator i = this->objects.begin(); i != this->objects.end(); ++i)
		{
			ss << separator << innerTabAmount << (1 + counter++) << ": " << i->toString();
			separator = ",\n";
		}
		return ss.str();
	}
}