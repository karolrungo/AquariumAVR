/*
 * 1WireService.c
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */

#include "1WireService.h"
#include "ds18x20.h"

#include "../Utilities/Logger.h"
#include "../AquariumData/AquariumData.h"
#include "../Timers/SoftwareTimer.h"

static void readMeasuredData();

void handleDS18B20_TemperatureRequest(MessageData p_msgData)
{
	LOG_Line("handling DS18B20_TemperatureRequest");
	search_sensors();
	DS18X20_start_meas(DS18X20_POWER_EXTERN, NULL);
	registerOneShotTimer(1000, &readMeasuredData);
}

void readMeasuredData()
{
	LOG_Line("Reading temperature from DS18B20");
	DS18X20_read_meas(gSensorIDs[0], &subzero, &temperature, &temperature_fract_bits);
}
