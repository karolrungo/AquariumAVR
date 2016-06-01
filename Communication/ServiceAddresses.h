/*
 * ServiceAddresses.h
 *
 *  Created on: 20 kwi 2016
 *      Author: Karol
 */

#ifndef COMMUNICATION_SERVICEADDRESSES_H_
#define COMMUNICATION_SERVICEADDRESSES_H_

typedef enum ServiceAddress
{
	MAIN,
	LCD_Service,
	DS18B20_Service
} ServiceAddress;

static inline char* serviceAddressToString(enum ServiceAddress p_address)
{
	static char *strings[] = {
			"MAIN",
			"LCD_Service",
			"DS18B20_Service"
    };

    return strings[p_address];
}

#endif /* COMMUNICATION_SERVICEADDRESSES_H_ */
