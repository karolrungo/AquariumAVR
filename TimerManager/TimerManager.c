/*
 * TimerManager.c

 *
 *  Created on: 2 mar 2016
 *      Author: Karol
 */
#include <avr/io.h>

#include "TimerManager.h"
#include "../Utilities/Logger.h"
#include <avr/interrupt.h>

Timer g_timersPool [TIMERS_NUMBER];

void initProgrammableTimers()
{
	initTimer0_10ms_ctc();

	uart_puts("Timers pool initialization: isRunning= false, isPeriodic= false, latency= 0ms\r\n");
	for(uint8_t i = 0; i< TIMERS_NUMBER; ++i)
	{
		g_timersPool[i] = (Timer){false, false, 0};
	}
	uart_puts("Timers pool initialization finished\r\n");
}
void initTimer0_10ms_ctc()
{
	// TIMER 0 - 8bit
	TCCR0 |= (1<<WGM01); //tryb ctc
	TCCR0 |= (1<<CS02) | (1<<CS00); //prescaler = 1024
	OCR0 = 78;
	TIMSK |= (1<<OCIE0);


	uart_puts("Timer0 configuration\r\n");
	LOG_RegisterValue("TCCR0", TCCR0);
	LOG_RegisterValue("OCR0", OCR0);
	LOG_RegisterValue("TIMSK", TIMSK);
}

ISR(TIMER0_COMP_vect)
{
 static int dupa;
}

