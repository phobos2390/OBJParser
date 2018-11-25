#include "conversionFuncs.h"

int myAtoi(string str)
{
	int val = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		val = val * 10 + (str[i] - '0');
	}
	return val;
}

float myAtof(string str)
{
	float val = 0;
	bool periodSeen = false;
	bool negative = false;
	float divVal = 1;
	float pow = 10;
	for (int i = 0; i < str.length(); ++i)
	{
		if (periodSeen)
		{
			divVal *= pow;
		}
		if (str[i] == '.')
		{
			periodSeen = true;
		}
		else if (str[i] == '-')
		{
			negative = true;
		}
		else
		{
			val = val * 10 + (str[i] - '0');
		}
	}
	if (negative)
	{
		return -val / (divVal);
	}
	else
	{
		return val / (divVal);
	}
}