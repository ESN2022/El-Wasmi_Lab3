#include <stdio.h>
#include "system.h"
#include "Lab3_definitions.h"
#include "opencores_i2c.h"



int main() {
  int data[6];
  int i;

  I2C_init(I2C_BASE, ALT_CPU_FREQ, 100000);

  if (I2C_start(I2C_BASE, 0x1D, 0) == 0) {
    printf("connection etablie");
  } else {
    printf("error de connexion");
  }

  write_register(ACT_INACT_CTL, 240);
  write_register(POWER_CT, 8);
  write_register(DATA_FORMAT, 8);

  while (1) {
    // lecture de l'axe x

    data[0] = read_register(ADXL345_DATAX0);

    data[1] = read_register(ADXL345_DATAX1);

    alt_16 x = (data[1] << 8) | data[0];

    printf("X: %d \n", x * 4);

    // Delay for a bit
    usleep(1000000);
  }
  return 0;
}
