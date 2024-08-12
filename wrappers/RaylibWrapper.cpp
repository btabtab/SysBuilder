#include "Drawing.hpp"
#include "FrameExport.hpp"

#include <raylib.h>

//This will begin the window and drawing processes
void initDrawing(Dimensions dimensions, char* window_name, int target_fps)
{
	InitWindow(dimensions.x, dimensions.y, window_name);
	SetTargetFPS(target_fps);
}
//This will start drawing to the screen.
void beginDrawing()
{
	BeginDrawing();
}
//This will stop drawing to the screen.
void endDrawing()
{
	EndDrawing();
}
/*
	This checks if the window needs to be kept open.
	Returns true if the window should be kept open.
*/
bool keepWindowOpen()
{
	return !WindowShouldClose();
}
//This will clear the screen of everything.
void clearScreen(IntColour colour)
{
	Color clear_colour = GetColor(colour);
	clear_colour.a = 0xff;
	ClearBackground(clear_colour);
}

/*
	This is the raylib-based implementation
	of the drawfunctions for the different
	geometry structs.
*/

void drawPoint(Point point, IntColour colour)
{
	DrawCircle(point.x, point.y, 0.5f, GetColor(colour));
}
void drawLine(Line line, IntColour colour)
{
	DrawLine(line.a.x, line.a.y, line.b.getX(), line.b.y, GetColor(colour));
}
void drawCircle(Point position, float radius, IntColour colour)
{
	DrawCircle(position.x, position.y, radius, GetColor(colour));
}

void drawLineMidpointClockwise(Line line, IntColour colour)
{
	drawLine(
		newLine(
			getMidPoint(line),
			getLeftOfLine(line)
			),
		~0xa0a0bb00
		);
}

void drawGrid(int dots, int spacing, IntColour colour)
{
	for(int x = 0; x != dots; x++)
	{
		for(int y = 0; y != dots; y++)
		{
			Line horizontal = newLine(
				newPoint(
						(x * spacing),
						(y * spacing)
						),
				newPoint(
						(x * spacing) + spacing,
						(y * spacing) + 0
						)
							);

			Line vertical = newLine(
				horizontal.a,
				newPoint(
						(x * spacing) + 0,
						(y * spacing) + spacing
						)
							);
			drawLine(
					horizontal,
					colour
					);
			drawLine(
					vertical,
					colour
					);
		}
	}
}

void test3D()
{
	static bool is_init_done = false;
	static Camera3D camera = { 0 };
	if(!is_init_done)
	{
		camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
		camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
		camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
		camera.fovy = 20.f;
		camera.projection = CAMERA_ORTHOGRAPHIC;
		is_init_done = true;
	}
	ClearBackground(BLACK);
	DrawText("TEST", 0, 0, 20, RED);
	BeginMode3D(camera);

	DrawCube((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, RED);
	DrawCubeWires((Vector3){-4.0f, 0.0f, 2.0f}, 2.0f, 5.0f, 2.0f, GOLD);
	DrawCubeWires((Vector3){-4.0f, 0.0f, -2.0f}, 3.0f, 6.0f, 2.0f, MAROON);
	DrawSphere((Vector3){-1.0f, 0.0f, -2.0f}, 1.0f, GREEN);
	DrawSphereWires((Vector3){1.0f, 0.0f, 2.0f}, 2.0f, 16, 16, LIME);
	DrawCylinder((Vector3){4.0f, 0.0f, -2.0f}, 1.0f, 2.0f, 3.0f, 4, SKYBLUE);
	DrawCylinderWires((Vector3){4.0f, 0.0f, -2.0f}, 1.0f, 2.0f, 3.0f, 4, DARKBLUE);
	DrawCylinderWires((Vector3){4.5f, -1.0f, 2.0f}, 1.0f, 1.0f, 2.0f, 6, BROWN);
	DrawCylinder((Vector3){1.0f, 0.0f, -4.0f}, 0.0f, 1.5f, 3.0f, 8, GOLD);
	DrawCylinderWires((Vector3){1.0f, 0.0f, -4.0f}, 0.0f, 1.5f, 3.0f, 8, PINK);
	DrawCapsule     ((Vector3){-3.0f, 1.5f, -4.0f}, (Vector3){-4.0f, -1.0f, -4.0f}, 1.2f, 8, 8, VIOLET);
	DrawCapsuleWires((Vector3){-3.0f, 1.5f, -4.0f}, (Vector3){-4.0f, -1.0f, -4.0f}, 1.2f, 8, 8, PURPLE);
	DrawGrid(10, 1.0f);        // Draw a grid

	EndMode3D();
}

void setWindowTransparency(float transparency_value)
{
	if(1 < transparency_value)
	{
		transparency_value = 1.f;
	}
	if(transparency_value < 0)
	{
		transparency_value = 0;
	}
	SetWindowOpacity(transparency_value);
}

void drawText(char* text, Point position, int size, IntColour colour)
{
	DrawText(text, position.x, position.y, size, GetColor(colour));
}

void exportFrame(int limit)
{
	static int frame_number = 0;
	if(limit < frame_number)
	{
		return;
	}
	char file_name[40] = "";
	sprintf(file_name, "/frames/%03d.png", frame_number);
	TakeScreenshot(file_name);
	frame_number++;
}

void drawFilledTriangle(Polygon polygon, IntColour colour)
{
	DrawTriangle(
				*(Vector2*)&polygon.a,
				*(Vector2*)&polygon.b,
				*(Vector2*)&polygon.c,
				GetColor(colour)
				);
}

void drawPointArrayAsLines(Point* points, int amount_of_points, IntColour colour)
{
	DrawTriangleStrip(
						(Vector2*)&points,
						amount_of_points,
						GetColor(colour)
						);
}