/*
 * Service.c
 *
 *  Created on: 9 sie 2016
 *      Author: Karol
 */
#include <avr/io.h>

#include "Service.h"
#include "ir_decode.h"
#include "../Utilities/Logger.h"

#include "../Communication/MessageRouter.h"
#include "../Communication/MessageBuilder.h"

///////////////////
#include "../LCD/lcd44780.h"

static void handleFrameCommand(uint8_t p_command);

void irKeyEvents()
{
	if(Ir_key_press_flag) /* jeœli odebrano prawid³owe kody z pilota */
	{
		if( address ) //rozpoznano kod klawisza
		{
			handleFrameCommand(command);
		}
	/* wyzerowanie flagi odbioru oraz wartoœci odebranych kodów */
	Ir_key_press_flag=0;
	command=0xff;
	address=0xff;
	}
}

void handleFrameCommand(uint8_t p_command)
{
	LOG_DEBUG("IR key pressed: %d", p_command);
	LcdBackround zmienna;
	zmienna.lcdBackground = LCD_TOGGLE;
	switch(p_command)
	{
		case 12: //czerwny przycisk

			sendMessage(IR_Service, buildMessageLcdBackground(zmienna));
		break;
		case 1:
			//sendMessage(IR_Service, buildMessageLcdBackground(true));
		break;
		default:
			LOG_DEBUG("No handler for IR key:", p_command);
	}
}
