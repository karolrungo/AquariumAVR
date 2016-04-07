#ifndef TIMER_MANAGER_H_
#define TIMER_MANAGER_H_

#include <stdint.h>
#include <stdbool.h>

#define TIMERS_NUMBER 8

typedef uint16_t Miliseconds;
typedef uint8_t TimerID;
typedef void(*Callback)(void);

typedef struct Timer
{
	bool m_isRunning;
	bool m_isOneShot;
	Miliseconds m_latency;
	Miliseconds m_timeLeft;
	void(*m_callback)(void);
} Timer;

void initSoftwareTimers(void);
bool registerTimer(const Miliseconds p_miliseconds, Callback p_callback);
void softwareTimersEvents(void);

#endif
