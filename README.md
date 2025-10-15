# STM32 Bootloader Simulation

This project simulates an STM32 bootloader using C, without requiring actual hardware.

## Memory Layout

- Bootloader: `0x08000000`
- Application: `0x08004000`
- Flash Size: 128KB

## Building

Run `make` to compile the simulation.

## Running

Execute the compiled binary to simulate the bootloader's behavior.

## Future Work

- Implement real flash memory operations
- Add UART/USB communication for firmware updates
