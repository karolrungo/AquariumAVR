/*
 * MessageData.h
 *
 *  Created on: 25 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGEDATA_H_
#define COMMUNICATION_MESSAGEDATA_H_

#include <avr/io.h>

typedef struct LcdBackround
{
	uint8_t isOn;
}LcdBackround;

typedef struct LcdText
{
	uint8_t isOn;
}LcdText;

typedef union MessageData
{
	LcdBackround lcdBackground;
	LcdText lcdText;

} MessageData;

#endif /* COMMUNICATION_MESSAGEDATA_H_ */
