#ifndef LIB_BYTEORDER_H_
#define LIB_BYTEORDER_H_

enum class ByteOrder {
    BE,
    LE,
#ifdef WORDS_BIGENDIAN
    NATIVE = BE
#else
    NATIVE = LE
#endif
};

#endif //LIB_BYTEORDER_H_