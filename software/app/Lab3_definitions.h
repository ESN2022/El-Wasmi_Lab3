#include "system.h"
#include "alt_types.h"
#include "opencores_i2c.h"

// ADXL345 Register addresses
#define ADXL345_DATAX0 0x32
#define ADXL345_DATAX1 0x33
#define ADXL345_DATAY0 0x34
#define ADXL345_DATAY1 0x35
#define ADXL345_DATAZ0 0x36
#define ADXL345_DATAZ1 0x37
#define DATA_FORMAT 0x37
#define ACT_INACT_CTL 0x27
#define POWER_CT 0x2D

void write_register(alt_16 x,int value);
alt_16 read_register(alt_16 x);
