---

# STM32L4 Bootloader Simulation

![C](https://img.shields.io/badge/language-C-blue)
![STM32](https://img.shields.io/badge/board-STM32L4-lightgrey)
![Makefile](https://img.shields.io/badge/build-Makefile-orange)
![License: MIT](https://img.shields.io/badge/license-MIT-yellow.svg)

A simple educational STM32L4 bootloader written in C, demonstrating **firmware loading**, **CRC verification**, and **flash memory management**. Includes a simulated flash interface and detailed logging for each step.

---

## Features

* Simulated flash memory with read, write, and erase operations
* CRC32 checksum verification of loaded firmware
* Loads firmware from a binary file (`app.bin`)
* Step-by-step logging of bootloader operations
* Modular C code suitable for learning embedded bootloader concepts

---

## Project Structure

```
stm32-bootloader/
├── inc/                # Header files
│   ├── bootloader.h
│   ├── crc32.h
│   └── flash.h
├── src/                # Source files
│   ├── main.c
│   ├── bootloader.c
│   ├── crc32.c
│   └── flash.c
├── tools/              # Helper scripts
│   └── mkapp.py        # Generates app.bin firmware
├── app.bin             # Example firmware
├── Makefile
└── README.md
```

---

## Usage

1. **Build the bootloader simulator**

```bash
make
```

2. **Run the simulator**

```bash
./bootloader_sim
```

The simulator will:

* Erase the simulated flash
* Load `app.bin` into flash memory
* Verify CRC checksum
* “Jump” to the application

---

## Adding Your Firmware

Use the provided Python tool `tools/mkapp.py` to generate a new firmware binary (`app.bin`) for testing.

```bash
python tools/mkapp.py
```

---

## Project Status / Next Steps

* Current: Fully functional simulated bootloader
* Next: Integrate with actual STM32 hardware for real flash programming
* Future: Add UART / USB DFU update support, multiple applications, advanced CRC algorithms

---

## License

MIT License © 2025 Amen Ellah Kerimi
[https://amenellah.kerimi.com](https://amenellah.kerimi.com)
