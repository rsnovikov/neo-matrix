#include <sys/ioctl.h>
#include "Console.h"

void Console::clearConsole() {
    puts("\x1B[2J");
}

void Console::moveCursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void Console::setColor(int colorNum) {
    printf("\x1B[1;%dm", colorNum);
}

void Console::getMaxXY(int *maxX, int *maxY) {
    struct winsize size{};
    ioctl(1, TIOCGWINSZ, &size);
    *maxX = size.ws_col;
    *maxY = size.ws_row;
}