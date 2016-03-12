#ifndef TIMER_MANAGER_H_
#define TIMER_MANAGER_H_

#include <stdint.h>
#include <stdbool.h>

#define TIMERS_NUMBER 8

typedef struct Timer
{
	bool m_isRunning;
	bool m_isOneShot;
	uint16_t m_latency;
} Timer;



void initProgrammableTimers();
void initTimer0_10ms_ctc();

#endif
