/*
 * Int2bin.c
 *
 *  Created on: 4 kwi 2016
 *      Author: Karol
 */
#include "Int2Bin.h"

#include <string.h>
#include <stdint.h>

const char* int2bin(const int p_integer)
{
	static char l_binary[9];
	l_binary[0] = '\0';

    for (uint8_t i = 128; i > 0; i >>= 1)
    {
        strcat(l_binary, ((p_integer & i) == i) ? "1" : "0");
    }
    return l_binary;
}

