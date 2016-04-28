/*
 * Timer.h
 *
 *  Created on: 28 kwi 2016
 *      Author: Karol
 */

#ifndef TIMERS_TIMER_H_
#define TIMERS_TIMER_H_

#include <stdint.h>
#include <stdbool.h>

typedef int16_t Miliseconds;
typedef uint8_t TimerID;
typedef void(*Callback)(void);

typedef struct Timer
{
	bool isRunning;
	bool isOneShot;
	Miliseconds latency;
	Miliseconds timeLeft;
	void(*callback)(void);
} Timer;

#endif /* TIMERS_TIMER_H_ */
