#include "wrappers/HUSKFrameWork.hpp"

int main(int argc, char const *argv[])
{
    printSystemLog("Starting Program...");

    initDrawing(newDimensions(600, 600), "C BSP Engine", 120);
    HUSK husk = initialiseHUSK();
    huskLoop(husk);

    printSystemLog("Program closing \"safely\".");
    return 0;
}