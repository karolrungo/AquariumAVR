#ifndef TIMER_MANAGER_H_
#define TIMER_MANAGER_H_

#include <stdint.h>
#include <stdbool.h>

typedef uint16_t Miliseconds;
typedef uint8_t TimerID;

#define TIMERS_NUMBER 8

typedef struct Timer
{
	bool m_isRunning;
	bool m_isOneShot;
	uint16_t m_latency;
	void(*m_callback)(void);
} Timer;

void initSoftwareTimers();
bool registerTimer(const Miliseconds p_miliseconds, void(*p_callback)(void));
void softwareTimersEvents();

#endif
