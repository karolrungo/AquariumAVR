#ifndef TIMER_MANAGER_H_
#define TIMER_MANAGER_H_

#include <stdint.h>
#include <stdbool.h>

#define TIMERS_NUMBER 8

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

void initSoftwareTimers(void);
bool registerTimer(const Miliseconds p_miliseconds, Callback p_callback);
void softwareTimersEvents(void);

#endif
