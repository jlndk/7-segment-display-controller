#include <stdio.h>
#include <time.h>

#define IS_DEBUG 1

int PORTA = 0;
int PORTB = 0;
int PORTC = 0;
int PORTD = 0;

int DDRA = 0;
int DDRB = 0;
int DDRC = 0;
int DDRD = 0;

/**
 * Simulates AVR environment
 */
void handleDebug() {
    system("clear");
    printf("PORTC: %d ", PORTC);
    printf("PORTD: %d\n", PORTD);
}
