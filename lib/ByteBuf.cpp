#include "ByteBuf.h"

#include <algorithm>
#include <cstring>

#include "ByteBufException.h"

ByteBuf* ByteBuf::make(uint8_t* buf, size_t len) {
    auto* ret = new ByteBuf();
    ret->_buffer = new uint8_t[len];
    std::memcpy(ret->_buffer, buf, len);
    ret->_offset = 0;
    ret->_capacity = len;
    ret->_usedBufferLength = len;
    ret->_maxCapacity = DEFAULT_MAX_BUFFER_CAPACITY;
    return ret;
}

ByteBuf *ByteBuf::make(const size_t capacity) { // NOLINT(*-convert-member-functions-to-static)
    auto* ret = new ByteBuf();
    ret->_buffer = new uint8_t[capacity];
    ret->_offset = 0;
    ret->_capacity = capacity;
    ret->_usedBufferLength = 0;
    ret->_maxCapacity = DEFAULT_MAX_BUFFER_CAPACITY;
    return ret;
}

void ByteBuf::write(const uint8_t value) {
    if(this->_offset >= this->_capacity) {
        this->increaseCapacity();
    }
    this->_buffer[this->_offset++] = value;
    this->_usedBufferLength += 1;
}

void ByteBuf::write(const uint8_t* value, const size_t len) {
    const size_t nextOffset = this->_offset + len;
    if(nextOffset > this->_capacity) {
        this->increaseCapacityMin(len);
    }
    std::memcpy(this->_buffer + this->_offset, value, len);
    this->_offset = nextOffset;
    this->_usedBufferLength += len;
}

void ByteBuf::read(uint8_t& out) {
    if(this->_offset > this->_usedBufferLength) {
        throw ByteBufException("Buffer read out of bounds");
    }
    out = this->_buffer[this->_offset++];
}

void ByteBuf::read(uint8_t* out, const size_t len) {
    const size_t maxOffset = this->_offset + len;
    if(maxOffset > this->_usedBufferLength) {
        throw ByteBufException("Buffer read out of bounds");
    }
    std::memcpy(out, this->_buffer + this->_offset, len);
    this->_offset = maxOffset;
}

uint8_t *ByteBuf::remaining() {
    const size_t remainingLength = this->_usedBufferLength - this->_offset;
    auto* ret = new uint8_t[remainingLength];
    this->read(ret, remainingLength);
    return ret;
}


uint8_t* ByteBuf::toString() const {
    auto* str = new uint8_t[this->_usedBufferLength];
    std::memcpy(str, this->_buffer, this->_usedBufferLength);
    return str;
}

void ByteBuf::setOffset(const size_t offset) {
    this->_offset = offset;
}

size_t ByteBuf::getOffset() const {
    return this->_offset;
}

size_t ByteBuf::getCapacity() const {
    return this->_capacity;
}

void ByteBuf::setCapacity(const size_t capacity) {
    this->_capacity = capacity;
    if(this->_capacity > this->_maxCapacity) {
        throw ByteBufException("Exceeded max buffer capacity");
    }
    auto* newByteBuf = new uint8_t[this->_capacity];
    std::memcpy(newByteBuf, this->_buffer, this->_offset);
    delete[] this->_buffer;
    this->_buffer = newByteBuf;
}

void ByteBuf::increaseCapacity() {
    size_t new_capacity = this->_capacity * this->_capacity;
    if (new_capacity > 10485760) { // 10MB. Why? Prevent memory exhaustion!
        new_capacity = 10485760;
    }
    this->setCapacity(new_capacity);
}

void ByteBuf::increaseCapacityMin(const size_t minimum_capacity) {
    size_t new_capacity = this->_capacity * this->_capacity;
    if (new_capacity > 10485760) { // 10MB. Why? Prevent memory exhaustion!
        new_capacity = 10485760;
    }
    size_t required_capacity = this->_capacity + minimum_capacity;
    if (required_capacity > new_capacity) {
        new_capacity = required_capacity;
    }
    this->setCapacity(new_capacity);
}

void ByteBuf::setMaxCapacity(const size_t maxCapacity) {
    this->_maxCapacity = maxCapacity;
}

size_t ByteBuf::getMaxCapacity() {
    return this->_maxCapacity;
}

size_t ByteBuf::getUsedBufferLength() const {
    return this->_usedBufferLength;
}

void ByteBuf::increaseCapacityIfLessThan(const size_t remaining_capacity) {
    if(this->_capacity - this->_offset < remaining_capacity) {
        this->increaseCapacityMin(remaining_capacity);
    }
}

void ByteBuf::free() {
    if(this->_buffer != nullptr) {
        delete[] this->_buffer;
        this->_buffer = nullptr;
    }
    this->_capacity = 0;
    this->_offset = 0;
}

void ByteBuf::writeUnsignedVarInt(const uint32_t value) {
    uint8_t a[5];
    uint32_t temp = value;
    for (int i = 0; i < 5; ++i) {
        if ((temp & ~0x7f) != 0) {
            a[i] = static_cast<uint8_t>(temp & 0x7f | 0x80);
        } else {
            a[i] = static_cast<uint8_t>(temp & 0x7f);
            this->write(a, i + 1);
            return;
        }
        temp >>= 7;
    }
    throw ByteBufException("This should never happen");
}

void ByteBuf::writeUnsignedVarLong(const uint64_t value) {
    uint8_t a[10];
    uint64_t temp = value;
    for (int i = 0; i < 10; ++i) {
        if ((temp & ~0x7f) != 0) {
            a[i] = static_cast<uint8_t>(temp & 0x7f | 0x80);
        } else {
            a[i] = static_cast<uint8_t>(temp & 0x7f);
            this->write(a, i + 1);
            return;
        }
        temp >>= 7;
    }
    throw ByteBufException("This should never happen");
}

void ByteBuf::readUnsignedVarInt(uint32_t* out) {
    uint32_t value = 0;
    for (int i = 0; i <= 28; i += 7) {
        if(this->_offset >= this->_usedBufferLength) {
            throw ByteBufException("Buffer read out of bounds");
        }
        const uint8_t b = this->_buffer[this->_offset++];
        value |= (b & 0x7f) << i;
        if ((b & 0x80) == 0) {
            *out = value;
            return;
        }
    }
    throw ByteBufException("VarInt did not terminate after 5 bytes!");
}

void ByteBuf::readUnsignedVarLong(uint64_t* out) {
    uint64_t value = 0;
    for (int i = 0; i <= 63; i += 7) {
        if(this->_offset >= this->_usedBufferLength) {
            throw ByteBufException("Buffer read out of bounds");
        }
        const uint8_t b = this->_buffer[this->_offset++];
        value |= (b & 0x7f) << i;
        if ((b & 0x80) == 0) {
            *out = value;
            return;
        }
    }
    throw ByteBufException("VarLong did not terminate after 10 bytes!");
}

void ByteBuf::writeVarInt(const int32_t value) {
    auto value2 = static_cast<uint32_t>(value);
    this->writeUnsignedVarInt((value2 << 1) ^ (value2 >> 31));
}

void ByteBuf::writeVarLong(const int64_t value) {
    auto value2 = static_cast<uint64_t>(value);
    this->writeUnsignedVarLong((value2 << 1) ^ (value2 >> 63));
}

void ByteBuf::readVarInt(int32_t* out) {
    uint32_t value;
    this->readUnsignedVarInt(&value);
    *out = static_cast<int32_t>((value >> 1) ^ -(value & 1));
}

void ByteBuf::readVarLong(int64_t* out) {
    uint64_t value;
    this->readUnsignedVarLong(&value);
    *out = static_cast<int64_t>((value >> 1) ^ -(value & 1));
}

ByteBuf::~ByteBuf() {
    this->free();
}