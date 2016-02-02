/*
 * main.c
 *
 *  Created on: 1 lut 2016
 *      Author: Karol
 */
#ifndef MAIN_C_
#define MAIN_C_

#include <avr/delay.h>
#include <avr/interrupt.h>

#include "LED_SERVICE/led.h"
#include "LCD/lcd44780.h"
#include "UART/uart.h"
#include "1Wire/ds18x20.h"

void display_temp(uint8_t x);

uint8_t subzero, cel, cel_fract_bits;

int main(void)
{
	lcd_init();
	USART_Init(__UBRR);

	setAlarmLedAsOutput();
	setAlarmLedOff();

	lcd_backgroundLedOn();
	lcd_locate(0,0);
	lcd_str("Dzien dobry!");

	sei(); //enable global interrupts

	search_sensors();
	DS18X20_start_meas( DS18X20_POWER_EXTERN, NULL );

	while(1)
	{
		DS18X20_start_meas( DS18X20_POWER_EXTERN, NULL );
		_delay_ms(1000);

		uart_puts("Witaj swiecie!\r\n");
		if( DS18X20_OK == DS18X20_read_meas(gSensorIDs[0], &subzero, &cel, &cel_fract_bits) )
		{
			display_temp(0);
		}

		DS18X20_start_meas( DS18X20_POWER_EXTERN, NULL );
		_delay_ms(1000);

		uart_puts("UART test\r\n");
		if( DS18X20_OK == DS18X20_read_meas(gSensorIDs[0], &subzero, &cel, &cel_fract_bits) )
		{
			display_temp(9);
		}
	}
return 0;
}

void display_temp(uint8_t x) {
	lcd_locate(1,x);
	if(subzero) lcd_str("-");	/* jeœli subzero==1 wyœwietla znak minus (temp. ujemna) */
	else lcd_str(" ");	/* jeœli subzero==0 wyœwietl spacjê zamiast znaku minus (temp. dodatnia) */
	lcd_int(cel);	/* wyœwietl dziesiêtne czêœci temperatury  */
	lcd_str(".");	/* wyœwietl kropkê */
	lcd_int(cel_fract_bits); /* wyœwietl dziesiêtne czêœci stopnia */
	lcd_str(" C "); /* wyœwietl znak jednostek (C - stopnie Celsiusza) */
}

#endif /* MAIN_C_ */
