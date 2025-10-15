/**
 *******************************************************************************
 * STM32L4 Bootloader - Core Functions
 *******************************************************************************
 * @author Amen Ellah Kerimi
 * @file   bootloader.c
 * @brief  Core bootloader logic: firmware loading, CRC checking, application jump.
 *
 * @see    Please refer to README for detailed information.
 *******************************************************************************
 * Copyright (c) 2025 Amen Ellah Kerimi.     https://amenellah.kerimi.com
 *******************************************************************************
 */

/* General Includes ---------------------------------------------------------*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Private Includes ---------------------------------------------------------*/
#include "../inc/bootloader.h"
#include "../inc/crc32.h"
#include "../inc/flash.h"

/* Private Defines ----------------------------------------------------------*/
#define APP_START_ADDR 0x08004000
#define APP_SIZE       0x20000
#define CRC_SIZE       4

/* Private Functions --------------------------------------------------------*/
void jump_to_application(uint8_t *app, uint32_t size) {
    uint32_t stored_crc;
    memcpy(&stored_crc, app + size - CRC_SIZE, CRC_SIZE);
    uint32_t calc_crc = crc32(app, size - CRC_SIZE);
    if (stored_crc == calc_crc) {
        printf("[Bootloader] Jumping to application at fake flash address... CRC OK!\n");
    } else {
        printf("[Bootloader] [ERROR] Application invalid! Staying in bootloader\n");
    }
}

/* CODE --------------------------------------------------------------------*/
void bootloader_main() {
    printf("Bootloader started...\n");
    printf("[Bootloader] Erasing flash...\n");
    flash_erase(0, APP_SIZE + CRC_SIZE);

    printf("[Bootloader] Loading firmware from app.bin...\n");
    FILE *f = fopen("app.bin", "rb");
    if (!f){
        printf("[Bootloader] [ERROR] Failed to open app.bin\n");
        return;
    }

    uint8_t buffer[1024];
    uint32_t addr = 0;
    size_t n;

    while ((n = fread(buffer, 1, sizeof(buffer), f))) {
        flash_write(addr, buffer, n);
        addr += n;
    }
    fclose(f);

    printf("[Bootloader] Firmware loaded: %u bytes\n", addr);

    printf("[Bootloader] Verifying CRC...\n");
    uint32_t stored_crc;
    flash_read(APP_SIZE, (uint8_t *)&stored_crc, CRC_SIZE);
    uint32_t calc_crc = crc32(flash_memory, APP_SIZE);
    printf("[Bootloader] Stored CRC: 0x%08X, Calculated CRC: 0x%08X\n", stored_crc, calc_crc);
    printf("[Bootloader] %s\n", (calc_crc == stored_crc) ? "CRC OK!" : "CRC FAIL!");

    jump_to_application(flash_memory, APP_SIZE + CRC_SIZE);
}
