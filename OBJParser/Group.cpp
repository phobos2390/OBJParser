#include "Group.h"
#include <sstream>

Group::Group() :hasTexture(false), hasMaterial(false), smoothBeenSet(false)
{
}

Group::~Group()
{
}

string Group::getMaterial()
{
	return this->useMtl;
}

string Group::getTexture()
{
	return this->useMap;
}

bool Group::isSmooth()
{
	return this->smooth;
}

vector<Face> Group::getFaces()
{
	return this->faces;
}

void Group::setMaterial(string material)
{
	this->hasMaterial = true;
	this->useMtl = material;
}

void Group::setTexture(string texture)
{
	this->hasTexture = true;
	this->useMap = texture;
}

void Group::setSmooth(bool smooth)
{
	this->smoothBeenSet = true;
	this->smooth = smooth;
}

void Group::setFaces(vector<Face> faces)
{
	this->faces = faces;
}

void Group::addFace(Face face)
{
	this->faces.push_back(face);
}

bool Group::hasTextureBeenSet()
{
	return this->hasTexture;
}

bool Group::hasMaterialBeenSet()
{
	return this->hasMaterial;
}

bool Group::hasSmoothBeenSet()
{
	return this->smoothBeenSet;
}

string Group::toString()
{
	stringstream ss;
	string outerTabAmount = "\t\t\t";
	string innerTabAmount = "\t\t\t\t";
	string separator = "\n";
	if (this->hasMaterial)
	{
		ss << "Material: " << this->useMtl << separator << outerTabAmount;
	}
	if (this->hasTexture)
	{
		ss << "Texture: " << this->useMap << separator << outerTabAmount;
	}
	if (this->smoothBeenSet)
	{
		if (this->smooth)
		{
			ss << "Smooth Shading" << separator << outerTabAmount;
		}
		else
		{
			ss << "Flat Shading" << separator << outerTabAmount;
		}
	}
	ss << "Faces: ";
	int counter = 0;
	for (vector<Face>::iterator i = this->faces.begin(); i != faces.end(); ++i)
	{
		ss << separator << innerTabAmount << (1 + counter++) << ": " << i->toString();
		separator = ",\n";
	}
	return ss.str();
}