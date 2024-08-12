#pragma once

#include "Point.hpp"

class Line
{
private:
    Point a, b;
public:
    Line():
    a(Point()), b(Point())
    {
    }
    Line(Point new_a, Point new_b):
    a(new_a), b(new_b)
    {
    }
};