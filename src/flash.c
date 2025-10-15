/**
 *******************************************************************************
 * STM32L4 Bootloader - Flash Simulation
 *******************************************************************************
 * @author Amen Ellah Kerimi
 * @file   flash.c
 * @brief  Simulated flash memory operations for bootloader testing.
 *
 * @see    Please refer to README for detailed information.
 *******************************************************************************
 */

/* General Includes ---------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Private Includes ---------------------------------------------------------*/
#include "../inc/flash.h"

/* Private Variables --------------------------------------------------------*/
uint8_t flash_memory[APP_SIZE + CRC_SIZE];

/* CODE --------------------------------------------------------------------*/
void flash_write(uint32_t addr, const uint8_t *data, uint32_t len) {
    if (addr + len > APP_SIZE + CRC_SIZE){
        printf("[FLASH] Write out of bounds! addr=0x%08X len=%u\n", addr, len);
        return;
    }
    memcpy(flash_memory + addr, data, len);
    printf("[FLASH] Wrote %u bytes to address 0x%08X\n", len, addr);
}

void flash_read(uint32_t addr, uint8_t *buf, uint32_t len){
    if (addr + len > APP_SIZE + CRC_SIZE){
        printf("[FLASH] Read out of bounds! addr=0x%08X len=%u\n", addr, len);
        return;
    }
    memcpy(buf, flash_memory + addr, len);
    printf("[FLASH] Read %u bytes from address 0x%08X\n", len, addr);
}

void flash_erase(uint32_t addr, uint32_t len){
    if (addr + len > APP_SIZE + CRC_SIZE){
        printf("[FLASH] Erase out of bounds!\n");
        return;
    }
    memset(flash_memory + addr, 0xFF, len);
    printf("[FLASH] Erased %u bytes from address 0x%08X\n", len, addr);
}
