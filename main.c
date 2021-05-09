#include <stdio.h>

#include "bus_menu.h"

int main() {
    //TIME time_tester = createTime(12, 30);

    /*time_tester.hour = 12;
    time_tester.minute = 30;

    time_tester.full_time = convertHMToFT(time_tester.hour, time_tester.minute);
    convertFTToHM(time_tester.full_time, &time_tester.hour, &time_tester.minute);
    strcpy(time_tester.time_str, convertHMToStr(time_tester.hour, time_tester.minute));
    convertStrToHM(time_tester.time_str, &time_tester.hour, &time_tester.minute);*/

    if (!loadGlobalDatabase()) {
        return -1;
    }

    mainMenu();

    return 0;
}
