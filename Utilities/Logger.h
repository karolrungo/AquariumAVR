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
void LOG_INFO(const char* format, ...);
void LOG_DEBUG(const char* format, ...);

#endif /* UTILITIES_LOGGER_H_ */
