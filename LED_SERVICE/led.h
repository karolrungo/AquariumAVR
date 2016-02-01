/*
 * led.h
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#ifndef LED_SERVICE_LED_H_
#define LED_SERVICE_LED_H_

#include <avr/io.h>

#define LED_ALARM_DIR DDRD
#define LED_ALARM_PORT PORTD
#define LED_ALARM PD7

void setAlarmLedAsOutput();
void setAlarmLedOn();
void setAlarmLedOff();

#endif /* LED_SERVICE_LED_H_ */
