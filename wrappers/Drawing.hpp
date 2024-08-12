#ifndef DRAWING
#define DRAWING
#include <iostream>

#include "../Geometry/Geometry.hpp"

#define OPAQUE 0xFF
#define ALMOST_TRANSPARENT 0xF0
#define TRANSLUCENT 0X0F
#define NEARLY_INVISIBLE 0X0A
#define TRANSPARENT 0x00

//Stores the colour to draw.
typedef unsigned int IntColour;
#define INTRED ((unsigned int)0xFF0000FF)
#define INTYELLOW ((unsigned int)0x0FF000FF)
#define INTGREEN ((unsigned int)0x00FF00FF)
#define INTOTHER ((unsigned int)0x000FF0FF)
#define INTBLUE ((unsigned int)0x0000FFFF)
#define INTPORPOL ((unsigned int)0xFF00FFFF)

//This will begin the window and drawing processes
void initDrawing(Dimensions dimensions, char* window_name, int target_fps);
//This will start drawing to the screen.
void beginDrawing();
//This will stop drawing to the screen.
void endDrawing();
//This checks if the window needs to be kept open.
bool keepWindowOpen();
//This will clear the screen of everything.
void clearScreen(IntColour colour);

//This will draw a single point on the screen.
void drawPoint(Point point, IntColour colour);
void drawLine(Line line, IntColour colour);
void drawCircle(Point point, float radius, IntColour colour);
void drawPolygon(Polygon, IntColour colour);
void drawSplitLine(SplitLine split_line, IntColour colour);
void drawBrush(Brush* brush, IntColour colour);

//Diagnosting drawing?
void drawLineMidpointClockwise(Line line, IntColour colour);

void drawSpace(Space space, int depth);

void drawBoundingBox(Point position, Dimensions dimensions, IntColour colour);

void drawGrid(int dots, int spacing, IntColour colour);

void test3D();

void setWindowTransparency(float transparency_value);

void drawText(char* text, Point position, int size, IntColour colour);

void drawPlane(Plane plane, IntColour colour);

void drawSector(Sector sector, IntColour colour);

void drawBrushSpace(BrushSpace* brush_space, IntColour colour);

void drawFilledTriangle(Polygon polygon, IntColour colour);
void drawPointArrayAsLines(Point* points, int amount_of_points, IntColour colour);

#endif