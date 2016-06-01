/*
 * 1WireService.c
 *
 *  Created on: 26 kwi 2016
 *      Author: Karol
 */

#include "1WireService.h"
#include "ds18x20.h"

#include "../Utilities/Logger.h"
#include "../Utilities/Queue.h"
#include "../AquariumData/AquariumData.h"
#include "../Timers/SoftwareTimer.h"

static void readMeasuredData();

void handleDS18B20_TemperatureRequest(MessageData p_msgData)
{
	LOG_INFO("Handling DS18B20_TemperatureRequest, sensorNumber= %d", p_msgData.ds1820SensorNumber);

	Enqueue(p_msgData.ds1820SensorNumber);
	search_sensors();

	DS18X20_start_meas(DS18X20_POWER_EXTERN, NULL);
	registerOneShotTimer(1000, &readMeasuredData);
}

void readMeasuredData()
{
	while(!isEmpty())
	{
	uint8_t g_sensorNumber = Front();
	Dequeue();
	LOG_INFO("Reading temperature from DS18B20 number = %d", g_sensorNumber);
	DS18X20_read_meas(gSensorIDs[g_sensorNumber],
					  &temperature[g_sensorNumber].subzero,
					  &temperature[g_sensorNumber].temperature,
					  &temperature[g_sensorNumber].temperature_fract_bits);
	}

}
