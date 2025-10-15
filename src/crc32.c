#include "crc32.h"

uint32_t crc32(const uint8_t *data, uint32_t len) {
    uint32_t crc = 0;
    for (uint32_t i = 0; i < len; i++) {
        crc += data[i];
    }
    return crc;
}
