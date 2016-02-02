/*
 * main.c
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#ifndef MAIN_C_
#define MAIN_C_

#include <avr/delay.h>
#include <avr/interrupt.h>

#include "LED_SERVICE/led.h"
#include "LCD/lcd44780.h"
#include "UART/uart.h"

int main(void)
{
	lcd_init();
	USART_Init(__UBRR);

	setAlarmLedAsOutput();

	lcd_backgroundLedOn();
	lcd_locate(0,0);
	lcd_str("Dzien dobry!");

	sei(); //enable global interrupts

	while(1)
	{
		uart_puts("Witaj swiecie!\r\n");
		setAlarmLedOff();
		_delay_ms(500);
		uart_puts("UART test\r\n");
		setAlarmLedOn();
		_delay_ms(500);
	}
return 0;
}

#endif /* MAIN_C_ */
