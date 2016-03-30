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

	lcd_init();
	initProgrammableTimers();

	setAlarmLedAsOutput();
	setAlarmLedOff();

	registerTimer(3000);



	while(1)
	{
		uint8_t ile = search_sensors();
		lcd_int(ile);
		SoftwareTimerEvents();
		//uart_puts("Ile czujnikow: ");
	//	uart_putint(ile,10);
	//	uart_puts("\r\n");
	}
return 0;
}


#endif /* MAIN_C_ */
