/*
 * SoftwareTimerBuilder.h
 *
 *  Created on: 28 kwi 2016
 *      Author: Karol
 */

#ifndef TIMERS_SOFTWARETIMERBUILDER_H_
#define TIMERS_SOFTWARETIMERBUILDER_H_

#include "SoftwareTimer.h"

Timer buildOneShotTimer(Miliseconds p_miliseconds, Callback p_callback);
Timer buildPeriodicalTimer(Miliseconds p_miliseconds, Callback p_callback);

#endif /* TIMERS_SOFTWARETIMERBUILDER_H_ */
