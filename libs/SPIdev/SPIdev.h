
#ifndef _SPIDEV_H_
#define _SPIDEV_H_

#define SPI_OK 0

#define SPI_ERR -1

int8_t readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data);

int writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data);

int init();

#endif