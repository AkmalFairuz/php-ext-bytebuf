#include "VarInt.h"
#include "ByteBufException.h"
#include <cstring>

void VarInt::writeUnsignedInt(uint8_t* buffer, size_t& offset, uint32_t value, size_t maxOffset) {
    uint8_t a[5];
    int i = 0;
    for (; i < 5; ++i) {
        if ((value & ~0x7f) != 0) {
            a[i] = static_cast<uint8_t>(value & 0x7f | 0x80);
        } else {
            a[i] = static_cast<uint8_t>(value & 0x7f);
            break;
        }
        value >>= 7;
    }
    if(offset + i >= maxOffset) {
        throw ByteBufException("VarInt exceeds maxOffset");
    }
    memcpy(buffer + offset, a, i + 1);
    offset += i + 1;
}

void VarInt::writeUnsignedLong(uint8_t* buffer, size_t& offset, uint64_t value, size_t maxOffset) {
    uint8_t a[10];
    int i = 0;
    for (; i < 10; ++i) {
        if ((value & ~0x7f) != 0) {
            a[i] = static_cast<uint8_t>(value & 0x7f | 0x80);
        } else {
            a[i] = static_cast<uint8_t>(value & 0x7f);
            break;
        }
        value >>= 7;
    }
    if(offset + i >= maxOffset) {
        throw ByteBufException("VarLong exceeds maxOffset");
    }
    memcpy(buffer + offset, a, i + 1);
    offset += i + 1;
}

void VarInt::readUnsignedInt(const uint8_t* buffer, size_t& offset, uint32_t* out, size_t maxOffset) {
    *out = 0;
    for (int i = 0; i <= 28; i += 7) {
        if(offset >= maxOffset) {
            throw ByteBufException("VarInt exceeds maxOffset");
        }
        const uint8_t b = buffer[offset++];
        *out |= (b & 0x7f) << i;
        if ((b & 0x80) == 0) {
            return;
        }
    }
    throw ByteBufException("VarInt::readUnsignedInt: VarInt did not terminate after 5 bytes!");
}

void VarInt::readUnsignedLong(const uint8_t* buffer, size_t& offset, uint64_t* out, size_t maxOffset) {
    *out = 0;
    for (int i = 0; i <= 63; i += 7) {
        if(offset >= maxOffset) {
            throw ByteBufException("VarLong exceeds maxOffset");
        }
        const uint8_t b = buffer[offset++];
        *out |= (b & 0x7f) << i;
        if ((b & 0x80) == 0) {
            return;
        }
    }
    throw ByteBufException("VarInt::readUnsignedLong: VarLong did not terminate after 10 bytes!");
}

void VarInt::writeInt(uint8_t* buffer, size_t& offset, const int32_t value, size_t maxOffset) {
    VarInt::writeUnsignedInt(buffer, offset, (value << 1) ^ (value >> 31), maxOffset);
}

void VarInt::readInt(const uint8_t* buffer, size_t& offset, int32_t* out, size_t maxOffset) {
    uint32_t i = 0;
    VarInt::readUnsignedInt(buffer, offset, &i, maxOffset);
    *out = static_cast<int32_t>((i >> 1) ^ -(i & 1));
}

void VarInt::writeLong(uint8_t* buffer, size_t& offset, const int64_t value, size_t maxOffset) {
    VarInt::writeUnsignedLong(buffer, offset, (value << 1) ^ (value >> 63), maxOffset);
}

void VarInt::readLong(const uint8_t* buffer, size_t& offset, int64_t* out, size_t maxOffset) {
    uint64_t i = 0;
    VarInt::readUnsignedLong(buffer, offset, &i, maxOffset);
    *out = static_cast<int64_t>((i >> 1) ^ -(i & 1));
}