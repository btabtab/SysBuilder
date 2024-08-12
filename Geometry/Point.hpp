#pragma once

#include <iostream>

class Point
{
private:
	float x, y;
public:
	Point():
	x(0), y(0)
	{
	}
	Point(float new_x, float new_y):
	x(new_x), y(new_y)
	{
	}

	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}
};