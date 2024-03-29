/* gsl extension for PHP */

#ifndef PHP_GSL_H
#define PHP_GSL_H

extern zend_module_entry gsl_module_entry;
#define phpext_gsl_ptr &gsl_module_entry

#define PHP_GSL_VERSION "0.0.1"

// Mathematical Functions
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
// Complex Numbers
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
// Polynomials
PHP_FUNCTION(gsl_poly_eval);
PHP_FUNCTION(gsl_poly_complex_eval);

# if defined(ZTS) && defined(COMPILE_DL_GSL)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif    /* PHP_GSL_H */
