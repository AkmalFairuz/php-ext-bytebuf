/* bytebuf extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

extern "C" {
#include "php.h"
#include "ext/standard/info.h"
#include "php_bytebuf.h"
#include "ext/spl/spl_exceptions.h"
#include "bytebuf_arginfo.h"
}

#include "src/PhpByteBuf.h"
#include "src/PhpLittleEndian.h"
#include "src/PhpBigEndian.h"
#include "src/ByteBufException.h"
#include "src/PhpVarInt.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

zend_class_entry* bytebuf_exception_ce;

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(bytebuf)
{
	bytebuf_exception_ce = register_bytebuf_exception(spl_ce_RuntimeException);

	register_bytebuf_class();
	register_little_endian_class();
	register_big_endian_class();
	register_var_int_class();
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(bytebuf)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "bytebuf support", "enabled");
	php_info_print_table_end();
}
/* }}} */

static const zend_module_dep module_dependencies[] = {
	ZEND_MOD_REQUIRED("spl")
	ZEND_MOD_END
};

/* {{{ bytebuf_module_entry */
zend_module_entry bytebuf_module_entry = {
	STANDARD_MODULE_HEADER_EX,      /* Standard ext module header */
	NULL,						    /* module_init */
	module_dependencies,			/* Module dependencies */
	"bytebuf",					    /* Extension name */
	NULL,					        /* zend_function_entry */
	PHP_MINIT(bytebuf),				/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	NULL,			                /* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(bytebuf),			    /* PHP_MINFO - Module info */
	PHP_BYTEBUF_VERSION,		    /* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_BYTEBUF
extern "C" {
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(bytebuf)
}
#endif
