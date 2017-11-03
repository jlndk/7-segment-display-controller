#include "lib/sim.h"

#if IS_DEBUG  == 0
    #include <avr/io.h>
    #include <util/delay.h>
#endif
#include "lib/utils.h"

//The amount of delay for each loop (in ms)
#define MAIN_DELAY 500

//The largest number that can be displayed on a display
#define DISPLAYS_MAX_NUM 9999

//The amount of displays conected
#define DISPLAYS_COUNT 4

//Because i'm lazy
#define true 1
#define false 0

//Define button ports
const int BUTTON_MODE_LIGHT = 0;
const int BUTTON_MODE_MOIST = 0;
const int BUTTON_MODE_TEMP = 0;

const int BUTTON_UP = 0;
const int BUTTON_DOWN = 0;

#include "lib/ui.h"
#include "lib/photoresistor.h"

/**
 * Prepares the processor and bootstraps the program
 */
void initialize () {
    /*
    Sets data direction for the registers (is the pins input or output).
    Each bit corresponds with a pin. 1 = output, 0 = input
     */
    DDRC = 0b11111111; //Register C (Pin 22-29) the 8 segments
    DDRD = 0b11110000; //Register D (Pin 14-21) the 4 displays

    set_display(0);
}

int main(void)
{
    //Prepare the processor before running
    initialize();

    while(true) {
        #if IS_DEBUG
        handleDebug();
        #endif

        //Handle ui
        ui_handle();

        //Handle displays
        display_handle();


        //Wait for some time
        delay(MAIN_DELAY);
    }
}
