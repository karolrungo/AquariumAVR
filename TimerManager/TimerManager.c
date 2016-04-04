/*
 * TimerManager.c

 *
 *  Created on: 2 mar 2016
 *      Author: Karol
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>

#include "TimerManager.h"
#include "../Utilities/Logger.h"
#include "../Utilities/Int2Bin.h"

Timer g_timersPool [TIMERS_NUMBER];

static TimerID NO_FREE_ID = -1;

static void initTimer0_10ms_ctc();
static TimerID getFirstFreeTimerInPool();
static void logTimerData(const uint8_t p_timerId);
static const Miliseconds setLatency(const Miliseconds p_miliseconds);

void initSoftwareTimers()
{
	LOG_Line("Programmable timers initialization started");
	initTimer0_10ms_ctc();

	LOG_Line("Timers pool initialization:");
	for(uint8_t id = 0; id< TIMERS_NUMBER; ++id)
	{
		g_timersPool[id] = (Timer){false, false, 0, NULL};
		logTimerData(id);
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
	LOG_Line("TCCR0= %s", int2bin(TCCR0));
	LOG_Line("OCR0= %s", int2bin(OCR0));
	LOG_Line("TIMSK= %s", int2bin(TIMSK));
}

bool registerTimer(const Miliseconds p_miliseconds, void(*p_callback)(void))
{
	TimerID l_TimerId = getFirstFreeTimerInPool();
	if(l_TimerId == NO_FREE_ID)
	{
		LOG_Line("ERROR. No free id for timner. Timer not started!");
		return false;
	}

	g_timersPool[l_TimerId].m_isRunning = true;
	g_timersPool[l_TimerId].m_isOneShot = false;
	g_timersPool[l_TimerId].m_latency = setLatency(p_miliseconds);
	g_timersPool[l_TimerId].m_callback = p_callback;
	logTimerData(l_TimerId);

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

static const Miliseconds setLatency(const Miliseconds p_miliseconds)
{
	//timer tick everys 10ms so division by 10 needed
	return p_miliseconds / 10;
}

static void logTimerData(const uint8_t p_timerId)
{
	LOG_Line("Timer[%d]: isRunning= %d, isPeriodic= %d, latency= %d[ms], callback= %x",
			p_timerId,
			g_timersPool[p_timerId].m_isRunning,
			g_timersPool[p_timerId].m_isOneShot,
			g_timersPool[p_timerId].m_latency,
			g_timersPool[p_timerId].m_callback);
}

void softwareTimersEvents()
{
	if(!g_timersPool[0].m_latency && g_timersPool[0].m_isRunning)
	{
		LOG_Line("dupa!");
		g_timersPool[0].m_callback();
		g_timersPool[0].m_isRunning = false;
	}

	if(!g_timersPool[1].m_latency && g_timersPool[1].m_isRunning)
	{
		LOG_Line("dupa!");
		g_timersPool[1].m_callback();
		g_timersPool[1].m_isRunning = false;
	}

	if(!g_timersPool[2].m_latency && g_timersPool[2].m_isRunning)
	{
		LOG_Line("dupa!");
		g_timersPool[2].m_callback();
		g_timersPool[2].m_isRunning = false;
	}
}

ISR(TIMER0_COMP_vect)
{
	Miliseconds l_timeLeft;

	l_timeLeft = g_timersPool[0].m_latency;
    if (l_timeLeft)g_timersPool[0].m_latency = --l_timeLeft;

    l_timeLeft = g_timersPool[1].m_latency;
    if (l_timeLeft)g_timersPool[1].m_latency = --l_timeLeft;

    l_timeLeft = g_timersPool[2].m_latency;
    if (l_timeLeft)g_timersPool[2].m_latency = --l_timeLeft;
}

