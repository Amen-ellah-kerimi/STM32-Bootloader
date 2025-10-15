/**
 *******************************************************************************
 * STM32L4 Bootloader - CRC32 Calculation
 *******************************************************************************
 * @author Amen Ellah Kerimi
 * @file   crc32.c
 * @brief  Simple CRC32 checksum calculation for bootloader verification.
 *
 * @see    Please refer to README for detailed information.
 *******************************************************************************
 */

/* General Includes ---------------------------------------------------------*/
#include <stdint.h>

/* Private Includes ---------------------------------------------------------*/
#include "../inc/crc32.h"

/* CODE --------------------------------------------------------------------*/
uint32_t crc32(const uint8_t *data, uint32_t len) {
    uint32_t crc = 0;
    for (uint32_t i = 0; i < len; i++) {
        crc += data[i];
    }
    return crc;
}
