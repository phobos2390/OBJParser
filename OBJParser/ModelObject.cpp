#include "ModelObject.h"
#include <sstream>

ModelObject::ModelObject()
{
}


ModelObject::~ModelObject()
{
	vector<float*>::iterator iter;
	for (iter = this->vertices.begin(); iter != this->vertices.end(); iter++)
	{
		delete [] (*iter);
	}
	for (iter = this->uvs.begin(); iter != this->uvs.end(); iter++)
	{
		delete [] (*iter);
	}
	for (iter = this->normals.begin(); iter != this->normals.end(); iter++)
	{
		delete [] (*iter);
	}
}

void ModelObject::addVertex(float x, float y, float z)
{
	float* addfloat = new float[3];
	addfloat[0] = x;
	addfloat[1] = y;
	addfloat[2] = z;
	this->vertices.push_back(addfloat);
}

void ModelObject::addVertex(float x, float y, float z, float w)
{
	addVertex(x / w, y / w, z / w);
}

void ModelObject::addUV(float x, float y)
{
	float* uv = new float[2];
	uv[0] = x;
	uv[1] = y;
	this->uvs.push_back(uv);
}

void ModelObject::addUV(float x, float y, float z)
{
	addUV(x / z, y / z);
}

void ModelObject::addNormal(float x, float y, float z)
{
	float* normal = new float[3];
	normal[0] = x;
	normal[1] = y;
	normal[2] = z;
	this->normals.push_back(normal);
}

void ModelObject::addGroup(Group group)
{
	this->groups.push_back(group);
}

void ModelObject::setLine(pair<int, int> line)
{
	this->lines.push_back(line);
}

void ModelObject::setIdentifier(const string& identifier)
{
	this->identifier = identifier;
}

void ModelObject::setMaterial(string material)
{
	this->material = material;
}

void ModelObject::setSmoothLighting(bool isSmooth)
{
	this->smooth = isSmooth;
}

void ModelObject::setTexture(string texture)
{
	this->texture = texture;
}

string ModelObject::printVectors(string innerTabAmount, int sizeOfVec, vector<float*>::iterator begin, vector<float*>::iterator end)
{
	string separator = "\n";
	stringstream ss;
	int counter = 0;
	for (vector<float*>::iterator i = begin; i != end; ++i)
	{
		ss << separator << innerTabAmount << (1 + counter++) << ": ";
		for (int j = 0; j < sizeOfVec; ++j)
		{
			ss << (*i)[j] << " ";
		}
		separator = ",\n";
	}
	return ss.str();
}

string ModelObject::getIdentifier()
{
	return this->identifier;
}

string ModelObject::toString()
{
	stringstream ss;
	string outerTabAmount = "\t";
	string innerTabAmount = "\t\t";
	string separator = "\n";
	int sizeOfVec = 3;
	int sizeOfUVVec = 2;
	ss << this->identifier << separator << outerTabAmount;
	ss << "Vertices ("<< this->vertices.size()<<"):" << this->printVectors(innerTabAmount, sizeOfVec, this->vertices.begin(), this->vertices.end());
	ss << separator << outerTabAmount;
	if (this->uvs.size() > 0)
	{
		ss << "Texture Coordinates (" << this->uvs.size() << "):" << this->printVectors(innerTabAmount, sizeOfUVVec, this->uvs.begin(), this->uvs.end());
		ss << separator << outerTabAmount;
	}
	if (this->normals.size() > 0)
	{
		ss << "Normals (" << this->normals.size() << "):" << this->printVectors(innerTabAmount, sizeOfVec, this->normals.begin(), this->normals.end());
		ss << separator << outerTabAmount;
	}
	ss << "Groups (" << this->groups.size() << "):";
	int counter = 0;
	for (vector<Group>::iterator i = this->groups.begin(); i != this->groups.end(); ++i)
	{
		ss << separator << innerTabAmount << (1 + counter++) << ": " << i->toString();
		separator = ",\n";
	}
	separator = "\n";
	ss << separator << outerTabAmount;
	if (this->lines.size() > 0)
	{
		ss << "Lines (" << this->lines.size() << "):";
		counter = 0;
		for (vector<pair<int, int>>::iterator i = this->lines.begin(); i != this->lines.end(); ++i)
		{
			ss << separator << innerTabAmount << (1 + counter++) << ": ";
			ss << i->first << " " << i->second;
			separator = ",\n";
		}
		separator = "\n";
	}
	return ss.str();
}