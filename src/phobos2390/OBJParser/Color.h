#pragma once
class Color
{
	float red;
	float green;
	float blue;
public:
	Color(float red, float green, float blue);
	virtual ~Color();
	float getRed() const;
	float getGreen() const;
	float getBlue() const;
};

