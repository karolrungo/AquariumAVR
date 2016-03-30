/*
 * Logger.c
 *
 *  Created on: 3 mar 2016
 *      Author: Karol
 */
#include <stdio.h>
#include <stdlib.h>

#include "../UART/uart.h"
#include "Logger.h"

#define MAX_MESSAGE_LEN 128
#define MAX_INTEGER_BITS 8

static char g_integer_buffer[MAX_INTEGER_BITS];
static char g_message[MAX_MESSAGE_LEN];

void LOG_init()
{
	USART_Init(__UBRR);
}

void LOG_RegisterValue(const char* p_registerName, uint8_t p_registerValue)
{
	itoa(p_registerValue, g_integer_buffer, 2);
	sprintf(g_message, "%s= 0b%s\r\n", p_registerName, g_integer_buffer);
	uart_puts(&g_message[0]);
}

void LOG_Line(const char* p_line)
{
	sprintf(g_message, "%s\r\n", p_line);
	uart_puts(&g_message[0]);
}

void LOG_LineWithValue(const char* p_line, uint16_t p_value)
{
	itoa(p_value, g_integer_buffer, 10);
	sprintf(g_message, "%s= %s\r\n", p_line, g_integer_buffer);
	uart_puts(&g_message[0]);
}

