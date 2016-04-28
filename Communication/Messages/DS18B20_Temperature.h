/*
 * DS18B20_Temperature.h
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGES_DS18B20_TEMPERATURE_H_
#define COMMUNICATION_MESSAGES_DS18B20_TEMPERATURE_H_

#include <avr/io.h>

typedef struct DS18B20_Temperature
{
	uint8_t m_sensorNumber;
	uint8_t temperature;
	uint8_t temperature_fract_bits;

}DS18B20_Temperature;

#endif /* COMMUNICATION_MESSAGES_DS18B20_TEMPERATURE_H_ */
