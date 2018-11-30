#include "ModelObject.h"
#include <sstream>

namespace Data
{
	ModelObject::ModelObject()
	{
	}


	ModelObject::~ModelObject()
	{
	}

	void ModelObject::addVertex(float x, float y, float z)
	{
		Vector3f addVec;
		addVec.x = x;
		addVec.y = y;
		addVec.z = z;
		this->vertices.push_back(addVec);
	}

	void ModelObject::addVertex(float x, float y, float z, float w)
	{
		addVertex(x / w, y / w, z / w);
	}

	void ModelObject::addVertex(Vector3f vec)
	{
		this->vertices.push_back(vec);
	}

	void ModelObject::addUV(float x, float y)
	{
		Vector2f addVec;
		addVec.x = x;
		addVec.y = y;
		this->uvs.push_back(addVec);
	}

	void ModelObject::addUV(float x, float y, float z)
	{
		addUV(x / z, y / z);
	}

	void ModelObject::addUV(Vector2f vec)
	{
		this->uvs.push_back(vec);
	}

	void ModelObject::addNormal(float x, float y, float z)
	{
		Vector3f addVec;
		addVec.x = x;
		addVec.y = y;
		addVec.z = z;
		this->normals.push_back(addVec);
	}

	void ModelObject::addNormal(Vector3f vec)
	{
		this->normals.push_back(vec);
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

	vector<Group>::iterator ModelObject::getGroupsBegin()
	{
		return this->groups.begin();
	}

	Group ModelObject::getGroup(int index)
	{
		return this->groups[index];
	}

	vector<Group>::iterator ModelObject::getGroupsEnd()
	{
		return this->groups.end();
	}

	vector<Vector3f>::iterator ModelObject::getVerticesBegin()
	{
		return this->vertices.begin();
	}

	Vector3f ModelObject::getVertex(int index)
	{
		return this->vertices[index];
	}
	
	vector<Vector3f>::iterator ModelObject::getVerticesEnd()
	{
		return this->vertices.end();
	}

	vector<Vector2f>::iterator ModelObject::getUVsBegin()
	{
		return this->uvs.begin();
	}

	Vector2f ModelObject::getUV(int index)
	{
		return this->uvs[index];
	}

	vector<Vector2f>::iterator ModelObject::getUVsEnd()
	{
		return this->uvs.end();
	}

	vector<Vector3f>::iterator ModelObject::getNormalsBegin()
	{
		return this->normals.begin();
	}

	Vector3f ModelObject::getNormal(int index)
	{
		return this->normals[index];
	}

	vector<Vector3f>::iterator ModelObject::getNormalsEnd()
	{
		return this->normals.end();
	}

	vector<pair<int, int> >::iterator ModelObject::getLinesBegin()
	{
		return this->lines.begin();
	}

	pair<int,int> ModelObject::getLine(int index)
	{
		return this->lines[index];
	}

	vector<pair<int, int> >::iterator ModelObject::getLinesEnd()
	{
		return this->lines.end();
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

	string ModelObject::printVectors(string innerTabAmount, int sizeOfVec, vector<vector<float> >::iterator begin, vector<vector<float> >::iterator end)
	{
		string separator = "\n";
		stringstream ss;
		int counter = 0;
		for (vector<vector<float> >::iterator i = begin; i != end; ++i)
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
		/*string outerTabAmount = "\t";
		string innerTabAmount = "\t\t";
		string separator = "\n";
		int sizeOfVec = 3;
		int sizeOfUVVec = 2;
		ss << this->identifier << separator << outerTabAmount;
		ss << "Vertices (" << this->vertices.size() << "):" << this->printVectors(innerTabAmount, sizeOfVec, this->vertices.begin(), this->vertices.end());
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
			for (vector<pair<int, int> >::iterator i = this->lines.begin(); i != this->lines.end(); ++i)
			{
				ss << separator << innerTabAmount << (1 + counter++) << ": ";
				ss << i->first << " " << i->second;
				separator = ",\n";
			}
			separator = "\n";
		}*/
		return ss.str();
	}
}
