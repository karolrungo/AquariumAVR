#ifndef TIMER_MANAGER_H_
#define TIMER_MANAGER_H_

#include "Timer.h"

void initSoftwareTimers(void);
bool registerOneShotTimer(const Miliseconds p_miliseconds, Callback p_callback);
bool registerPeriodicTimer(const Miliseconds p_miliseconds, Callback p_callback);
void softwareTimersEvents(void);

#endif
