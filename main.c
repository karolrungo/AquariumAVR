/*
 * main.c
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#ifndef MAIN_C_
#define MAIN_C_

#include <avr/interrupt.h>

#include "TimerManager/TimerManager.h"
#include "LED_SERVICE/led.h"
#include "LCD/lcd44780.h"
#include "Utilities/Logger.h"
#include "1Wire/ds18x20.h"


#include <avr/delay.h>



int main(void)
{
	sei(); //enable global interrupts
	LOG_init();


	LOG_Line("LCD initialization started");
	lcd_init();
	LOG_Line("LCD initialization finished");

	LOG_Line("Programmable timers initialization started");
	initProgrammableTimers();
	LOG_Line("Programmable timers initialization finished");

	setAlarmLedAsOutput();
	setAlarmLedOff();

	lcd_backgroundLedOn();

	while(1)
	{
		//uart_puts("DUPA");
	}
return 0;
}


#endif /* MAIN_C_ */
