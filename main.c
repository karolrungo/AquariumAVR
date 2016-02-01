/*
 * main.c
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#include <avr/delay.h>
#include "LED_SERVICE/led.h"
#include "LCD/lcd44780.h"

#ifndef MAIN_C_
#define MAIN_C_



int main(void)
{
	lcd_init();
	setAlarmLedAsOutput();

	while(1)
	{
		_delay_ms(500);
		setAlarmLedOn();
		lcd_backgroundLedOn();
		_delay_ms(500);
		setAlarmLedOff();
		lcd_backgroundLedOff();
	}
return 0;
}

#endif /* MAIN_C_ */
