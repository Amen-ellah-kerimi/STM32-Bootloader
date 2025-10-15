#!/usr/bin/env python3

import struct

APP_SIZE = 0x20000
CRC_SIZE = 4

def crc32(data):
    return sum(data) & 0xFFFFFFFF

def main():
    app = bytearray([i & 0xFF for i in range(APP_SIZE)])

    c = crc32(app)

    app += struct.pack('<I', c)

    with open("../app.bin","wb") as f:
        f.write(app)

    print(f"App binary generated with CRC {c:#010x}")

if __name__=="__main__":
    main()
