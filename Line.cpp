#include "Line.h"
#include "Utils.h"
#include "Symbol.h"

Line::Line(int _x, int _maxY, long long _lastPrintTime, int _lineLength, int _color)
        : x(_x), maxY(_maxY), lineLength(_lineLength), color(_color), lastPrintTime(_lastPrintTime) {
    y = 0;
    completed = false;
}

void Line::move() {
    if (lineLength <= y && y < maxY + lineLength) {
        Console::moveCursor(
                lineLength % 2 == 0 ? (y % 2 == 0 ? x : x + 1) : (y % 2 == 0 ? x + 1 : x),
                maxY - y + lineLength);
        printf(" ");
        fflush(stdout);
    }
    if (y < maxY) {
        Console::setColor(WHITE);
        Symbol::print(char(Utils::getRandomIntInRange(65, 89)), y % 2 == 0 ? x : x + 1, maxY - y);
        fflush(stdout);
        if (y != 0 && lineLength != 1) {
            Console::setColor(color);
            Symbol::print(char(Utils::getRandomIntInRange(65, 89)), y % 2 == 0 ? x + 1 : x, maxY - y + 1);
            fflush(stdout);
        }
    } else if (y == maxY) {
        Console::setColor(color);
        Symbol::print(char(Utils::getRandomIntInRange(65, 89)), y % 2 == 0 ? x + 1 : x, 0);
    }
    y++;

    if (y >= maxY + lineLength) this->completed = true;
}