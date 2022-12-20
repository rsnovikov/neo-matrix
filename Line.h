#pragma once

#include "Console.h"

struct Line {
    int x;
    int y;
    int lineLength;
    int maxY;
    int color;
    bool completed;

    Line(int _x, int _maxY, long long lastPrintTime, int _lineLength = 5, int _color = GREEN);

    void move();

public:
    long long lastPrintTime;
};