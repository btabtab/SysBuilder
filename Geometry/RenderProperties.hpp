#pragma once

#include "Colour.hpp"

class RenderProperties
{
private:
    Colour colour;
public:
    Colour* getColour();
};