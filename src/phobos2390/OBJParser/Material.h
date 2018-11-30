#pragma once
#include "Color.h"
#include <string>

using namespace std;

class Material
{
private:
	string identifier;
	float specularExp;
	float refraction;
	float transparency;
	Color ambient;
	Color specular;
	Color diffuse;
	int illumination;
public:
	string getIdentifier();
	float getSpecularExp();
	float getRefraction();
	float getTransparency();
	Color getAmbient();
	Color getSpecular();
	Color getDiffuse();
	int getIllumination();
	void setIdentifier(string);
	void setSpecularExp(float);
	void setRefraction(float);
	void setTransparency(float);
	void setAmbient(Color);
	void setSpecular(Color);
	void setDiffuse(Color);
	void setIllumination(int);
	Material();
	~Material();
};

