#pragma once

#include <string>

using namespace std;

namespace Data
{
	class FaceVertex
	{
	private:
		int vertexIndex;
		int uvIndex;
		int normalIndex;
		bool hasUVIndex;
		bool hasNormalIndex;
	public:
		FaceVertex(int);
		FaceVertex(int, int, int);
		~FaceVertex();
		int getVertexIndex();
		int getUVIndex();
		int getNormalIndex();
		bool hasUV();
		bool hasNormal();
		void setVertexIndex(int);
		void setUVIndex(int);
		void setNormalIndex(int);
		string toString();
	};
}