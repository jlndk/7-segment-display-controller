/*
The binary codes for the digits on the display.
Each code corresponds with it's position, such that 0 is at the zeroth position,
one is at the first position, and so on...
 */
const int digits[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

unsigned int currentDisplay = 0;
int *currentDigits;

/**
 * Displays a given digit to a given device
 * @param num    The digit that should be outputted. Can be between 0 and DISPLAYS_MAX_NUM.
 */
void set_display(int num){
    //Throw error
    if(num > DISPLAYS_MAX_NUM) {
        //@TODO: Display error code
        return;
    }
    currentDigits = intToDigits(num);
}

/**
 * Updates the actual displays based on the desired value from set_display
 */
void display_handle()
{
    //Bitshift register, so that the next display is chosen
    PORTD = 1<<currentDisplay;

    //If the desired display value for this screen is -1 we turn off the display
    if(currentDigits[currentDisplay] == -1) {
        PORTC = 0;
    }
    //.. otherwise we update the display
    else {
        PORTC = digits[currentDigits[currentDisplay]];
    }

    //Increment display counter
    currentDisplay++;

    //If the counter exceeds the amount of displays available we loop back to 0
    if(currentDisplay >= DISPLAYS_COUNT) {
        currentDisplay = 0;
    }
}
