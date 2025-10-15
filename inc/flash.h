#ifndef FLASH_H
#define FLASH_H

#include <stdint.h>

#define APP_SIZE 0x20000
#define CRC_SIZE 4

extern uint8_t flash_memory[APP_SIZE + CRC_SIZE];

void flash_write(uint32_t addr, const uint8_t *data, uint32_t len);
void flash_read(uint32_t addr, uint8_t *buf, uint32_t len);
void flash_erase(uint32_t addr, uint32_t len);

#endif
