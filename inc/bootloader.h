#ifndef BOOTLOADER_H
#define BOOTLOADER_H

#include <stdint.h>

#define APP_SIZE 0x20000
#define CRC_SIZE 4

extern uint8_t flash_memory[APP_SIZE + CRC_SIZE];

void jump_to_application(uint8_t *app, uint32_t size);
void bootloader_main(void);

#endif
