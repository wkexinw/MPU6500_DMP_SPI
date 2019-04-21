#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <bcm2835.h>
#include "SPIdev.h"

int init(){
	// If you call this, it will not actually access the GPIO
	// Use for testing
    //bcm2835_set_debug(1);
    if (!bcm2835_init())
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return -1;
    }
    if (!bcm2835_spi_begin())
    {
      printf("bcm2835_spi_begin failedg. Are you running as root??\n");
      return -1;
    }
    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256);
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
    bcm2835_spi_chipSelect(BCM2835_SPI_CS0);                   // The default
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, LOW);
	return 0;
}

int writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data) {

	char byte[length+1];

	byte[0]=regAddr;

	memcpy(byte+1, data, length);

	bcm2835_spi_transfern(byte,sizeof(byte));

	return 0;
}

int8_t readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data){

	char byte[length+1];

	byte[0]=regAddr|0x80;

	memcpy(byte+1, data, length);

	bcm2835_spi_transfern(byte,sizeof(byte));

	memcpy(data,byte+1,length);

	return 0;
}