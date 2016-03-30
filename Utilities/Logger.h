/*
 * Logger.h
 *
 *  Created on: 3 mar 2016
 *      Author: Karol
 */

#ifndef UTILITIES_LOGGER_H_
#define UTILITIES_LOGGER_H_

#include <stdint.h>

void LOG_init();
void LOG_RegisterValue(const char* p_registerName, uint8_t p_registerValue);
void LOG_Line(const char* p_line);
void LOG_LineWithValue(const char* p_line, uint16_t p_value);

#endif /* UTILITIES_LOGGER_H_ */
