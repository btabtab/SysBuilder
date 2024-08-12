#include "Drawing.hpp"

void drawBoundingBox(Point position, Dimensions dimensions, IntColour colour)
{
	drawLine(newLine(position, addPoints(position, dimensions)), colour);
	drawLine(newLine(position, addPoints(position, dimensions)), colour);
}

void drawPolygon(Polygon polygon, IntColour colour)
{
	drawLine(newLine(polygon.a, polygon.b), colour);
	drawLine(newLine(polygon.b, polygon.c), colour);
	drawLine(newLine(polygon.c, polygon.a), colour);
}

/*
	This will draw the given space and will
	also render the sub-spaces within the
	space until the maximum depth has been
	traversed to.

	A negative 'depth' is for the left side
	and positive 'depth' is for the right side.
*/
void drawSpace(Space space, int depth)
{
	for(int i = 0; i != 4; i++)
	{
		drawPlane(space.planes[i], INTGREEN);
	}
}

void drawBrush(Brush* brush, IntColour colour)
{
	drawLine(newLine(brush->a, brush->b), colour);
	drawLine(newLine(brush->b, brush->c), colour);
	drawLine(newLine(brush->c, brush->d), colour);
	drawLine(newLine(brush->d, brush->a), colour);
}

void drawPlane(Plane plane, IntColour colour)
{
	if(plane.type == false)
	{
		return;
	}

	drawLine(plane.geometry, colour);
	drawLineMidpointClockwise(plane.geometry, (~colour) | OPAQUE);
	char text_buffer[5] = "";

	drawText(text_buffer, getMidPoint(plane.geometry), 5, ~0);
}

void drawBrushSpace(BrushSpace* brush_space, IntColour colour)
{
	drawBrush(&brush_space->brushes[0], ~0);

	for(int i = 1; i != brush_space->brush_count; i++)
	{
		IntColour brush_draw_colour = (colour >> (colour == ~0)) | OPAQUE;
		drawBrush(&brush_space->brushes[i], brush_draw_colour);
	}
}

void drawSector(Sector sector, IntColour colour)
{
	drawLine(newLine(sector.a, sector.c), (~colour) | OPAQUE);
	drawLine(newLine(sector.b, sector.d), (~colour) | OPAQUE);
	
	drawLine(newLine(sector.a, sector.b), colour);
	drawLine(newLine(sector.b, sector.c), colour);
	drawLine(newLine(sector.c, sector.d), colour);
	drawLine(newLine(sector.d, sector.a), colour);
	
	drawCircle(sector.a, 3, (~colour >> 1) | OPAQUE);
	drawCircle(sector.b, 3, (~colour >> 1) | OPAQUE);
	drawCircle(sector.c, 3, (~colour >> 1) | OPAQUE);
	drawCircle(sector.d, 3, (~colour >> 1) | OPAQUE);
}