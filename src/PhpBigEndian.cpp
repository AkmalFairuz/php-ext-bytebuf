#include "PhpBigEndian.h"
#include "../lib/ByteOrder.h"
#include "../lib/ByteFlipper.h"
#include "../bytebuf_arginfo.h"
#include "ZendUtil.h"
#include "Int24Util.h"
#include "ByteBufException.h"
#include <cstdint>

extern "C" {
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_exceptions.h"
}

extern zend_class_entry* bytebuf_exception_ce;

typedef struct {
    zend_object std;
} big_endian_obj;

zend_class_entry *big_endian_ce;
static zend_object_handlers big_endian_handlers;

static zend_object* big_endian_new(zend_class_entry *ce) {
    auto object = alloc_custom_zend_object<big_endian_obj>(ce, &big_endian_handlers);
    return &object->std;
}

static void big_endian_free(zend_object *object) {
    zend_object_std_dtor(object);
}

#define BIG_ENDIAN_METHOD(name) \
    PHP_METHOD(AkmalFairuz_ByteBuf_BE, name)

BIG_ENDIAN_METHOD(__construct) {
    // NOTHING
}

#define BIG_ENDIAN_READ_WRITE_METHOD(name, type, size) \
    BIG_ENDIAN_METHOD(write##name) { \
        zend_long value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_LONG(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        auto value2 = static_cast<type>(value); \
        auto *returnBytes = reinterpret_cast<uint8_t*>(&value2); \
        if(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(returnBytes, size); \
        } \
        \
        RETURN_STRINGL(reinterpret_cast<char*>(returnBytes), size); \
    } \
    \
    BIG_ENDIAN_METHOD(read##name) { \
        zend_string *value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_STR(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        if(ZSTR_LEN(value) < size) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, "Invalid length of string, expected %d", size); \
            return; \
        } \
        \
        auto* returnBytes = reinterpret_cast<uint8_t*>(ZSTR_VAL(value)); \
        if(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(returnBytes, size); \
        } \
        \
        RETURN_LONG(*reinterpret_cast<type*>(returnBytes)); \
    }

BIG_ENDIAN_READ_WRITE_METHOD(Short, int16_t, 2)
BIG_ENDIAN_READ_WRITE_METHOD(UnsignedShort, uint16_t, 2)
BIG_ENDIAN_READ_WRITE_METHOD(Int, int32_t, 4)
BIG_ENDIAN_READ_WRITE_METHOD(UnsignedInt, uint32_t, 4)
BIG_ENDIAN_READ_WRITE_METHOD(Long, int64_t, 8)
BIG_ENDIAN_READ_WRITE_METHOD(UnsignedLong, uint64_t, 8)

#define BIG_ENDIAN_READ_WRITE_TRIAD_METHOD(name, type, tobytesfunc, tointfunc) \
    BIG_ENDIAN_METHOD(write##name) { \
        zend_long value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_LONG(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        auto value2 = static_cast<int32_t>(value); \
        auto *returnBytes = new uint8_t[3]; \
        tobytesfunc(value2, returnBytes); \
        if(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(returnBytes, 3); \
        } \
        \
        zend_string *result = zend_string_init(reinterpret_cast<char*>(returnBytes), 3, 0); \
        delete[] returnBytes; \
        RETURN_STR(result); \
    } \
    \
    BIG_ENDIAN_METHOD(read##name) { \
        zend_string *value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_STR(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        if(ZSTR_LEN(value) < 3) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, "Invalid length of string, expected 3"); \
            return; \
        } \
        \
        auto *returnBytes = reinterpret_cast<uint8_t*>(ZSTR_VAL(value)); \
        if(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(returnBytes, 3); \
        } \
        \
        type ret = 0; \
        tointfunc(returnBytes, &ret); \
        RETURN_LONG(ret); \
    }

BIG_ENDIAN_READ_WRITE_TRIAD_METHOD(Triad, int32_t, int24_to_bytes, bytes_to_int24)
BIG_ENDIAN_READ_WRITE_TRIAD_METHOD(UnsignedTriad, uint32_t, uint24_to_bytes, bytes_to_uint24)

#define BIG_ENDIAN_READ_WRITE_FLOAT_METHOD(name, type, size) \
    BIG_ENDIAN_METHOD(write##name) { \
        double value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_DOUBLE(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        auto value2 = static_cast<type>(value); \
        auto *returnBytes = reinterpret_cast<uint8_t*>(&value2); \
        if(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(returnBytes, size); \
        } \
        \
        RETURN_STRINGL(reinterpret_cast<char*>(returnBytes), size); \
    } \
    \
    BIG_ENDIAN_METHOD(read##name) { \
        zend_string *value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_STR(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        if(ZSTR_LEN(value) < size) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, "Invalid length of string, expected %d", size); \
            return; \
        } \
        \
        auto *returnBytes = reinterpret_cast<uint8_t*>(ZSTR_VAL(value)); \
        if(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(returnBytes, size); \
        } \
        \
        double ret = *reinterpret_cast<type*>(returnBytes); \
        RETURN_DOUBLE(ret); \
    }

BIG_ENDIAN_READ_WRITE_FLOAT_METHOD(Float, float, 4)
BIG_ENDIAN_READ_WRITE_FLOAT_METHOD(Double, double, 8)

void register_big_endian_class() {
    zend_class_entry ce;
    ce.ce_flags |= ZEND_ACC_FINAL | ZEND_ACC_NO_DYNAMIC_PROPERTIES;
    INIT_CLASS_ENTRY(ce, "AkmalFairuz\\ByteBuf\\BE", be_methods);
    big_endian_ce = zend_register_internal_class(&ce);
    big_endian_ce->create_object = big_endian_new;

    memcpy(&big_endian_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    big_endian_handlers.offset = XtOffsetOf(big_endian_obj, std);
    big_endian_handlers.free_obj = big_endian_free;
}
