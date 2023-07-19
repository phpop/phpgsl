/* gsl_complex extension for PHP */

#ifndef PHP_GSL_COMPLEX_H
#define PHP_GSL_COMPLEX_H

extern zend_module_entry gsl_complex_module_entry;
#define phpext_gsl_complex_ptr &gsl_complex_module_entry

#define PHP_GSL_COMPLEX_VERSION "0.0.1"

PHP_FUNCTION(gsl_complex_real);
PHP_FUNCTION(gsl_complex_imag);
PHP_FUNCTION(gsl_complex_rect);
PHP_FUNCTION(gsl_complex_polar);
PHP_FUNCTION(gsl_complex_arg);
PHP_FUNCTION(gsl_complex_abs);
PHP_FUNCTION(gsl_complex_abs2);
PHP_FUNCTION(gsl_complex_logabs);
PHP_FUNCTION(gsl_complex_add);
PHP_FUNCTION(gsl_complex_sub);
PHP_FUNCTION(gsl_complex_mul);
PHP_FUNCTION(gsl_complex_div);
PHP_FUNCTION(gsl_complex_add_real);
PHP_FUNCTION(gsl_complex_sub_real);
PHP_FUNCTION(gsl_complex_mul_real);
PHP_FUNCTION(gsl_complex_div_real);
PHP_FUNCTION(gsl_complex_add_imag);
PHP_FUNCTION(gsl_complex_sub_imag);
PHP_FUNCTION(gsl_complex_mul_imag);
PHP_FUNCTION(gsl_complex_div_imag);
PHP_FUNCTION(gsl_complex_conjugate);
PHP_FUNCTION(gsl_complex_inverse);
PHP_FUNCTION(gsl_complex_negative);
PHP_FUNCTION(gsl_complex_sqrt);
PHP_FUNCTION(gsl_complex_sqrt_real);
PHP_FUNCTION(gsl_complex_pow);
PHP_FUNCTION(gsl_complex_pow_real);
PHP_FUNCTION(gsl_complex_exp);
PHP_FUNCTION(gsl_complex_log);
PHP_FUNCTION(gsl_complex_log10);
PHP_FUNCTION(gsl_complex_log_b);
PHP_FUNCTION(gsl_complex_sin);
PHP_FUNCTION(gsl_complex_cos);
PHP_FUNCTION(gsl_complex_tan);
PHP_FUNCTION(gsl_complex_sec);
PHP_FUNCTION(gsl_complex_csc);
PHP_FUNCTION(gsl_complex_cot);
PHP_FUNCTION(gsl_complex_arcsin);
PHP_FUNCTION(gsl_complex_arcsin_real);
PHP_FUNCTION(gsl_complex_arccos);
PHP_FUNCTION(gsl_complex_arccos_real);
PHP_FUNCTION(gsl_complex_arcsec);
PHP_FUNCTION(gsl_complex_arcsec_real);
PHP_FUNCTION(gsl_complex_arccsc);
PHP_FUNCTION(gsl_complex_arccsc_real);
PHP_FUNCTION(gsl_complex_arctan);
PHP_FUNCTION(gsl_complex_arccot);
PHP_FUNCTION(gsl_complex_sinh);
PHP_FUNCTION(gsl_complex_cosh);
PHP_FUNCTION(gsl_complex_tanh);
PHP_FUNCTION(gsl_complex_sech);
PHP_FUNCTION(gsl_complex_csch);
PHP_FUNCTION(gsl_complex_coth);
PHP_FUNCTION(gsl_complex_arcsinh);
PHP_FUNCTION(gsl_complex_arccosh);
PHP_FUNCTION(gsl_complex_arccosh_real);
PHP_FUNCTION(gsl_complex_arctanh);
PHP_FUNCTION(gsl_complex_arctanh_real);
PHP_FUNCTION(gsl_complex_arcsech);
PHP_FUNCTION(gsl_complex_arccsch);
PHP_FUNCTION(gsl_complex_arccoth);

# if defined(ZTS) && defined(COMPILE_DL_GSL_COMPLEX)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_GSL_COMPLEX_H */
