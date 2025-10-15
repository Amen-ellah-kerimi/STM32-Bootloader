#include "flash.h"
#include <string.h>
#include <stdio.h>

uint8_t flash_memory[APP_SIZE + CRC_SIZE];

void flash_write(uint32_t addr,
                 const uint8_t *data,
                 uint32_t len) {
    if (addr + len > APP_SIZE + CRC_SIZE){
        printf("[Flash] write out of bounds!addr=0x%08X len=%u\n", addr, len);
        return;
    }
    memcpy(flash_memory + addr, data, len);
    printf("[FLASH] Wrote %u bytes to address 0x%08X\n", len, addr);

}

void flash_read(uint32_t addr,
                uint8_t *buf,
                uint32_t len){
    if (addr + len > APP_SIZE + CRC_SIZE){
        printf("[Flash] read out of bounds! addr=0x%08X len=%u\n", addr, len);
        return;
    }
    memcpy(buf, flash_memory + addr, len);
    printf("[FLASH] Read %u bytes from address 0x%08X\n", len, addr);
}

void flash_erase(uint32_t addr, uint32_t len){
    if (addr + len > APP_SIZE + CRC_SIZE){
        printf("[Flash] erase out of bounds!\n");
        return;
    }
    memset(flash_memory + addr, 0xFF, len);
    printf("[FLASH] Erased %u bytes from address 0x%08X\n", len, addr);
}
