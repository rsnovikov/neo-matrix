// todo: fix warnings
#include "AppManager.h"

int main() {
    AppManager *appManager = new AppManager;
    appManager->init();
    appManager->run();
    return 0;
}

