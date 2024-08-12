#ifndef SUB_WINDOW
#define SUB_WINDOW

/*
    This will control the smaller windows
    within the main window. It will use
    RenderTextures to draw the contents.

    This will also display the names
    of each of the smaller windows
    and also the controls for the
    sub-windows.
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../Geometry/Point.hpp"

typedef struct SubWindow
{
    int ID;
    bool keep_open;
    Point position;
    Dimensions resolution;

    bool skip_next_update;
    bool is_paused;

    char name[30];
    void* render_texture;
}
SubWindow;

//This will create a new subwindow.
SubWindow newSubWindow(char* name, Point position, Dimensions dimensions);
//This will pause the subwindow.
void pauseSubWindow(SubWindow* sub_window);
//This will skip the next draw update.
void skipNextUpdate(SubWindow* sub_window);
//This will draw the subwindow on the screen.
SubWindow drawSubWindow(SubWindow* sub_window);
//This will close and kill the subwindow.
void closeSubWindow(SubWindow* sub_window);

//This will begin drawing to the subwindow.
void drawToSubWindow(SubWindow* sub_window);
//This ends any subwindow drawing that is currently happening.
void stopDrawingToSubWindow(SubWindow* sub_window);

#endif