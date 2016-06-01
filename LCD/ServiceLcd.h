/*
 * ServiceLcd.h
 *
 *  Created on: 25 kwi 2016
 *      Author: Karol
 */

#ifndef LCD_SERVICE_H_
#define LCD_SERVICE_H_

#include "../Communication/MessageData.h"

void initLcd();
void handleLcdBackground(const MessageData p_msgData);
void handleLcdDisplayTemperature();

#endif /* LCD_SERVICE_H_ */
