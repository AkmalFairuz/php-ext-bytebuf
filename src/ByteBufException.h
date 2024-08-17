static const zend_function_entry class_bytebuf_exception_methods[] = {
	ZEND_FE_END
};

static zend_class_entry *register_bytebuf_exception(zend_class_entry *class_entry_RuntimeException) {
	zend_class_entry ce_parent, *class_entry_parent;

	/* Fix class_alias() broken on PHP8.1, so we use register the class here */
	INIT_NS_CLASS_ENTRY(ce_parent, "pocketmine\\utils", "BinaryDataException", class_bytebuf_exception_methods);
	class_entry_parent = zend_register_internal_class_ex(&ce_parent, class_entry_RuntimeException);

	zend_class_entry ce, *class_entry;

	INIT_NS_CLASS_ENTRY(ce, "AkmalFairuz\\ByteBuf", "ByteBufException", class_bytebuf_exception_methods);
	//class_entry = zend_register_internal_class_ex(&ce, class_entry_RuntimeException);
	class_entry = zend_register_internal_class_ex(&ce, class_entry_parent);
	class_entry->ce_flags |= ZEND_ACC_FINAL;

	return class_entry;
}