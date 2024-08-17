/* bytebuf extension for PHP */

#ifndef PHP_BYTEBUF_H
# define PHP_BYTEBUF_H

extern zend_module_entry bytebuf_module_entry;
# define phpext_bytebuf_ptr &bytebuf_module_entry

# define PHP_BYTEBUF_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_BYTEBUF)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_BYTEBUF_H */
