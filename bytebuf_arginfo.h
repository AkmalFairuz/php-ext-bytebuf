/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 54b0ffc3af871b189435266df516f7575c1b9675 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_alloc, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, initialCapacity, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_fromString, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, initialBuffer, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_write, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, buf, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_read, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_setOffset, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_getOffset, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_getUsedBufferLength, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_remaining, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(name, num_args, return_type, return_by_ref, arg_type) \
    ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_##name, 0, num_args, return_type, return_by_ref) \
    	ZEND_ARG_TYPE_INFO(0, value, arg_type, 0) \
    ZEND_END_ARG_INFO() \
	ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, name);

#define BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(name, return_type, return_by_ref) \
    ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_##name, 0, 0, return_type, return_by_ref) \
    ZEND_END_ARG_INFO() \
	ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, name);

/* BYTE */
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeByte, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedByte, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readByte, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readUnsignedByte, IS_LONG, 0);

/* SHORT */
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeShort, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedShort, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readShort, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readUnsignedShort, IS_LONG, 0);

BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLShort, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLUnsignedShort, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLShort, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLUnsignedShort, IS_LONG, 0);

/* TRIAD */
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeTriad, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedTriad, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readTriad, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readUnsignedTriad, IS_LONG, 0);

BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLTriad, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLUnsignedTriad, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLTriad, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLUnsignedTriad, IS_LONG, 0);

/* INT */
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeInt, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedInt, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readInt, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readUnsignedInt, IS_LONG, 0);

BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLInt, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLUnsignedInt, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLInt, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLUnsignedInt, IS_LONG, 0);

/* LONG */
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLong, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedLong, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLong, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readUnsignedLong, IS_LONG, 0);

BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLLong, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLUnsignedLong, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLLong, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLUnsignedLong, IS_LONG, 0);

/* FLOAT */
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeFloat, 1, IS_VOID, 0, IS_DOUBLE);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readFloat, IS_DOUBLE, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLFloat, 1, IS_VOID, 0, IS_DOUBLE);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLFloat, IS_DOUBLE, 0);

/* DOUBLE */
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeDouble, 1, IS_VOID, 0, IS_DOUBLE);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readDouble, IS_DOUBLE, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeLDouble, 1, IS_VOID, 0, IS_DOUBLE);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readLDouble, IS_DOUBLE, 0);

/* VAR INT */
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeVarInt, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedVarInt, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeVarLong, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedVarLong, 1, IS_VOID, 0, IS_LONG);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readVarInt, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readUnsignedVarInt, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readVarLong, IS_LONG, 0);
BYTEBUF_ARG_WITH_RETURN_TYPE_INFO_NO_ARG(readUnsignedVarLong, IS_LONG, 0);

/* LITTLE ENDIAN CLASS CLASS */
#define ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(name, return_type, arg_type) \
    ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_LE_##name, 0, 1, return_type, 0) \
        ZEND_ARG_TYPE_INFO(0, value, arg_type, 0) \
    ZEND_END_ARG_INFO() \
	ZEND_METHOD(AkmalFairuz_ByteBuf_LE, name); \
	\
	ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_BE_##name, 0, 1, return_type, 0) \
		ZEND_ARG_TYPE_INFO(0, value, arg_type, 0) \
    ZEND_END_ARG_INFO() \
	ZEND_METHOD(AkmalFairuz_ByteBuf_BE, name);

ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeShort, IS_STRING, IS_LONG)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readShort, IS_LONG, IS_STRING)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedShort, IS_STRING, IS_LONG)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readUnsignedShort, IS_LONG, IS_STRING)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeTriad, IS_STRING, IS_LONG)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readTriad, IS_LONG, IS_STRING)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedTriad, IS_STRING, IS_LONG)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readUnsignedTriad, IS_LONG, IS_STRING)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeInt, IS_STRING, IS_LONG)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readInt, IS_LONG, IS_STRING)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedInt, IS_STRING, IS_LONG)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readUnsignedInt, IS_LONG, IS_STRING)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeLong, IS_STRING, IS_LONG)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readLong, IS_LONG, IS_STRING)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeUnsignedLong, IS_STRING, IS_LONG)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readUnsignedLong, IS_LONG, IS_STRING)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeFloat, IS_STRING, IS_DOUBLE)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readFloat, IS_DOUBLE, IS_STRING)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(writeDouble, IS_STRING, IS_DOUBLE)
ENDIAN_ARG_WITH_RETURN_TYPE_INFO_EX(readDouble, IS_DOUBLE, IS_STRING)

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_LE___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_BE___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(AkmalFairuz_ByteBuf_LE, __construct);
ZEND_METHOD(AkmalFairuz_ByteBuf_BE, __construct);

/* VAR INT CLASS */
#define VAR_INT_READ_ARG(arg_name, type, offset_type) \
    ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_VarInt_##arg_name, 0, 2, IS_LONG, 0) \
		ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0) \
		ZEND_ARG_TYPE_INFO(1, offset, offset_type, 0) \
    ZEND_END_ARG_INFO(); \
	ZEND_METHOD(AkmalFairuz_ByteBuf_VarInt, arg_name);

#define VAR_INT_WRITE_ARG(arg_name) \
    ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_VarInt_##arg_name, 0, 1, IS_STRING, 0) \
    	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0) \
    ZEND_END_ARG_INFO() \
	ZEND_METHOD(AkmalFairuz_ByteBuf_VarInt, arg_name);

VAR_INT_WRITE_ARG(writeInt)
VAR_INT_WRITE_ARG(writeUnsignedInt)
VAR_INT_WRITE_ARG(writeLong)
VAR_INT_WRITE_ARG(writeUnsignedLong)

VAR_INT_READ_ARG(readInt, IS_STRING, IS_LONG)
VAR_INT_READ_ARG(readUnsignedInt, IS_STRING, IS_LONG)
VAR_INT_READ_ARG(readLong, IS_STRING, IS_LONG)
VAR_INT_READ_ARG(readUnsignedLong, IS_STRING, IS_LONG)

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_AkmalFairuz_ByteBuf_VarInt___construct, 0, 0, 0)
ZEND_END_ARG_INFO()
ZEND_METHOD(AkmalFairuz_ByteBuf_VarInt, __construct);

ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, alloc);
ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, fromString);
ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, __construct);
ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, write);
ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, read);
ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, setOffset);
ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, getOffset);
ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, getUsedBufferLength);
ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, remaining);
ZEND_METHOD(AkmalFairuz_ByteBuf_ByteBuf, toString);

static const zend_function_entry bytebuf_methods[] = {
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, alloc, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_alloc, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, fromString, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_fromString, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, __construct, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf___construct, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, write, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_write, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, read, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_read, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, setOffset, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_setOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, getOffset, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_getOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, getUsedBufferLength, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_getUsedBufferLength, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, remaining, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_remaining, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, toString, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_toString, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeByte, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeByte, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeUnsignedByte, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeUnsignedByte, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readByte, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readByte, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readUnsignedByte, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readUnsignedByte, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeShort, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeShort, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeUnsignedShort, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeUnsignedShort, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readShort, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readShort, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readUnsignedShort, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readUnsignedShort, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLShort, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLShort, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLUnsignedShort, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLUnsignedShort, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLShort, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLShort, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLUnsignedShort, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLUnsignedShort, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeTriad, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeTriad, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeUnsignedTriad, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeUnsignedTriad, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readTriad, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readTriad, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readUnsignedTriad, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readUnsignedTriad, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLTriad, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLTriad, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLUnsignedTriad, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLUnsignedTriad, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLTriad, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLTriad, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLUnsignedTriad, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLUnsignedTriad, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeUnsignedInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readUnsignedInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLUnsignedInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLUnsignedInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeUnsignedLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readUnsignedLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLUnsignedLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLUnsignedLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeFloat, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeFloat, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readFloat, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readFloat, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLFloat, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLFloat, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLFloat, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLFloat, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeDouble, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeDouble, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readDouble, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readDouble, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeLDouble, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeLDouble, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readLDouble, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readLDouble, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeVarInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeVarInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeUnsignedVarInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeUnsignedVarInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeVarLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeVarLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, writeUnsignedVarLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_writeUnsignedVarLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readVarInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readVarInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readUnsignedVarInt, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readUnsignedVarInt, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readVarLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readVarLong, ZEND_ACC_PUBLIC)
	ZEND_ME(AkmalFairuz_ByteBuf_ByteBuf, readUnsignedVarLong, arginfo_class_AkmalFairuz_ByteBuf_ByteBuf_readUnsignedVarLong, ZEND_ACC_PUBLIC)

	ZEND_FE_END
};

static const zend_function_entry le_methods[] = {
	ZEND_ME(AkmalFairuz_ByteBuf_LE, __construct, arginfo_class_AkmalFairuz_ByteBuf_LE___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeShort, arginfo_class_AkmalFairuz_ByteBuf_LE_writeShort, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readShort, arginfo_class_AkmalFairuz_ByteBuf_LE_readShort, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeUnsignedShort, arginfo_class_AkmalFairuz_ByteBuf_LE_writeUnsignedShort, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readUnsignedShort, arginfo_class_AkmalFairuz_ByteBuf_LE_readUnsignedShort, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeTriad, arginfo_class_AkmalFairuz_ByteBuf_LE_writeTriad, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readTriad, arginfo_class_AkmalFairuz_ByteBuf_LE_readTriad, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeUnsignedTriad, arginfo_class_AkmalFairuz_ByteBuf_LE_writeUnsignedTriad, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readUnsignedTriad, arginfo_class_AkmalFairuz_ByteBuf_LE_readUnsignedTriad, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeInt, arginfo_class_AkmalFairuz_ByteBuf_LE_writeInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readInt, arginfo_class_AkmalFairuz_ByteBuf_LE_readInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_LE_writeUnsignedInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_LE_readUnsignedInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeLong, arginfo_class_AkmalFairuz_ByteBuf_LE_writeLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readLong, arginfo_class_AkmalFairuz_ByteBuf_LE_readLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_LE_writeUnsignedLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_LE_readUnsignedLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeFloat, arginfo_class_AkmalFairuz_ByteBuf_LE_writeFloat, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readFloat, arginfo_class_AkmalFairuz_ByteBuf_LE_readFloat, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, writeDouble, arginfo_class_AkmalFairuz_ByteBuf_LE_writeDouble, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_LE, readDouble, arginfo_class_AkmalFairuz_ByteBuf_LE_readDouble, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry be_methods[] = {
	ZEND_ME(AkmalFairuz_ByteBuf_BE, __construct, arginfo_class_AkmalFairuz_ByteBuf_BE___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeShort, arginfo_class_AkmalFairuz_ByteBuf_BE_writeShort, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readShort, arginfo_class_AkmalFairuz_ByteBuf_BE_readShort, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeUnsignedShort, arginfo_class_AkmalFairuz_ByteBuf_BE_writeUnsignedShort, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readUnsignedShort, arginfo_class_AkmalFairuz_ByteBuf_BE_readUnsignedShort, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeTriad, arginfo_class_AkmalFairuz_ByteBuf_BE_writeTriad, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readTriad, arginfo_class_AkmalFairuz_ByteBuf_BE_readTriad, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeUnsignedTriad, arginfo_class_AkmalFairuz_ByteBuf_BE_writeUnsignedTriad, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readUnsignedTriad, arginfo_class_AkmalFairuz_ByteBuf_BE_readUnsignedTriad, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeInt, arginfo_class_AkmalFairuz_ByteBuf_BE_writeInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readInt, arginfo_class_AkmalFairuz_ByteBuf_BE_readInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_BE_writeUnsignedInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_BE_readUnsignedInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeLong, arginfo_class_AkmalFairuz_ByteBuf_BE_writeLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readLong, arginfo_class_AkmalFairuz_ByteBuf_BE_readLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_BE_writeUnsignedLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_BE_readUnsignedLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeFloat, arginfo_class_AkmalFairuz_ByteBuf_BE_writeFloat, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readFloat, arginfo_class_AkmalFairuz_ByteBuf_BE_readFloat, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, writeDouble, arginfo_class_AkmalFairuz_ByteBuf_BE_writeDouble, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_BE, readDouble, arginfo_class_AkmalFairuz_ByteBuf_BE_readDouble, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry var_int_methods[] = {
	ZEND_ME(AkmalFairuz_ByteBuf_VarInt, __construct, arginfo_class_AkmalFairuz_ByteBuf_VarInt___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(AkmalFairuz_ByteBuf_VarInt, writeUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_VarInt_writeUnsignedInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_VarInt, writeUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_VarInt_writeUnsignedLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_VarInt, readUnsignedInt, arginfo_class_AkmalFairuz_ByteBuf_VarInt_readUnsignedInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_VarInt, readUnsignedLong, arginfo_class_AkmalFairuz_ByteBuf_VarInt_readUnsignedLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_VarInt, writeInt, arginfo_class_AkmalFairuz_ByteBuf_VarInt_writeInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_VarInt, readInt, arginfo_class_AkmalFairuz_ByteBuf_VarInt_readInt, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_VarInt, writeLong, arginfo_class_AkmalFairuz_ByteBuf_VarInt_writeLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_ME(AkmalFairuz_ByteBuf_VarInt, readLong, arginfo_class_AkmalFairuz_ByteBuf_VarInt_readLong, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	ZEND_FE_END
};