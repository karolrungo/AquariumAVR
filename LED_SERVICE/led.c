/*
 * led.c
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#include "led.h"

void setAlarmLedAsOutput()
{
	LED_ALARM_DIR |= (1<<LED_ALARM);
}

void setAlarmLedOn()
{
	LED_ALARM_PORT &= ~(1<<LED_ALARM);
}

void setAlarmLedOff()
{
	LED_ALARM_PORT |= (1<<LED_ALARM);
}
