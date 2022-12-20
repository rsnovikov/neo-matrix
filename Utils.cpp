#include "Utils.h"
#include <random>
#include "Console.h"

using namespace std;

int Utils::getRandomIntInRange(int start, int end) {
    random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(start, end);
    return uni(rng);
}

int Utils::getRandomColor() {
    int color = Utils::getRandomIntInRange(MIN_COLOR_INT, MAX_COLOR_INT);
    return color;
}

bool Utils::isNum(string str) {
    bool flag = true;
    for (char i: str) {
        if (!isdigit(i)) {
            flag = false;
            break;
        }
    }
    return flag;
}
