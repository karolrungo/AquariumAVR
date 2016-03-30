/*
 * TimerManager.c

 *
 *  Created on: 2 mar 2016
 *      Author: Karol
 */
#include <avr/io.h>
#include <avr/interrupt.h>

#include "TimerManager.h"
#include "../Utilities/Logger.h"

Timer g_timersPool [TIMERS_NUMBER];

static TimerID NO_FREE_ID= -1;

void initProgrammableTimers()
{
	LOG_Line("Programmable timers initialization started");
	initTimer0_10ms_ctc();

	LOG_Line("Timers pool initialization: isRunning= false, isPeriodic= false, latency= 0ms");
	for(uint8_t i = 0; i< TIMERS_NUMBER; ++i)
	{
		g_timersPool[i] = (Timer){false, false, 0};
	}
	LOG_Line("Timers pool initialization finished");
	LOG_Line("Programmable timers initialization finished");
}
void initTimer0_10ms_ctc()
{
	// TIMER 0 - 8bit
	TCCR0 |= (1<<WGM01); //tryb ctc
	TCCR0 |= (1<<CS02) | (1<<CS00); //prescaler = 1024
	OCR0 = 78;
	TIMSK |= (1<<OCIE0);

	LOG_Line("Timer0 configuration");
	LOG_RegisterValue("TCCR0", TCCR0);
	LOG_RegisterValue("OCR0", OCR0);
	LOG_RegisterValue("TIMSK", TIMSK);
}

bool registerTimer(const Miliseconds p_miliseconds)
{
	TimerID l_TimerId = getFirstFreeTimerInPool();
	if(l_TimerId == NO_FREE_ID)
	{
		LOG_Line("ERROR. No free id for timner. Timer not started!");
		return false;
	}

	LOG_LineWithValue("Timer registered with id", l_TimerId);
	LOG_LineWithValue("Timer latency in miliseconds", p_miliseconds);
	g_timersPool[l_TimerId].m_isRunning = true;
	g_timersPool[l_TimerId].m_isOneShot = false;
	g_timersPool[l_TimerId].m_latency = setLatency(p_miliseconds);

	return true;
}

TimerID getFirstFreeTimerInPool()
{
	for(TimerID i=0; i<TIMERS_NUMBER; ++i)
	{
		if(!g_timersPool[i].m_isRunning)
		{
			return i;
		}
	}
	return NO_FREE_ID;
}

const Miliseconds setLatency(const Miliseconds p_miliseconds)
{
	//timer tick everys 10ms so division by 10 needed
	return p_miliseconds / 10;
}

void SoftwareTimerEvents()
{
	if(!g_timersPool[0].m_latency && g_timersPool[0].m_isRunning)
	{
		LOG_Line("tryklo!");

		g_timersPool[0].m_isRunning = false;
	}
}

ISR(TIMER0_COMP_vect)
{
	Miliseconds l_timeLeft;

	l_timeLeft = g_timersPool[0].m_latency;
    if (l_timeLeft)g_timersPool[0].m_latency = --l_timeLeft;
}

