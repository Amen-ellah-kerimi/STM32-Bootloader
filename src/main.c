/**
 *******************************************************************************
 * STM32L4 Bootloader
 *******************************************************************************
 * @author Amen Ellah Kerimi
 * @file   main.c
 * @brief  Main program
 *             This file demonstrates the usage of the bootloader.
 *
 * @see    Please refer to README for detailed information.
 *******************************************************************************
 * Copyright (c) 2025 Amen Ellah Kerimi.     https://amenellah.kerimi.com
 *******************************************************************************
 */

/* General Includes ---------------------------------------------------------*/
#include <stdio.h>

/* Private Includes ---------------------------------------------------------*/
#include "../inc/bootloader.h"

/* CODE ---------------------------------------------------------*/
int main() {
    bootloader_main();
    return 0;
}
