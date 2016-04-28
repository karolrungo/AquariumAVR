/*
 * MessageTypes.h
 *
 *  Created on: 25 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_MESSAGETYPES_H_
#define COMMUNICATION_MESSAGETYPES_H_

typedef enum MessageType
{
	MSG_LCD_BACKGROUND,
	MSG_DS18B20_TEMPERATURE_REQ
} MessageType;

static inline char* msgType2String(enum MessageType p_msgType)
{
    static char *strings[] = {
			"MSG_LCD_BACKGROUND",
			"MSG_DS18B20_TEMPERATURE_REQ"
    };

    return strings[p_msgType];
}


#endif /* COMMUNICATION_MESSAGETYPES_H_ */
