/*
 * TimerManager.c

 *
 *  Created on: 2 mar 2016
 *      Author: Karol
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>
#include <stdbool.h>

#include "TimerManager.h"
#include "../Utilities/Logger.h"
#include "../Utilities/Int2Bin.h"

static Timer g_timersPool [TIMERS_NUMBER];
static TimerID NO_FREE_ID = -1;

static void initTimer0_10ms_ctc();
static TimerID getFirstFreeTimerInPool();
static void logTimerData(const TimerID p_timerId);
static bool timerShoulBeStopped(const TimerID p_timerId);
static void handleTimerCallback(const TimerID p_timerId);
static void restartTimer(const TimerID p_timerId);

void initSoftwareTimers()
{
	LOG_Line("Programmable timers initialization started");
	initTimer0_10ms_ctc();

	LOG_Line("Timers pool initialization:");
	for(uint8_t id = 0; id< TIMERS_NUMBER; ++id)
	{
		g_timersPool[id] = (Timer){false, false, 0, 0, NULL};
		logTimerData(id);
	}
	LOG_Line("Timers pool initialization finished");
	LOG_Line("Programmable timers initialization finished");
}
static void initTimer0_10ms_ctc()
{
	// TIMER 0 - 8bit
	TCCR0 |= (1<<WGM01); //tryb ctc
	TCCR0 |= (1<<CS02) | (1<<CS00); //prescaler = 1024
	OCR0 = 78;
	TIMSK |= (1<<OCIE0);

	LOG_Line("Timer0 configuration");
	LOG_Line("TCCR0= %s, OCR0= %s, TIMSK= %s",
			int2bin(TCCR0), int2bin(OCR0), int2bin(TIMSK));
}

bool registerTimer(const Miliseconds p_miliseconds, Callback p_callback)
{
	TimerID l_TimerId = getFirstFreeTimerInPool();
	if(l_TimerId == NO_FREE_ID)
	{
		LOG_Line("ERROR. No free id for timner. Timer not started!");
		return false;
	}

	g_timersPool[l_TimerId].m_isRunning = true;
	g_timersPool[l_TimerId].m_isOneShot = false;
	g_timersPool[l_TimerId].m_latency = p_miliseconds;
	g_timersPool[l_TimerId].m_timeLeft = g_timersPool[l_TimerId].m_latency / 10;
	g_timersPool[l_TimerId].m_callback = p_callback;
	logTimerData(l_TimerId);

	return true;
}

void softwareTimersEvents(void)
{
	for(TimerID id=0; id<TIMERS_NUMBER; ++id)
	{
		if(timerShoulBeStopped(id))
		{
			handleTimerCallback(id);
			g_timersPool[id].m_isRunning = false;
			restartTimer(id);
		}
	}
}

static TimerID getFirstFreeTimerInPool(void)
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

static void logTimerData(const TimerID p_timerId)
{
	LOG_Line("Timer[%d]: running= %d, oneShot= %d, latency= %d[ms], timeLeft= %d[ms], callback= %x",
			p_timerId,
			g_timersPool[p_timerId].m_isRunning,
			g_timersPool[p_timerId].m_isOneShot,
			g_timersPool[p_timerId].m_latency,
			g_timersPool[p_timerId].m_timeLeft,
			g_timersPool[p_timerId].m_callback);
}

static bool timerShoulBeStopped(const TimerID p_timerId)
{
	return !g_timersPool[p_timerId].m_timeLeft &&
			g_timersPool[p_timerId].m_isRunning;
}

static void handleTimerCallback(const TimerID p_timerId)
{
	if(g_timersPool[p_timerId].m_callback)
	{
		g_timersPool[p_timerId].m_callback();
	}
}

static void restartTimer(const TimerID p_timerId)
{
	if(!g_timersPool[p_timerId].m_isOneShot)
	{
		g_timersPool[p_timerId].m_isRunning = true;
		g_timersPool[p_timerId].m_timeLeft = g_timersPool[p_timerId].m_latency / 10;
		//logTimerData(p_timerId);
	}
}

ISR(TIMER0_COMP_vect)
{
	Miliseconds l_timeLeft;

	for(TimerID id=0; id<TIMERS_NUMBER; ++id)
	{
		l_timeLeft = g_timersPool[id].m_timeLeft;
	    if (l_timeLeft)
	    {
			g_timersPool[id].m_timeLeft = --l_timeLeft;
	    }
	}
}

