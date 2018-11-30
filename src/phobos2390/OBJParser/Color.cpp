#include "Color.h"


Color::Color(float red, float green, float blue):red(red),green(green),blue(blue)
{
}


Color::~Color()
{
}

float Color::getRed() const
{
	return this->red;
}

float Color::getGreen() const
{
	return this->green;
}

float Color::getBlue() const
{
	return this->blue;
}
