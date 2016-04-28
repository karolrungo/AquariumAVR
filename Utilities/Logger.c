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

//#define DEBUG_LOGS_ENABLED
#define INFO_LOGS_ENABLED

#define MAX_MESSAGE_LEN 128

static char g_message[MAX_MESSAGE_LEN];

void LOG_init()
{
	USART_Init(__UBRR);
}

void LOG_INFO(const char* format, ...)
{
#ifdef INFO_LOGS_ENABLED
	va_list args;
	va_start(args,format);
	vsprintf(g_message, format, args);
	strcat(g_message, "\n\r");
	uart_puts(g_message);
	va_end(args);
#endif
}

void LOG_DEBUG(const char* format, ...)
{
#ifdef DEBUG_LOGS_ENABLED
	va_list args;
	va_start(args,format);
	vsprintf(g_message, format, args);
	strcat(g_message, "\n\r");
	uart_puts(g_message);
	va_end(args);
#endif
}
