#include "Input.hpp"

#include <raylib.h>

Input current_input;

/*
	This function 'compareInputs()' is ONLY
	meant to be used privately in here.
	which is why it has been hidden away in
	here. It serves no actual function to the
	program at large.
*/
bool compareInputs(Input a, Input b)
{
	if(
		a.character_pressed != b.character_pressed
		||
		a.left_pressed != b.left_pressed
		||
		!arePointsEqual(a.mouse_position, b.mouse_position)
	)
	{
		return true;
	}
	return false;
}

void updateInput()
{
	//Updates the mouse buttons.
	current_input.left_pressed = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
	current_input.right_pressed = IsMouseButtonPressed(MOUSE_RIGHT_BUTTON);

	//Updates the mouse position.
	current_input.mouse_position.x = GetMouseX();
	current_input.mouse_position.y = GetMouseY();

	//Updates the keyboard.
	current_input.character_pressed = GetCharPressed();

	static Input previous_input_set = { 0 };
	current_input.was_input_updated = compareInputs(previous_input_set, current_input);
	previous_input_set = current_input;
}

/*
	Returns a pointer to 'current_input'
	as there is only supposed to be one
	instance of the input struct;
*/
Input* getInput()
{
	return &current_input;
}