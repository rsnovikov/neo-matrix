#pragma once

#include <string>

struct Utils {
    static int getRandomIntInRange(int start, int end);

    static int getRandomColor();

    static bool isNum(std::string str);
};
