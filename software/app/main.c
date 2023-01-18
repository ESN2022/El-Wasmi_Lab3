#include "Lab3_definitions.h"

// déclaration des fonctions d'interruption pour le timer et les Switchs
static void timer_interrupt(void * Context, alt_u32 id);
static void irqhandler_switch(void * context);

int main() {
  // Initialisation de la communication I2C
  I2C_init(I2C_BASE, ALT_CPU_FREQ, 100000);

  // Vérification de la connexion avec la périphérique I2C
  if (I2C_start(I2C_BASE, 0x1D, 0) == 0) {
    printf("connection établie\n");
  } else {
    printf("error de connexion\n");
  }
  // Initialisation et configuration du timer pour les interruptions
  IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
  alt_ic_isr_register(TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID, TIMER_0_IRQ, (void * ) timer_interrupt, NULL, 0);
  IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER_0_BASE, 0x07);

  // Initialisation et configuration des commutateurs pour les interruptions
  IOWR_ALTERA_AVALON_PIO_IRQ_MASK(SWITCHS_BASE, 0b1111);
  IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SWITCHS_BASE, 0x0);
  alt_ic_isr_register(SWITCHS_IRQ_INTERRUPT_CONTROLLER_ID, SWITCHS_IRQ, (void * ) irqhandler_switch, NULL, NULL);

  // Ecriture dans les registres pour configurer l'acceleromètre
  write_register(ACT_INACT_CTL, 240);
  write_register(POWER_CT, 8);
  write_register(DATA_FORMAT, 8);
  write_register(ADXL345_OFSX, 1);
  write_register(ADXL345_OFSY, 0);
  write_register(ADXL345_OFSZ, 2);

  // Lecture de la valeur des commutateurs
  switch_value = IORD_ALTERA_AVALON_PIO_DATA(SWITCHS_BASE);

  while (1);
  return 0;
}

static void timer_interrupt(void * Context, alt_u32 id) {
  // Lecture des données de l'acceleromètre
  data[0] = read_register(ADXL345_DATAX0);
  data[1] = read_register(ADXL345_DATAX1);
  // combiner les données X
  X = (data[1] << 8) | data[0];

  data[2] = read_register(ADXL345_DATAY0);
  data[3] = read_register(ADXL345_DATAY1);
  // combiner les données Y
  Y = (data[3] << 8) | data[2];

  data[4] = read_register(ADXL345_DATAZ0);
  data[5] = read_register(ADXL345_DATAZ1);
  // combiner les données Z
  Z = (data[5] << 8) | data[4];

  // Affichage des valeurs X, Y, Z dans la console
  printf("X: %d Y: %d Z: %d \n", X * 4, Y * 4, Z * 4);

  // Appel de la fonction pour afficher les valeurs de X, Y, Z sur les afficheurs 7 segments en fonction de la position des switchs
  axes();

  // Réinitialisation du statut du timer
  IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER_0_BASE, 0);
}

static void irqhandler_switch(void * context) {
  switch_value = IORD_ALTERA_AVALON_PIO_DATA(SWITCHS_BASE);
  IOWR_ALTERA_AVALON_PIO_EDGE_CAP(SWITCHS_BASE, 0x0);
}
