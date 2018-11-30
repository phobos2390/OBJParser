#include "Material.h"


Material::Material():diffuse(0,0,0),specular(0,0,0),ambient(0,0,0)
{
}

Material::~Material()
{
}

string Material::getIdentifier()
{
	return this->identifier;
}
float Material::getSpecularExp()
{
	return this->specularExp;
}
float Material::getRefraction()
{
	return this->refraction;
}
float Material::getTransparency()
{
	return this->transparency;
}
Color Material::getAmbient()
{
	return this->ambient;
}
Color Material::getSpecular()
{
	return this->specular;
}
Color Material::getDiffuse()
{
	return this->diffuse;
}
int Material::getIllumination()
{
	return this->illumination;
}
void Material::setIdentifier(string id)
{
	this->identifier = id;
}
void Material::setSpecularExp(float exp)
{
	this->specularExp = exp;
}
void Material::setRefraction(float refraction)
{
	this->refraction = refraction;
}
void Material::setTransparency(float transparency)
{
	this->transparency = transparency;
}
void Material::setAmbient(Color amb)
{
	this->ambient = amb;
}
void Material::setSpecular(Color spec)
{
	this->specular = spec;
}
void Material::setDiffuse(Color diff)
{
	this->diffuse = diff;
}
void Material::setIllumination(int illum)
{
	this->illumination = illum;
}