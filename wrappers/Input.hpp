#ifndef INPUT_CONTROL
#define INPUT_CONTROL

#include "../Geometry/Geometry.hpp"

typedef struct Input
{
    int character_pressed;
    Point mouse_position;

    bool left_pressed;
    bool right_pressed;

    bool was_input_updated;
}
Input;


void updateInput();
Input* getInput();

#endif