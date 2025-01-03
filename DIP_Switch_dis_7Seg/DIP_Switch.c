#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

const unsigned char seg_code[10] = {
    ~0x3F, // 0
    ~0x06, // 1
    ~0x5B, // 2
    ~0x4F, // 3
    ~0x66, // 4
    ~0x6D, // 5
    ~0x7D, // 6
    ~0x07, // 7
    ~0x7F, // 8
    ~0x6F  // 9
};

void display_number(unsigned char number) {
    unsigned char digit1 = number / 100;
    unsigned char digit2 = (number / 10) % 10;
    unsigned char digit3 = number % 10;



    PORTB = seg_code[digit1];
    PORTC = 0b00000001;
	 _delay_ms(1);
    PORTC = 0x00;

    PORTB = seg_code[digit2];
    PORTC = 0b00000010;
	 _delay_ms(1);
    PORTC = 0x00;

    PORTB = seg_code[digit3];
    PORTC = 0b00000100;
	 _delay_ms(1);
    PORTC = 0x00;
}

int main(void) {
    DDRA = 0x00;
    PORTA = 0xFF;
    DDRB = 0xFF;
    DDRC = 0xFF;

    while (1) {
        unsigned char value = ~PINA;
        display_number(value);
    }
}
