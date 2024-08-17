#include "PhpVarInt.h"
#include "../bytebuf_arginfo.h"
#include "ZendUtil.h"
#include "../lib/VarInt.h"
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

#define VAR_INT_READ_WRITE_METHOD(name, type, maxsize) \
    VAR_INT_METHOD(write##name) { \
        zend_long value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_LONG(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        auto value2 = static_cast<type>(value); \
        uint8_t retBuf[maxsize]; \
        size_t offset = 0; \
        VarInt::write##name(retBuf, offset, value2); \
        \
        RETURN_STRINGL(reinterpret_cast<char*>(retBuf), offset); \
    } \
    \
    VAR_INT_METHOD(read##name) { \
        zend_string *bufferz; \
        zval *offsetz; \
        ZEND_PARSE_PARAMETERS_START(2, 2) \
            Z_PARAM_STR(bufferz) \
            Z_PARAM_ZVAL(offsetz) \
        ZEND_PARSE_PARAMETERS_END(); \
        \
        auto buffer = reinterpret_cast<uint8_t*>(ZSTR_VAL(bufferz)); \
        size_t offset = Z_LVAL_P(Z_REFVAL_P(offsetz)); \
        type retValue = 0; \
        try { \
            VarInt::read##name(buffer, offset, &retValue); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
        ZEND_TRY_ASSIGN_REF_LONG(offsetz, offset); \
        \
        RETURN_LONG(retValue); \
    }

VAR_INT_READ_WRITE_METHOD(Int, int32_t, 5)
VAR_INT_READ_WRITE_METHOD(Long, int64_t, 10)
VAR_INT_READ_WRITE_METHOD(UnsignedInt, uint32_t, 5)
VAR_INT_READ_WRITE_METHOD(UnsignedLong, uint64_t, 10)

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