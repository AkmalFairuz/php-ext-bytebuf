#ifndef LIB_BYTEFLIPPER_H_
#define LIB_BYTEFLIPPER_H_
#include <cstdint>

class ByteFlipper {
public:
    static void flip(uint8_t* buf, size_t len);
};

#endif //LIB_BYTEFLIPPER_H_