#include "../lib/ByteBuf.h"
#include "../lib/ByteBufException.h"
#include "ZendUtil.h"
#include "../bytebuf_arginfo.h"
#include "../lib/ByteOrder.h"
#include "../lib/ByteFlipper.h"
#include "../lib/VarInt.h"
#include "Int24Util.h"

extern "C" {
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_exceptions.h"
}

extern zend_class_entry* bytebuf_exception_ce;

zend_class_entry* bytebuf_entry;
static zend_object_handlers bytebuf_handlers;

typedef struct {
    ByteBuf* bytebuf;
    zend_object std;
} bytebuf_obj;

/* new ByteBuf() */
static zend_object* bytebuf_new(zend_class_entry* class_type) {
    auto object = alloc_custom_zend_object<bytebuf_obj>(class_type, &bytebuf_handlers);
    return &object->std;
}

/* clone ByteBuf */
static zend_object* bytebuf_clone(zend_object* object) {
    auto* obj = fetch_from_zend_object<bytebuf_obj>(object);
    auto* new_obj = fetch_from_zend_object<bytebuf_obj>(bytebuf_new(obj->std.ce));

    auto* previousBuf = obj->bytebuf->toString();
    new_obj->bytebuf = ByteBuf::make(previousBuf, obj->bytebuf->getUsedBufferLength());
    new_obj->bytebuf->setOffset(obj->bytebuf->getOffset());
    new_obj->bytebuf->setMaxCapacity(obj->bytebuf->getMaxCapacity());

    delete[] previousBuf;

    return &new_obj->std;
}

/* unset(ByteBuf) */
static void bytebuf_free(zend_object* object) {
    auto obj = fetch_from_zend_object<bytebuf_obj>(object);
    delete obj->bytebuf;
    zend_object_std_dtor(object);
}

#define PHP_BYTEBUF_METHOD(name) PHP_METHOD(AkmalFairuz_ByteBuf_ByteBuf, name)

/* STATIC ByteBuf::alloc(int $capacity) : ByteBuf */
PHP_BYTEBUF_METHOD(alloc) {
    zend_long capacity;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(capacity)
    ZEND_PARSE_PARAMETERS_END();

    auto* object = fetch_from_zend_object<bytebuf_obj>(bytebuf_new(bytebuf_entry));
    object->bytebuf = ByteBuf::make(capacity);

    RETURN_OBJ(&object->std);
}

/* STATIC ByteBuf::fromString(string $buf) : ByteBuf */
PHP_BYTEBUF_METHOD(fromString) {
    zend_string* buf;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(buf)
    ZEND_PARSE_PARAMETERS_END();

    auto* object = fetch_from_zend_object<bytebuf_obj>(bytebuf_new(bytebuf_entry));
    object->bytebuf = ByteBuf::make(reinterpret_cast<uint8_t*>(ZSTR_VAL(buf)), ZSTR_LEN(buf));

    RETURN_OBJ(&object->std);
}

/* ByteBuf::__construct(string $buffer, int $offset) */
PHP_BYTEBUF_METHOD(__construct) {
    zend_string* initialBuffer;
    zend_long offset;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_STR(initialBuffer)
        Z_PARAM_LONG(offset)
    ZEND_PARSE_PARAMETERS_END();

    auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis()));
    auto initialBufferLen = ZSTR_LEN(initialBuffer);
    if(initialBufferLen > 0) {
        object->bytebuf = ByteBuf::make(reinterpret_cast<uint8_t*>(ZSTR_VAL(initialBuffer)), initialBufferLen);
    } else {
        object->bytebuf = ByteBuf::make(64);
    }
    object->bytebuf->setOffset(offset);
}

/* ByteBuf::write(string $buf) : void */
PHP_BYTEBUF_METHOD(write) {
    zend_string* buf;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(buf)
    ZEND_PARSE_PARAMETERS_END();

    auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis()));
    object->bytebuf->write(reinterpret_cast<uint8_t*>(ZSTR_VAL(buf)), ZSTR_LEN(buf));
}

/* ByteBuf::read(int $length) : string */
PHP_BYTEBUF_METHOD(read) {
    zend_long length;

    ZEND_PARSE_PARAMETERS_START_EX(ZEND_PARSE_PARAMS_THROW, 1, 1)
        Z_PARAM_LONG(length)
    ZEND_PARSE_PARAMETERS_END();

    if(length == 0){
        RETURN_STR(zend_empty_string);
    }

    auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis()));

    // Allocate using emalloc for better memory management. 
    // 1.5x faster than ext-encoding ByteBuffer::readByteArray & 2.1x faster than substr() like BinaryUtils did
    uint8_t* buf = static_cast<uint8_t*>(emalloc(length));
    if (!buf) {
        zend_throw_exception_ex(bytebuf_exception_ce, 0, "Failed to allocate memory");
        return;
    }

    try {
        object->bytebuf->read(buf, length);

        // Since RETURN_STRINGL stops execution, we use zend_string_init instead
        zend_string* result = zend_string_init(reinterpret_cast<char*>(buf), length, 0);
        efree(buf);
        RETURN_STR(result);
    } catch (const ByteBufException& e) {
        efree(buf);
        zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what());
        return;
    }
}

/* ByteBuf::setOffset(int $offset) : void */
PHP_BYTEBUF_METHOD(setOffset) {
    zend_long offset;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(offset)
    ZEND_PARSE_PARAMETERS_END();

    auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis()));
    object->bytebuf->setOffset(offset);
}

/* ByteBuf::getOffset() : int */
PHP_BYTEBUF_METHOD(getOffset) {
    auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis()));
    RETURN_LONG(object->bytebuf->getOffset());
}

/* ByteBuf::getUsedBufferLength() : int */
PHP_BYTEBUF_METHOD(getUsedBufferLength) {
    auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis()));
    RETURN_LONG(object->bytebuf->getUsedBufferLength());
}

/* ByteBuf::remaining() : string */
PHP_BYTEBUF_METHOD(remaining) {
    auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis()));
    auto* buf = object->bytebuf->remaining();
    auto len = object->bytebuf->getUsedBufferLength() - object->bytebuf->getOffset();

    RETURN_STRINGL(reinterpret_cast<char*>(buf), len);
}

/* ByteBuf::toString() : string */
PHP_BYTEBUF_METHOD(toString) {
    auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis()));
    auto len = object->bytebuf->getUsedBufferLength();

    RETURN_STRINGL(reinterpret_cast<char*>(object->bytebuf->_buffer), len);
}

/*
 * ByteBuf::writeByte(int $value) : void
 * ByteBuf::writeUnsignedByte(int $value) : void
 * ByteBuf::writeShort(int $value) : void
 * ByteBuf::writeUnsignedShort(int $value) : void
 * ByteBuf::writeLShort(int $value) : void
 * ByteBuf::writeUnsignedLShort(int $value) : void
 * ByteBuf::writeInt(int $value) : void
 * ByteBuf::writeUnsignedInt(int $value) : void
 * ByteBuf::writeLInt(int $value) : void
 * ByteBuf::writeUnsignedLInt(int $value) : void
 * ByteBuf::writeLong(int $value) : void
 * ByteBuf::writeUnsignedLong(int $value) : void
 * ByteBuf::writeLLong(int $value) : void
 * ByteBuf::writeUnsignedLLong(int $value) : void
 * ByteBuf::writeFloat(int $value) : void
 * ByteBuf::writeLFloat(int $value) : void
 * ByteBuf::writeDouble(int $value) : void
 * ByteBuf::writeLDouble(int $value) : void
 * 
 * ByteBuf::readByte() : int
 * ByteBuf::readUnsignedByte() : int
 * ByteBuf::readShort() : int
 * ByteBuf::readUnsignedShort() : int
 * ByteBuf::readLShort() : int
 * ByteBuf::readLUnsignedShort() : int
 * ByteBuf::readInt() : int
 * ByteBuf::readUnsignedInt() : int
 * ByteBuf::readLInt() : int
 * ByteBuf::readLUnsignedInt() : int
 * ByteBuf::readLong() : int
 * ByteBuf::readUnsignedLong() : int
 * ByteBuf::readLLong() : int
 * ByteBuf::readLUnsignedLong() : int
 */
#define BYTEBUF_READ_WRITE_INT(name, type, size) \
    PHP_BYTEBUF_METHOD(write##name) { \
        zend_long value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_LONG(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        auto value2 = static_cast<type>(value); \
        auto* writeBytes = reinterpret_cast<uint8_t*>(&value2); \
        if constexpr(ByteOrder::NATIVE != ByteOrder::BE){ \
            ByteFlipper::flip(writeBytes, size); \
        } \
        try { \
            object->bytebuf->write(writeBytes, size); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
    } \
    \
    PHP_BYTEBUF_METHOD(read##name) { \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        type value; \
        try{ \
            object->bytebuf->read(reinterpret_cast<uint8_t*>(&value), size); \
        }catch (const ByteBufException& e){ \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
        if constexpr(ByteOrder::NATIVE != ByteOrder::BE){ \
            ByteFlipper::flip(reinterpret_cast<uint8_t*>(&value), size); \
        } \
        RETURN_LONG(value); \
    } \
    \
    PHP_BYTEBUF_METHOD(writeL##name) { \
        zend_long value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_LONG(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        auto value2 = static_cast<type>(value); \
        auto* writeBytes = reinterpret_cast<uint8_t*>(&value2); \
        if constexpr(ByteOrder::NATIVE != ByteOrder::LE){ \
            ByteFlipper::flip(writeBytes, size); \
        } \
        try { \
            object->bytebuf->write(writeBytes, size); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
    } \
    \
    PHP_BYTEBUF_METHOD(readL##name) { \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        type value; \
        try { \
            object->bytebuf->read(reinterpret_cast<uint8_t*>(&value), size); \
        }catch (const ByteBufException& e){ \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
        if constexpr(ByteOrder::NATIVE != ByteOrder::LE){ \
            ByteFlipper::flip(reinterpret_cast<uint8_t*>(&value), size); \
        } \
        RETURN_LONG(value); \
    }

BYTEBUF_READ_WRITE_INT(Short, int16_t, 2)
BYTEBUF_READ_WRITE_INT(UnsignedShort, uint16_t, 2)
BYTEBUF_READ_WRITE_INT(Int, int32_t, 4)
BYTEBUF_READ_WRITE_INT(UnsignedInt, uint32_t, 4)
BYTEBUF_READ_WRITE_INT(Long, int64_t, 8)
BYTEBUF_READ_WRITE_INT(UnsignedLong, uint64_t, 8)

/*
 * ByteBuf::writeTriad(int $value) : void
 * ByteBuf::writeUnsignedTriad(int $value) : void
 * ByteBuf::writeLTriad(int $value) : void
 * ByteBuf::writeUnsignedLTriad(int $value) : void
 * 
 * ByteBuf::readTriad() : int
 * ByteBuf::readUnsignedTriad() : int
 * ByteBuf::readLTriad() : int
 * ByteBuf::readLUnsignedTriad() : int
 */
#define BYTEBUF_READ_WRITE_TRIAD(name, type, tobytesfunc, tointfunc) \
    PHP_BYTEBUF_METHOD(write##name) { \
        zend_long value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_LONG(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        auto value2 = static_cast<int32_t>(value); \
        uint8_t writeBytes[3]; \
        tobytesfunc(value2, writeBytes); \
        if constexpr(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(writeBytes, 3); \
        } \
        try { \
            object->bytebuf->write(writeBytes, 3); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
    } \
    \
    PHP_BYTEBUF_METHOD(read##name) { \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        uint8_t buf[3]; \
        try { \
            object->bytebuf->read(buf, 3); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
        if constexpr(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(buf, 3); \
        } \
        type value = 0; \
        tointfunc(buf, &value); \
        RETURN_LONG(value); \
    } \
    \
    PHP_BYTEBUF_METHOD(writeL##name) { \
        zend_long value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_LONG(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        auto value2 = static_cast<int32_t>(value); \
        uint8_t writeBytes[3]; \
        tobytesfunc(value2, writeBytes); \
        if constexpr(ByteOrder::NATIVE != ByteOrder::LE) { \
            ByteFlipper::flip(writeBytes, 3); \
        } \
        try { \
            object->bytebuf->write(writeBytes, 3); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
    } \
    \
    PHP_BYTEBUF_METHOD(readL##name) { \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        uint8_t buf[3]; \
        try { \
            object->bytebuf->read(buf, 3); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
        if constexpr(ByteOrder::NATIVE != ByteOrder::LE) { \
            ByteFlipper::flip(buf, 3); \
        } \
        type value = 0; \
        tointfunc(buf, &value); \
        RETURN_LONG(value); \
    }

BYTEBUF_READ_WRITE_TRIAD(Triad, int32_t, int24_to_bytes, bytes_to_int24)
BYTEBUF_READ_WRITE_TRIAD(UnsignedTriad, uint32_t, uint24_to_bytes, bytes_to_uint24)

/*
 * ByteBuf::readFloat() : float
 * ByteBuf::readLFloat() : float
 * ByteBuf::readDouble() : float
 * ByteBuf::readLDouble() : float
 */
#define BYTEBUF_READ_WRITE_FLOAT(name, type, size) \
    PHP_BYTEBUF_METHOD(write##name) { \
        double value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_DOUBLE(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        type value2 = static_cast<type>(value); \
        auto* writeBytes = reinterpret_cast<uint8_t*>(&value2); \
        if constexpr(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(writeBytes, size); \
        } \
        try { \
            object->bytebuf->write(writeBytes, size); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
    } \
    \
    PHP_BYTEBUF_METHOD(read##name) { \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        type value2; \
        try { \
            object->bytebuf->read(reinterpret_cast<uint8_t*>(&value2), size); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
        if constexpr(ByteOrder::NATIVE != ByteOrder::BE) { \
            ByteFlipper::flip(reinterpret_cast<uint8_t*>(&value2), size); \
        } \
        double value = static_cast<double>(value2); \
        RETURN_DOUBLE(value); \
    } \
    \
    PHP_BYTEBUF_METHOD(writeL##name) { \
        double value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_DOUBLE(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        type value2 = static_cast<type>(value); \
        auto* writeBytes = reinterpret_cast<uint8_t*>(&value2); \
        if constexpr(ByteOrder::NATIVE != ByteOrder::LE) { \
            ByteFlipper::flip(writeBytes, size); \
        } \
        try { \
            object->bytebuf->write(writeBytes, size); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
    } \
    \
    PHP_BYTEBUF_METHOD(readL##name) { \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        type value2; \
        try { \
            object->bytebuf->read(reinterpret_cast<uint8_t*>(&value2), size); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
        if constexpr(ByteOrder::NATIVE != ByteOrder::LE) { \
            ByteFlipper::flip(reinterpret_cast<uint8_t*>(&value2), size); \
        } \
        double value = static_cast<double>(value2); \
        RETURN_DOUBLE(value); \
    }

BYTEBUF_READ_WRITE_FLOAT(Float, float, 4)
BYTEBUF_READ_WRITE_FLOAT(Double, double, 8)

#define BYTEBUF_READ_WRITE_BYTE(name, type) \
    PHP_BYTEBUF_METHOD(write##name) { \
        zend_long value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_LONG(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        auto value2 = static_cast<type>(value); \
        try { \
            object->bytebuf->write(static_cast<uint8_t>(value2)); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
    } \
    \
    PHP_BYTEBUF_METHOD(read##name) { \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        uint8_t value; \
        try { \
            object->bytebuf->read(value); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
        RETURN_LONG(static_cast<type>(value)); \
    }

BYTEBUF_READ_WRITE_BYTE(Byte, int8_t)
BYTEBUF_READ_WRITE_BYTE(UnsignedByte, uint8_t)

#define BYTEBUF_READ_WRITE_VARINT(name, type, writeFunc, readFunc) \
    PHP_BYTEBUF_METHOD(write##name) { \
        zend_long value; \
        ZEND_PARSE_PARAMETERS_START(1, 1) \
            Z_PARAM_LONG(value) \
        ZEND_PARSE_PARAMETERS_END(); \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        auto value2 = static_cast<type>(value); \
        size_t previousOffset = object->bytebuf->_offset; \
        try { \
            VarInt::writeFunc(object->bytebuf->_buffer, object->bytebuf->_offset, value2); \
            object->bytebuf->_usedBufferLength += object->bytebuf->_offset - previousOffset; \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
    } \
    \
    PHP_BYTEBUF_METHOD(read##name) { \
        auto object = fetch_from_zend_object<bytebuf_obj>(Z_OBJ_P(getThis())); \
        type value; \
        try { \
            VarInt::readFunc(object->bytebuf->_buffer, object->bytebuf->_offset, &value); \
        } catch (const ByteBufException& e) { \
            zend_throw_exception_ex(bytebuf_exception_ce, 0, e.what()); \
            return; \
        } \
        RETURN_LONG(value); \
    }

BYTEBUF_READ_WRITE_VARINT(UnsignedVarInt, uint32_t, writeUnsignedInt, readUnsignedInt)
BYTEBUF_READ_WRITE_VARINT(UnsignedVarLong, uint64_t, writeUnsignedLong, readUnsignedLong)
BYTEBUF_READ_WRITE_VARINT(VarInt, int32_t, writeInt, readInt)
BYTEBUF_READ_WRITE_VARINT(VarLong, int64_t, writeLong, readLong)

void register_bytebuf_class() {
    memcpy(&bytebuf_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    bytebuf_handlers.offset = XtOffsetOf(bytebuf_obj, std);
    bytebuf_handlers.free_obj = bytebuf_free;
    bytebuf_handlers.clone_obj = bytebuf_clone;

    zend_class_entry ce;
    INIT_CLASS_ENTRY(ce, "AkmalFairuz\\ByteBuf\\ByteBuf", bytebuf_methods);
    ce.create_object = bytebuf_new;
    bytebuf_entry = zend_register_internal_class(&ce);
    bytebuf_entry->ce_flags |= ZEND_ACC_FINAL;
}