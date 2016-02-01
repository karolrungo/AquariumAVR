/*
 * main.c
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#include <avr/delay.h>
#include "LED_SERVICE/led.h"

#ifndef MAIN_C_
#define MAIN_C_



int main(void)
{
	setAlarmLedAsOutput();

	while(1)
	{
		_delay_ms(500);
		setAlarmLedOn();
		_delay_ms(500);
		setAlarmLedOff();
	}
return 0;
}

#endif /* MAIN_C_ */
