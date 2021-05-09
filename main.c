#include "menu/bus_menu.h"

int main() {
    if (!loadGlobalDatabase()) {
        return -1;
    }

    mainMenu();
    return 0;
}