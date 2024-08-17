#ifndef LIB_VARINT_H_
#define LIB_VARINT_H_

#include <cstdint>
#include <cstddef>

class VarInt {
public:
    static void writeUnsignedInt(uint8_t* buffer, size_t& offset, uint32_t value, size_t maxOffset);
    static void writeUnsignedLong(uint8_t* buffer, size_t& offset, uint64_t value, size_t maxOffset);
    static void readUnsignedInt(const uint8_t* buffer, size_t& offset, uint32_t* out, size_t maxOffset);
    static void readUnsignedLong(const uint8_t* buffer, size_t& offset, uint64_t* out, size_t maxOffset);
    static void writeInt(uint8_t* buffer, size_t& offset, int32_t value, size_t maxOffset);
    static void readInt(const uint8_t* buffer, size_t& offset, int32_t* out, size_t maxOffset);
    static void writeLong(uint8_t* buffer, size_t& offset, int64_t value, size_t maxOffset);
    static void readLong(const uint8_t* buffer, size_t& offset, int64_t* out, size_t maxOffset);
};

#endif //LIB_VARINT_H_