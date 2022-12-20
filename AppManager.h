#pragma once

#include <string>

class AppManager {
    int frequency;
    int drawLineInterval;
    int lineSpeed;
    int lineLength;
    bool isEpilepsy;
    int maxY, maxX;

    void getValuesFromUser();

    static int getIntFromUser(std::string str, int min = 1, int max = 30);

    static bool getIsEpilepsyFromUser();

public:
    void init();

    [[noreturn]] void run() const;
};

