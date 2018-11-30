#pragma once

#include <vector>
#include "Group.h"
#include "Vector2.h"
#include "Vector3.h"

using namespace std;

namespace Data
{
	class ModelObject
	{
	private:
		string identifier;
		string material;
		string texture;
		bool smooth;
		vector<Vector3f> vertices;
		vector<Vector2f> uvs;
		vector<Vector3f> normals;
		vector<Group> groups;
		vector<pair<int, int> > lines;
		string printVectors(string innerTabAmount, int sizeOfVec, vector<vector<float> >::iterator begin, vector<vector<float> >::iterator end);
	public:
		ModelObject();
		~ModelObject();
		void addVertex(float x, float y, float z);
		void addVertex(float x, float y, float z, float w);
		void addVertex(Vector3f vec);
		void addUV(float x, float y);
		void addUV(float x, float y, float z);
		void addUV(Vector2f vec);
		void addNormal(float x, float y, float z);
		void addNormal(Vector3f vec);
		void addGroup(Group group);
		void setLine(pair<int, int> line);
		void setIdentifier(const string&);
		string getIdentifier();
		void setMaterial(string material);
		void setSmoothLighting(bool isSmooth);
		void setTexture(string texture);
		string toString();
		vector<Vector3f>::iterator getVerticesBegin();
		Vector3f getVertex(int index);
		vector<Vector3f>::iterator getVerticesEnd();
		vector<Vector2f>::iterator getUVsBegin();
		Vector2f getUV(int index);
		vector<Vector2f>::iterator getUVsEnd();
		vector<Vector3f>::iterator getNormalsBegin();
		Vector3f getNormal(int index);
		vector<Vector3f>::iterator getNormalsEnd();
		vector<pair<int, int> >::iterator getLinesBegin();
		pair<int, int> getLine(int index);
		vector<pair<int, int> >::iterator getLinesEnd();
		vector<Group>::iterator getGroupsBegin();
		Group getGroup(int index);
		vector<Group>::iterator getGroupsEnd();
	};
}
