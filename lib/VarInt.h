#ifndef LIB_VARINT_H_
#define LIB_VARINT_H_

#include <cstdint>

class VarInt {
public:
    static void writeUnsignedInt(uint8_t* buffer, size_t& offset, uint32_t value);
    static void writeUnsignedLong(uint8_t* buffer, size_t& offset, uint64_t value);
    static void readUnsignedInt(const uint8_t* buffer, size_t& offset, uint32_t* out);
    static void readUnsignedLong(const uint8_t* buffer, size_t& offset, uint64_t* out);
    static void writeInt(uint8_t* buffer, size_t& offset, int32_t value);
    static void readInt(const uint8_t* buffer, size_t& offset, int32_t* out);
    static void writeLong(uint8_t* buffer, size_t& offset, int64_t value);
    static void readLong(const uint8_t* buffer, size_t& offset, int64_t* out);
};

#endif //LIb_VARINT_H_