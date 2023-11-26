PHP_ARG_WITH([gsl],
  [for GSL support],
  [AS_HELP_STRING([[--with-gsl[=DIR]]],
    [Include GSL support])])

if test "$PHP_GSL" != "no"; then
  if test -r $PHP_GSL/include/gsl_math.h; then
    GSL_DIR=$PHP_GSL
  else
    AC_MSG_CHECKING(for GSL in default path)
    for i in /usr/local /usr; do
      if test -r $i/include/gsl/gsl_math.h; then
        GSL_DIR=$i
        AC_MSG_RESULT(found in $i)
        break
      fi
    done
  fi

  if test -z "$GSL_DIR"; then
    AC_MSG_RESULT(not found)
    AC_MSG_ERROR(Please reinstall the GSL distribution)
  fi

  LDFLAGS="$LDFLAGS `gsl-config --libs`"

  PHP_CHECK_LIBRARY(gsl, gsl,
  [
    PHP_ADD_INCLUDE($GSL_DIR/include)
    PHP_ADD_LIBRARY_WITH_PATH(gsl, $GSL_DIR/$PHP_LIBDIR, GSL_SHARED_LIBADD)
    AC_DEFINE(HAVE_GSL,1,[ ])
  ],
  [],
  [
    -$LDFLAGS
  ])

  PHP_NEW_EXTENSION(gsl, gsl.c, $ext_shared)
  PHP_SUBST(GSL_SHARED_LIBADD)
fi
