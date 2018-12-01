#pragma once

#include "FaceVertex.h"
#include <vector>

using namespace std;

namespace Data
{
	class Face
	{
	private:
		vector<FaceVertex> vertices;
	public:
		Face(FaceVertex first, FaceVertex second, FaceVertex third);
		Face(vector<FaceVertex> vertices);
		virtual ~Face();
		void addVertex(FaceVertex vertex);
		vector<FaceVertex> getVertices();
		string toString();
	};
}