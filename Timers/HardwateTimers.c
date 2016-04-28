#include <avr/io.h>

#include "../Timers/HardwareTimers.h"
#include "../Utilities/Logger.h"
#include "../Utilities/Int2Bin.h"

void Timer0_init_10ms_ctc()
{
	// TIMER 0 - 8bit
	TCCR0 |= (1<<WGM01); //tryb ctc
	TCCR0 |= (1<<CS02) | (1<<CS00); //prescaler = 1024
	OCR0 = 78; //8 000 000 / 1024 / 78 = 100Hz = 10ms
	TIMSK |= (1<<OCIE0);

	LOG_DEBUG("Timer0 configuration");
	LOG_DEBUG("TCCR0= %s, OCR0= %s, TIMSK= %s",
			int2bin(TCCR0), int2bin(OCR0), int2bin(TIMSK));
}
