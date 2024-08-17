#ifndef SRC_INT24_TYPE_H_
#define SRC_INT24_TYPE_H_

#include <cstdint>
#include <cstddef>

void int24_to_bytes(int32_t value, uint8_t* buf);
void bytes_to_int24(const uint8_t* buf, int32_t* out);
void uint24_to_bytes(uint32_t value, uint8_t* buf);
void bytes_to_uint24(const uint8_t* buf, uint32_t* out);

#endif //SRC_TRIAD_TYPE_H_