#include "OBJData.h"
#include <sstream>


OBJData::OBJData()
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

vector<string> OBJData::getMaterialFileNames()
{
	return this->materialFileNames;
}

vector<string> OBJData::getTextureFileNames()
{
	return this->textureFileNames;
}

vector<ModelObject> OBJData::getObjects()
{
	return this->objects;
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