/*
 * AquariumData.h
 *
 *  Created on: 28 kwi 2016
 *      Author: Karol
 */

#ifndef AQUARIUMDATA_AQUARIUMDATA_H_
#define AQUARIUMDATA_AQUARIUMDATA_H_

#include <avr/io.h>

#include "Temperature.h"

#define MAX_SENSOR_NUMBER 4

Temperature temperature[MAX_SENSOR_NUMBER];

#endif /* AQUARIUMDATA_AQUARIUMDATA_H_ */
