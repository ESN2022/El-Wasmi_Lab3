/*
 * Lab3_definitions.c
 *
 *  Created on: 13 janv. 2023
 *      Author: Ahmed
 */

#include "Lab3_definitions.h"

/*
Fonction pour écrire dans un registre spécifique du capteur en utilisant le protocole I2C.
Il prend en entrée l'adresse du registre et la valeur à écrire.
*/
void write_register(alt_16 x, int value) {
  I2C_start(I2C_BASE, 0x1D, 0);
  I2C_write(I2C_BASE, x, 0);
  I2C_write(I2C_BASE, value, 1);

}

/*
Fonction pour lire un registre spécifique du capteur en utilisant le protocole I2C.
Il prend en entrée l'adresse du registre et retourne la valeur lue.
*/
int read_register(alt_16 x) {
  I2C_start(I2C_BASE, 0x1D, 0);
  I2C_write(I2C_BASE, x, 0);
  I2C_start(I2C_BASE, 0x1D, 1);
  return I2C_read(I2C_BASE, 1);

}

/*
Fonction pour convertir un entier en code BCD (Binary-Coded Decimal).
Il prend en entrée la valeur à convertir et retourne la valeur convertie.
*/
alt_32 int_to_bcd(alt_32 int_value) {
  alt_32 result = 0;
  if (int_value < 0) {
    int_value = -int_value;
    result = 15 << 16;
  } else {
    result = 14 << 16;
  }
  char bcd_value[4];
  bcd_value[0] = int_value % 10;
  bcd_value[1] = int_value / 10 % 10;
  bcd_value[2] = int_value / 100 % 10;
  bcd_value[3] = int_value / 1000 % 10;
  return result = result + (bcd_value[3] << 12) + (bcd_value[2] << 8) + (bcd_value[1] << 4) + bcd_value[0];
}

/*
Fonction pour afficher les valeurs de l'accélération sur les afficheurs 7 segments en fonction de la valeur de switch_value.
Il lit la valeur de switch_value et affiche la valeur de l'accélération correspondante (X, Y ou Z)
*/
void axes() {
  switch (switch_value) {
  case 0b00:
    IOWR_ALTERA_AVALON_PIO_DATA(SEG_BASE, (10 << 20) + int_to_bcd(X * 4));
    printf("Valeur pour switch 00: x\n");
    break;
  case 0b01:
    IOWR_ALTERA_AVALON_PIO_DATA(SEG_BASE, (11 << 20) + int_to_bcd(Y * 4));
    printf("Valeur pour switch 01: y\n");
    break;
  case 0b10:
    IOWR_ALTERA_AVALON_PIO_DATA(SEG_BASE, (12 << 20) + int_to_bcd(Z * 4));
    printf("Valeur pour switch 10: z\n");
    break;
  }
}
