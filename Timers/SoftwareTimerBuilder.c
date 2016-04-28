/*
 * SoftwareTimerBuilder.c
 *
 *  Created on: 28 kwi 2016
 *      Author: Karol
 */

#include "SoftwareTimerBuilder.h"

#include <stdbool.h>

Timer buildOneShotTimer(Miliseconds p_miliseconds, Callback p_callback)
{
	Timer l_timer;
	l_timer.isRunning = true;
	l_timer.isOneShot = true;
	l_timer.latency = p_miliseconds;
	l_timer.timeLeft = l_timer.latency;
	l_timer.callback = p_callback;
	return l_timer;
}

Timer buildPeriodicalTimer(Miliseconds p_miliseconds, Callback p_callback)
{
	Timer l_timer;
	l_timer.isRunning = true;
	l_timer.isOneShot = false;
	l_timer.latency = p_miliseconds;
	l_timer.timeLeft = l_timer.latency;
	l_timer.callback = p_callback;
	return l_timer;
}
