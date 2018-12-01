#pragma once
#include <string>
#include "Face.h"
#include <vector>

using namespace std;

namespace Data
{
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
		virtual ~Group();
		string getMaterial();
		string getTexture();
		bool isSmooth();
		bool hasTextureBeenSet();
		bool hasMaterialBeenSet();
		bool hasSmoothBeenSet();
		void clearFaces();
		vector<Face>::iterator getFacesBegin();
		vector<Face>::iterator getFacesEnd();
		void setMaterial(string material);
		void setTexture(string texture);
		void setSmooth(bool smooth);
		void setFaces(vector<Face> faces);
		void addFace(Face face);
		string toString();
	};
}