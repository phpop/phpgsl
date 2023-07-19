/* gsl_math extension for PHP */

#ifndef PHP_GSL_MATH_H
#define PHP_GSL_MATH_H

extern zend_module_entry gsl_math_module_entry;
#define phpext_gsl_math_ptr &gsl_math_module_entry

#define PHP_GSL_MATH_VERSION "0.0.1"

PHP_FUNCTION(gsl_isnan);
PHP_FUNCTION(gsl_isinf);
PHP_FUNCTION(gsl_finite);
PHP_FUNCTION(gsl_log1p);
PHP_FUNCTION(gsl_expm1);
PHP_FUNCTION(gsl_hypot);
PHP_FUNCTION(gsl_hypot3);
PHP_FUNCTION(gsl_acosh);
PHP_FUNCTION(gsl_asinh);
PHP_FUNCTION(gsl_atanh);
PHP_FUNCTION(gsl_ldexp);
PHP_FUNCTION(gsl_frexp);
PHP_FUNCTION(gsl_pow_int);
PHP_FUNCTION(gsl_pow_2);
PHP_FUNCTION(gsl_pow_3);
PHP_FUNCTION(gsl_pow_4);
PHP_FUNCTION(gsl_pow_5);
PHP_FUNCTION(gsl_pow_6);
PHP_FUNCTION(gsl_pow_7);
PHP_FUNCTION(gsl_pow_8);
PHP_FUNCTION(gsl_pow_9);
PHP_FUNCTION(gsl_fcmp);

# if defined(ZTS) && defined(COMPILE_DL_GSL_MATH)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_GSL_MATH_H */
