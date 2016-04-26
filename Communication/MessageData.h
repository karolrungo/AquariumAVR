/*
 * MessageData.h
 *
 *  Created on: 25 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGEDATA_H_
#define COMMUNICATION_MESSAGEDATA_H_

#include "Messages/LcdBackground.h"

//put messages in this union
typedef union MessageData
{
	LcdBackround lcdBackground;
	//other structures
} MessageData;

#endif /* COMMUNICATION_MESSAGEDATA_H_ */
