/*
 * PinDefinitions.h
 *
 *  Created on: 30 mar 2016
 *      Author: Karol
 */

#ifndef UTILITIES_PINDEFINITIONS_H_
#define UTILITIES_PINDEFINITIONS_H_

////// 1-WIRE //////////
#define OW_PIN  PD5
#define OW_IN   PIND
#define OW_OUT  PORTD
#define OW_DDR  DDRD
////////////////////////

////////////// LCD /////////////
#define LCD_D7PORT  B
#define LCD_D7 0
#define LCD_D6PORT  B
#define LCD_D6 1
#define LCD_D5PORT  B
#define LCD_D5 2
#define LCD_D4PORT  B
#define LCD_D4 3

#define LCD_RSPORT B
#define LCD_RS 4

#define LCD_RWPORT B
#define LCD_RW 5
#define LCD_EPORT B
#define LCD_E 6
#define LCD_BACKGROUNDPORT B
#define LCD_BL 7
//////////////////////////////

//////////// LEDs /////////////
#define LED_ALARM_DIR DDRD
#define LED_ALARM_PORT PORTD
#define LED_ALARM PD7
//////////////////////////////

#endif /* UTILITIES_PINDEFINITIONS_H_ */
