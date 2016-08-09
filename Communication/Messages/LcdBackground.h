/*
 * LcdBackground.h
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGES_LCDBACKGROUND_H_
#define COMMUNICATION_MESSAGES_LCDBACKGROUND_H_

typedef struct LcdBackround
{
	enum ELcdBackround {LCD_OFF, LCD_ON, LCD_TOGGLE} lcdBackground;
}LcdBackround;

#endif /* COMMUNICATION_MESSAGES_LCDBACKGROUND_H_ */
