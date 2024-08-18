#include "PhpVarInt.h"
#include "../bytebuf_arginfo.h"
#include "ZendUtil.h"
#include <cstdint>
#include "../lib/ByteBufException.h"

extern "C" {
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_exceptions.h"
}

typedef struct {
    zend_object std;
} var_int_obj;

extern zend_class_entry* bytebuf_exception_ce;

zend_class_entry *var_int_ce;
static zend_object_handlers var_int_handlers;

static zend_object* var_int_new(zend_class_entry *ce) {
    auto object = alloc_custom_zend_object<var_int_obj>(ce, &var_int_handlers);
    return &object->std;
}

static void var_int_free(zend_object *object) {
    zend_object_std_dtor(object);
}

#define VAR_INT_METHOD(name) \
    PHP_METHOD(AkmalFairuz_ByteBuf_VarInt, name)

VAR_INT_METHOD(__construct) {
    // NOTHING
}

int32_t VarIntDecodeZigZag32(uint32_t n) {
	return (n >> 1) ^ -(n & 1);
}

int64_t VarIntDecodeZigZag64(uint64_t n) {
	return (n >> 1) ^ -(n & 1);
}

uint32_t VarIntEncodeZigZag32(int32_t n) {
	return (n << 1) ^ (n >> 31);
}

uint64_t VarIntEncodeZigZag64(int64_t n) {
	return (n << 1) ^ (n >> 63);
}

#define VAR_INT_READ_WRITE_METHOD(name, type, maxsize, signed, maxloop) \
    VAR_INT_METHOD(write##name) { \
        zend_long zvalue; \
        \
        ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1) \
            Z_PARAM_LONG(zvalue) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        type raw = (type)zvalue; \
        if (signed) { \
            if (maxsize == 5) { \
                raw = VarIntEncodeZigZag32(raw); \
            } else { \
                raw = VarIntEncodeZigZag64(raw); \
            } \
        } \
        \
        char a[maxsize]; \
        type temp = raw; \
        for (int i = 0; i < maxsize; ++i) { \
            if ((temp & ~0x7f) != 0) { \
                a[i] = (temp & 0x7f) | 0x80; \
            } else { \
                a[i] = temp & 0x7f; \
                RETURN_STRINGL(a, i + 1); \
            } \
            temp >>= 7; \
        } \
        zend_throw_exception_ex(bytebuf_exception_ce, 0, "This should never happen"); \
    } \
    \
    VAR_INT_METHOD(read##name) { \
        zend_string* zdata; \
        zval* zoffset = NULL; \
        \
        ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 2, 2) \
            Z_PARAM_STR(zdata) \
            Z_PARAM_ZVAL(zoffset) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        char* data = ZSTR_VAL(zdata); \
        size_t data_len = (size_t)ZSTR_LEN(zdata); \
        zend_long offsetLval = Z_LVAL_P(Z_REFVAL_P(zoffset)); \
        size_t offset = (size_t)offsetLval; \
        type value = 0; \
        for (int i = 0; i <= maxloop; i += 7) { \
            if(offset >= data_len) { \
                zend_throw_exception_ex(bytebuf_exception_ce, 0, "No bytes left in buffer"); \
                return; \
            } \
            unsigned char b = data[offset++]; \
            value |= ((b & 0x7f) << i); \
            if ((b & 0x80) == 0) { \
                ZEND_TRY_ASSIGN_REF_LONG(zoffset, offset); \
                if (signed) { \
                    if (maxsize == 5) { \
                        RETURN_LONG(VarIntDecodeZigZag32(value)); \
                    } else { \
                        RETURN_LONG(VarIntDecodeZigZag64(value)); \
                    } \
                } \
                RETURN_LONG(value); \
            } \
        } \
        zend_throw_exception_ex(bytebuf_exception_ce, 0, "VarInt did not terminate after %d bytes!", maxsize); \
    }

VAR_INT_READ_WRITE_METHOD(Int, uint32_t, 5, true, 28)
VAR_INT_READ_WRITE_METHOD(Long, uint64_t, 10, true, 63)
VAR_INT_READ_WRITE_METHOD(UnsignedInt, uint32_t, 5, false, 28)
VAR_INT_READ_WRITE_METHOD(UnsignedLong, uint64_t, 10, false, 63)

void register_var_int_class() {
    zend_class_entry ce;
    ce.ce_flags |= ZEND_ACC_FINAL | ZEND_ACC_NO_DYNAMIC_PROPERTIES;
    INIT_CLASS_ENTRY(ce, "AkmalFairuz\\ByteBuf\\VarInt", var_int_methods);
    var_int_ce = zend_register_internal_class(&ce);
    var_int_ce->create_object = var_int_new;

    memcpy(&var_int_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    var_int_handlers.offset = XtOffsetOf(var_int_obj, std);
    var_int_handlers.free_obj = var_int_free;
}