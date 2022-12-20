#include "Symbol.h"
#include "Console.h"

using namespace std;

void Symbol::print(char content, int x, int y) {
    Console::moveCursor(x, y);
    printf("%c", content);
    fflush(stdout);
}