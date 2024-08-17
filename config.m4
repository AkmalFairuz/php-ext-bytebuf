PHP_ARG_ENABLE([bytebuf],
  [whether to enable bytebuf support],
  [AS_HELP_STRING([--enable-bytebuf],
    [Enable bytebuf support])],
  [no])

if test "$PHP_BYTEBUF" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, BYTEBUF_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-bytebuf -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/bytebuf.h"  # you most likely want to change this
  dnl if test -r $PHP_BYTEBUF/$SEARCH_FOR; then # path given as parameter
  dnl   BYTEBUF_DIR=$PHP_BYTEBUF
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for bytebuf files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       BYTEBUF_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$BYTEBUF_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the bytebuf distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-bytebuf -> add include path
  dnl PHP_ADD_INCLUDE($BYTEBUF_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-bytebuf -> check for lib and symbol presence
  dnl LIBNAME=BYTEBUF # you may want to change this
  dnl LIBSYMBOL=BYTEBUF # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_BYTEBUF_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your bytebuf library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $BYTEBUF_DIR/$PHP_LIBDIR, BYTEBUF_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_BYTEBUF_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your bytebuf library.])
  dnl ],[
  dnl   -L$BYTEBUF_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(BYTEBUF_SHARED_LIBADD)

  dnl In case of no dependencies

  PHP_REQUIRE_CXX()

  AC_DEFINE(HAVE_BYTEBUF, 1, [ Have bytebuf support ])

  PHP_NEW_EXTENSION(bytebuf, bytebuf.cpp lib/ByteBuf.cpp lib/ByteFlipper.cpp lib/VarInt.cpp src/PhpByteBuf.cpp src/PhpBigEndian.cpp src/PhpLittleEndian.cpp src/Int24Util.cpp src/PhpVarInt.cpp, $ext_shared,,-std=c++17, yes)
  PHP_ADD_BUILD_DIR($ext_builddir/lib, 1)
  PHP_ADD_BUILD_DIR($ext_builddir/src, 1)
  dnl PHP_ADD_INCLUDE($ext_builddir)
fi
