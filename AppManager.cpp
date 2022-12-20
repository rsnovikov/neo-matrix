#include "AppManager.h"
#include <cstdio>
#include <string>
#include <chrono>
#include "Console.h"
#include "Line.h"
#include "Utils.h"
#include <iostream>

using namespace std;
using namespace std::chrono;

void AppManager::getValuesFromUser() {
    frequency = AppManager::getIntFromUser("Введите частоту");
    lineSpeed = AppManager::getIntFromUser("Введите скорость линии");
    lineLength = AppManager::getIntFromUser("Введите длину линии");
    isEpilepsy = AppManager::getIsEpilepsyFromUser();
}

int AppManager::getIntFromUser(string str, int min, int max) {
    string inputStr;
    printf("Значение должно быть от %d то %d. %s:", min, max, str.c_str());
    cin >> inputStr;
    while (!Utils::isNum(inputStr)) {
        printf("Значение должно быть ЧИСЛОМ от %d то %d. %s:", min, max, str.c_str());
        cin >> inputStr;
    }
    int num = stoi(inputStr);
    while (num < min || num > max) {
        printf("Неверное значение! Значение должно быть от %d то %d, %s:", min, max, str.c_str());
        scanf("%d", &num);
    }
    return num;
}

bool AppManager::getIsEpilepsyFromUser() {
    printf("Включить режим эпилепсии? (y/n): ");
    int sym = getchar();
    while (sym != 121 && sym != 110 && sym != 89 && sym != 78) {
        printf("Неверное значение! Ввведите y или n, Включить режим эпилепсии? (y/n): ");
        sym = getchar();
    }
    if (sym == 121 || sym == 89) return true;
    return false;
}

// todo: decompose function, realise function, which create line and push to the arr

void AppManager::run() const {
    long long lastDrawSymbol = duration_cast<milliseconds>(
            system_clock::now().time_since_epoch()).count();
    long long lastStartLinesTime = lastDrawSymbol;
    vector<int> timeIntervals = {};
    vector<Line *> lines = {};


    for (int i = 1; i <= frequency; ++i) {
        timeIntervals.push_back(Utils::getRandomIntInRange(0, 999));
    }
    while (true) {
        long long currentTime = duration_cast<milliseconds>(
                system_clock::now().time_since_epoch()).count();

        // todo: combine add interval and createLine
        if (currentTime - lastStartLinesTime >= 1000) {
            timeIntervals.clear();
            for (int i = 1; i <= frequency; ++i) {
                timeIntervals.push_back(Utils::getRandomIntInRange(0, 999));
            }
            lastStartLinesTime = currentTime;
        }

        for (int i = 0; i < timeIntervals.size(); ++i) {
            if (currentTime - lastStartLinesTime >= long(timeIntervals[i])) {
                Line *line = new Line(Utils::getRandomIntInRange(1, maxX), maxY, currentTime, lineLength,
                                      !isEpilepsy ? GREEN : Utils::getRandomColor());
                lines.push_back(line);
                timeIntervals.erase(timeIntervals.begin() + i);
            }
        }

        for (int i = 0; i < lines.size(); ++i) {
            if (currentTime - lines[i]->lastPrintTime >= drawLineInterval) {
                lines[i]->move();
                if (lines[i]->completed) {
                    delete lines[i];
                    lines.erase(lines.begin() + i);
                }
                lines[i]->lastPrintTime = currentTime;
            }
        }
    }
}

void AppManager::init() {
    getValuesFromUser();
    drawLineInterval = 1000 / lineSpeed;
    Console::getMaxXY(&maxX, &maxY);
    Console::clearConsole();
}