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

#define MAX_MESSAGE_LEN 64
#define MAX_INTEGER_BITS 8

void LOG_init()
{
	USART_Init(__UBRR);
}

void LOG_RegisterValue(const char* p_registerName, uint8_t p_registerValue)
{
	char l_integer_buffer[MAX_INTEGER_BITS];
	itoa(p_registerValue, l_integer_buffer, 2);

	char l_message[MAX_MESSAGE_LEN];
	sprintf(l_message, "%s= 0b%s\r\n", p_registerName, l_integer_buffer);
	uart_puts(&l_message[0]);
}

void LOG_Line(const char* p_line)
{
	char l_message[MAX_MESSAGE_LEN];
	sprintf(l_message, "%s\r\n", p_line);
	uart_puts(&l_message[0]);
}

