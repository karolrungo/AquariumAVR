/*
 * SoftwareTimerBuilder.c
 *
 *  Created on: 28 kwi 2016
 *      Author: Karol
 */

#include "SoftwareTimerBuilder.h"

#include <stdbool.h>

static Timer buildCommonPart(Miliseconds p_miliseconds, Callback p_callback);

Timer buildOneShotTimer(Miliseconds p_miliseconds, Callback p_callback)
{
	Timer l_timer = buildCommonPart(p_miliseconds, p_callback);
	l_timer.isOneShot = true;
	return l_timer;
}

Timer buildPeriodicalTimer(Miliseconds p_miliseconds, Callback p_callback)
{
	Timer l_timer = buildCommonPart(p_miliseconds, p_callback);
	l_timer.isOneShot = false;
	return l_timer;
}

Timer buildCommonPart(Miliseconds p_miliseconds, Callback p_callback)
{
	Timer l_timer;
	l_timer.isRunning = true;
	l_timer.latency = p_miliseconds;
	l_timer.timeLeft = l_timer.latency;
	l_timer.callback = p_callback;
	return l_timer;
}
