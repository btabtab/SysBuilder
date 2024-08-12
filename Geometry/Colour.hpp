#pragma once

#include <inttypes.h>

class Colour
{
private:
	uint8_t red, green, blue, alpha;
public:
	Colour():
	red(0), green(0), blue(0), alpha(0)
	{
	}
	Colour(uint8_t r, uint8_t g, uint8_t b, uint8_t a):
	red(r), green(g), blue(b), alpha(a)
	{
	}
	void setRed();
	void setGreen();
	void setBlue();
	void setAlpha();

	void mixWithOtherColour(Colour other, bool mix_alpha);
	void invert();
	Colour getInverted();
};

#define BLACK Colour(0, 0, 0, 0xff)
#define WHITE Colour(0xff, 0xff, 0xff, 0xff)

#define RED Colour(0xff, 0, 0, 0xff)
#define GREEN Colour(0, 0xff, 0, 0xff)
#define BLUE Colour(0, 0, 0xff, 0xff)

#define PURPLE Colour(0xff, 0, 0xff, 0xff)