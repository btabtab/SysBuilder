#pragma once

#include <vector>

#include "RenderObject.hpp"
#include "Point.hpp"

class Polygon : RenderObject
{
private:
	std::vector<Point> points;
public:
	Polygon()
	{
	}
	void addPoint(Point point_to_add);
	void removePoint(int index_to_remove);
	void nukeContents();
	void draw();
};