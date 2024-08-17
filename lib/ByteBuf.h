#ifndef LIB_BYTEBUF_H_
#define LIB_BYTEBUF_H_

#include <cstddef>
#include <cstdint>

/* DEFAULT_MAX_BUFFER_CAPACITY is 100MB */
#define DEFAULT_MAX_BUFFER_CAPACITY 104857600

class ByteBuf {
public:
    uint8_t* _buffer{};
    size_t _capacity{};
    size_t _offset{};
    size_t _maxCapacity{};
    size_t _usedBufferLength{};

    static ByteBuf* make(size_t capacity);
    static ByteBuf* make(uint8_t* buf, size_t len);

    void write(uint8_t value);
    void write(const uint8_t* value, size_t len);
    void read(uint8_t &out);
    void read(uint8_t* out, size_t len);

    uint8_t* remaining();

    [[nodiscard]] uint8_t* toString() const;
    void setOffset(size_t offset);
    [[nodiscard]] size_t getOffset() const;

    [[nodiscard]] size_t getCapacity() const;
    void setCapacity(size_t capacity);
    void increaseCapacity();
    void increaseCapacityMin(size_t minimum_capacity);
    void increaseCapacityIfLessThan(size_t remaining_capacity);
    void setMaxCapacity(size_t maxCapacity);
    size_t getMaxCapacity();

    [[nodiscard]] size_t getUsedBufferLength() const;

    void free();

    ~ByteBuf();
};

#endif //LIB_BYTEBUF_H_