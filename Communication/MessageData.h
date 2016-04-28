/*
 * MessageData.h
 *
 *  Created on: 25 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGEDATA_H_
#define COMMUNICATION_MESSAGEDATA_H_

#include <avr/io.h>

#include "Messages/LcdBackground.h"
#include "Messages/DS18B20_Temperature.h"

//put messages in this union
typedef union MessageData
{
	LcdBackround lcdBackground;
	uint8_t ds1820SensorNumber;
	DS18B20_Temperature dS18B20_Temperature;
} MessageData;

#endif /* COMMUNICATION_MESSAGEDATA_H_ */
