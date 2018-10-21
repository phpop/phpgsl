/* gsl extension for PHP */

#ifndef PHP_GSL_H
# define PHP_GSL_H

extern zend_module_entry gsl_module_entry;
# define phpext_gsl_ptr &gsl_module_entry

# define PHP_GSL_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_GSL)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_GSL_H */

