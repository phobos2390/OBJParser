#include "FaceVertex.h"
#include <sstream>

namespace Data
{
	FaceVertex::FaceVertex(int vertexIndex)
		: vertexIndex(vertexIndex),
		hasUVIndex(false),
		hasNormalIndex(false)
	{

	}

	FaceVertex::FaceVertex(int vertexIndex, int uvIndex, int normalIndex)
		: vertexIndex(vertexIndex),
		uvIndex(uvIndex),
		normalIndex(normalIndex),
		hasUVIndex(true),
		hasNormalIndex(true)
	{

	}

	FaceVertex::~FaceVertex()
	{
	}

	int FaceVertex::getVertexIndex()
	{
		return this->vertexIndex;
	}

	int FaceVertex::getUVIndex()
	{
		return this->uvIndex;
	}

	int FaceVertex::getNormalIndex()
	{
		return this->normalIndex;
	}

	void FaceVertex::setVertexIndex(int vert)
	{
		this->vertexIndex = vert;
	}

	void FaceVertex::setUVIndex(int uvIndex)
	{
		this->uvIndex = uvIndex;
		this->hasUVIndex = true;
	}

	void FaceVertex::setNormalIndex(int normalIndex)
	{
		this->normalIndex = normalIndex;
		this->hasNormalIndex = true;
	}

	bool FaceVertex::hasUV()
	{
		return this->hasUVIndex;
	}

	bool FaceVertex::hasNormal()
	{
		return this->hasNormalIndex;
	}

	string FaceVertex::toString()
	{
		stringstream ss;
		ss << "v" << this->vertexIndex;
		ss << "/";
		if (this->hasUVIndex)
		{
			ss << "vt" << this->uvIndex;
		}
		ss << "/";
		if (this->hasNormalIndex)
		{
			ss << "vn" << this->normalIndex;
		}
		return ss.str();
	}
}