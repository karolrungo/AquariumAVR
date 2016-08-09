/*
 * Temperature.h
 *
 *  Created on: 31 maj 2016
 *      Author: Karol
 */

#ifndef AQUARIUMDATA_TEMPERATURE_H_
#define AQUARIUMDATA_TEMPERATURE_H_

typedef struct Temperature
{
	uint8_t temperature;
	uint8_t temperature_fract_bits;
	uint8_t subzero;
} Temperature;

#endif /* AQUARIUMDATA_TEMPERATURE_H_ */
