/*
 * Lab3_definitions.c
 *
 *  Created on: 13 janv. 2023
 *      Author: Ahmed
 */

#include <stdio.h>
#include "Lab3_definitions.h"

void write_register(alt_16 x,int value) {
	   I2C_start(I2C_BASE, 0x1D, 0);
	   I2C_write(I2C_BASE, x, 0);
	    I2C_write(I2C_BASE, value, 1);
}


alt_16 read_register(alt_16 x) {
	 I2C_start(I2C_BASE, 0x1D, 0);
		    I2C_write(I2C_BASE, x, 0);
	   I2C_start(I2C_BASE, 0x1D, 1);
	   return I2C_read(I2C_BASE, 1);

}
