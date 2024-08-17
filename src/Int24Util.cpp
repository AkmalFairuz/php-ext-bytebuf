#include "Int24Util.h"
#include "../lib/ByteOrder.h"
#include "../lib/ByteFlipper.h"

#include <algorithm>

void int24_to_bytes(int32_t value, uint8_t* buf) {
    buf[0] = static_cast<uint8_t>(value);
    buf[1] = static_cast<uint8_t>(value >> 8);
    buf[2] = static_cast<uint8_t>(value >> 16);
}

void bytes_to_int24(const uint8_t* buf, int32_t* out) {
    *out = (buf[0] & 0xFF) | ((buf[1] & 0xFF) << 8) | ((buf[2] & 0xFF) << 16);
    if (*out & 0x800000) {
        *out |= 0xFF000000;
    }
}

void uint24_to_bytes(uint32_t value, uint8_t* buf) {
    buf[0] = static_cast<uint8_t>(value);
    buf[1] = static_cast<uint8_t>(value >> 8);
    buf[2] = static_cast<uint8_t>(value >> 16);
}

void bytes_to_uint24(const uint8_t* buf, uint32_t* out) {
    *out = (buf[0] & 0xFF) | ((buf[1] & 0xFF) << 8) | ((buf[2] & 0xFF) << 16);
}