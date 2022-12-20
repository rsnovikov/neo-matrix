#pragma once

#include <string>
#include <vector>

#define GREEN  32
#define WHITE  37
#define MIN_COLOR_INT  31
#define MAX_COLOR_INT  36

struct Console {
    static void clearConsole();

    static void moveCursor(int x, int y);

    static void setColor(int colorNum);

    static void getMaxXY(int *maxX, int *maxY);
};