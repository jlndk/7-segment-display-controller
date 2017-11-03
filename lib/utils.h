int * intToDigits(int num)
{
    int numCount = 1;

    int number = num;

    while(number /= 10) {
        numCount++;
    }

    static int digits[4] = {-1, -1, -1, -1};

    for(int i = 0; i < numCount; i++){
        digits[3-i] = num % 10;
        num /= 10;
    }

    return digits;
}


#if IS_DEBUG
    void delay(int amount)
    {
        int num = amount * 1000;

        // Stroing start time
        clock_t start_time = clock();

        // looping till required time is not acheived
        while (clock() < start_time + num);
    }
#else
    void delay(int amount) {
        _delay_ms(MAIN_DELAY);
    }
#endif
