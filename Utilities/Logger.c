/*
 * Logger.c
 *
 *  Created on: 3 mar 2016
 *      Author: Karol
 */
#include <stdio.h>
#include <string.h>

#include "../UART/uart.h"
#include "Logger.h"

#define MAX_MESSAGE_LEN 128

static char g_message[MAX_MESSAGE_LEN];

void LOG_init()
{
	USART_Init(__UBRR);
}

void LOG_Line(const char* format, ...)
{
	va_list args;
	va_start(args,format);
	// What if message will be longer that buffer size?
	vsprintf(g_message, format, args);
	strcat(g_message, "\n\r");
	uart_puts(g_message);
	va_end(args);
}

