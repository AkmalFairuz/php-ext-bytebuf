#include "VarInt.h"
#include "ByteBufException.h"
#include <cstring>

void VarInt::writeUnsignedInt(uint8_t* buffer, size_t& offset, uint32_t value) {
    uint8_t a[5];
    int i = 0;
    while (i < 5) {
        a[i] = (value & 0x7f);
        if ((value >>= 7) != 0) {
            a[i] |= 0x80;
        } else {
            break;
        }
        ++i;
    }
    memcpy(buffer + offset, a, i + 1);
    offset += i + 1;
}

void VarInt::writeUnsignedLong(uint8_t* buffer, size_t& offset, uint64_t value) {
    uint8_t a[10];
    int i = 0;
    while (i < 10) {
        a[i] = (value & 0x7f);
        if ((value >>= 7) != 0) {
            a[i] |= 0x80;
        } else {
            break;
        }
        ++i;
    }
    memcpy(buffer + offset, a, i + 1);
    offset += i + 1;
}

void VarInt::readUnsignedInt(const uint8_t* buffer, size_t& offset, uint32_t* out) {
    *out = 0;
    for (int i = 0; i <= 28; i += 7) {
        const uint8_t b = buffer[offset++];
        *out |= (b & 0x7f) << i;
        if ((b & 0x80) == 0) {
            return;
        }
    }
    throw ByteBufException("VarInt::readUnsignedInt: VarInt did not terminate after 5 bytes!");
}

void VarInt::readUnsignedLong(const uint8_t* buffer, size_t& offset, uint64_t* out) {
    *out = 0;
    for (int i = 0; i <= 63; i += 7) {
        const uint8_t b = buffer[offset++];
        *out |= (b & 0x7f) << i;
        if ((b & 0x80) == 0) {
            return;
        }
    }
    throw ByteBufException("VarInt::readUnsignedLong: VarLong did not terminate after 10 bytes!");
}

void VarInt::writeInt(uint8_t* buffer, size_t& offset, const int32_t value) {
    VarInt::writeUnsignedInt(buffer, offset, (value << 1) ^ (value >> 31));
}

void VarInt::readInt(const uint8_t* buffer, size_t& offset, int32_t* out) {
    uint32_t i = 0;
    VarInt::readUnsignedInt(buffer, offset, &i);
    *out = static_cast<int32_t>((i >> 1) ^ -(i & 1));
}

void VarInt::writeLong(uint8_t* buffer, size_t& offset, const int64_t value) {
    VarInt::writeUnsignedLong(buffer, offset, (value << 1) ^ (value >> 63));
}

void VarInt::readLong(const uint8_t* buffer, size_t& offset, int64_t* out) {
    uint64_t i = 0;
    VarInt::readUnsignedLong(buffer, offset, &i);
    *out = static_cast<int64_t>((i >> 1) ^ -(i & 1));
}