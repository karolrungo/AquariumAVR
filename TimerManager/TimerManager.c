/*
 * TimerManager.c

 *
 *  Created on: 2 mar 2016
 *      Author: Karol
 */

#include <avr/interrupt.h>
#include <stddef.h>
#include <stdbool.h>

#include "TimerManager.h"
#include "../Utilities/Logger.h"
#include "../Utilities/Int2Bin.h"

static volatile  Timer g_timersPool [TIMERS_NUMBER];
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
		g_timersPool[id] = (Timer){false, true, 0, 0, NULL};
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
	OCR0 = 78; //8 000 000 / 1024 / 78 = 100Hz = 10ms
	TIMSK |= (1<<OCIE0);

	LOG_Line("Timer0 configuration");
	LOG_Line("TCCR0= %s, OCR0= %s, TIMSK= %s",
			int2bin(TCCR0), int2bin(OCR0), int2bin(TIMSK));
}

bool registerTimer(const Miliseconds p_miliseconds, Callback p_callback)
{
	if(p_miliseconds <= 0)
	{
		LOG_Line("ERROR. Latency should be greater than 0. Timer not started!");
		return false;
	}

	TimerID l_TimerId = getFirstFreeTimerInPool();
	if(l_TimerId == NO_FREE_ID)
	{
		LOG_Line("ERROR. No free id for timner. Timer not started!");
		return false;
	}

	g_timersPool[l_TimerId].isRunning = true;
	g_timersPool[l_TimerId].isOneShot = false;
	g_timersPool[l_TimerId].latency = p_miliseconds;
	g_timersPool[l_TimerId].timeLeft = g_timersPool[l_TimerId].latency;
	g_timersPool[l_TimerId].callback = p_callback;
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
			g_timersPool[id].isRunning = false;
			restartTimer(id);
		}
	}
}

static TimerID getFirstFreeTimerInPool(void)
{
	for(TimerID i=0; i<TIMERS_NUMBER; ++i)
	{
		if(!g_timersPool[i].isRunning)
		{
			return i;
		}
	}
	return NO_FREE_ID;
}

static void logTimerData(const TimerID p_timerId)
{
	LOG_Line("Timer[%d]: running=%d, oneShot=%d, latency=%d[ms], "
			"timeLeft=%d, callback=%x",
			p_timerId,
			g_timersPool[p_timerId].isRunning,
			g_timersPool[p_timerId].isOneShot,
			g_timersPool[p_timerId].latency,
			g_timersPool[p_timerId].timeLeft,
			g_timersPool[p_timerId].callback);
}

static bool timerShoulBeStopped(const TimerID p_timerId)
{
	return  g_timersPool[p_timerId].timeLeft < 0 &&
			g_timersPool[p_timerId].isRunning;
}

static void handleTimerCallback(const TimerID p_timerId)
{
	if(g_timersPool[p_timerId].callback)
	{
		g_timersPool[p_timerId].callback();
	}
}

static void restartTimer(const TimerID p_timerId)
{
	if(!g_timersPool[p_timerId].isOneShot)
	{
		g_timersPool[p_timerId].isRunning = true;
		g_timersPool[p_timerId].timeLeft = g_timersPool[p_timerId].latency;
		logTimerData(p_timerId);
	}
}

ISR(TIMER0_COMP_vect)
{
	for(TimerID id=0; id<TIMERS_NUMBER; ++id)
	{
	    if (g_timersPool[id].timeLeft >= 0)
	    {
	    	//interrupt occurs every 10ms so substract 10
			g_timersPool[id].timeLeft -= 10;
	    }
	}
}
