#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "Zend/zend_hash.h"
#include "php_gsl.h"

#include <gsl/gsl_math.h>
#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>
#include <gsl/gsl_poly.h>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

#include "gsl_math.c"
#include "gsl_complex.c"
#include "gsl_poly.c"

/* {{{ gsl_functions[]
 */
static const zend_function_entry gsl_functions[] = {
    // math
	PHP_FE(gsl_isnan,		arginfo_gsl_isnan)
	PHP_FE(gsl_isinf,		arginfo_gsl_isinf)
	PHP_FE(gsl_finite,		arginfo_gsl_finite)
	PHP_FE(gsl_log1p,		arginfo_gsl_log1p)
	PHP_FE(gsl_expm1,		arginfo_gsl_expm1)
	PHP_FE(gsl_hypot,		arginfo_gsl_hypot)
	PHP_FE(gsl_hypot3,		arginfo_gsl_hypot3)
	PHP_FE(gsl_acosh,		arginfo_gsl_acosh)
	PHP_FE(gsl_asinh,		arginfo_gsl_asinh)
	PHP_FE(gsl_atanh,		arginfo_gsl_atanh)
	PHP_FE(gsl_ldexp,		arginfo_gsl_ldexp)
	PHP_FE(gsl_frexp,		arginfo_gsl_frexp)
	PHP_FE(gsl_pow_int,		arginfo_gsl_pow_int)
	PHP_FE(gsl_pow_2,		arginfo_gsl_pow)
	PHP_FE(gsl_pow_3,		arginfo_gsl_pow)
	PHP_FE(gsl_pow_4,		arginfo_gsl_pow)
	PHP_FE(gsl_pow_5,		arginfo_gsl_pow)
	PHP_FE(gsl_pow_6,		arginfo_gsl_pow)
	PHP_FE(gsl_pow_7,		arginfo_gsl_pow)
	PHP_FE(gsl_pow_8,		arginfo_gsl_pow)
	PHP_FE(gsl_pow_9,		arginfo_gsl_pow)
	PHP_FE(gsl_fcmp,		arginfo_gsl_fcmp)
    // complex
    // 5.2 Complex number macros
    PHP_FE(gsl_complex_real,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_imag,			arginfo_gsl_complex_1_complex_param)

    // 5.3 Assigning complex numbers
    PHP_FE(gsl_complex_rect,		arginfo_gsl_complex_2_double_param)
    PHP_FE(gsl_complex_polar,		arginfo_gsl_complex_2_double_param)

    // 5.4 Properties of complex numbers
    PHP_FE(gsl_complex_arg,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_abs,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_abs2,		arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_logabs,		arginfo_gsl_complex_1_complex_param)

    // 5.5 Complex arithmetic operators
    PHP_FE(gsl_complex_add,			arginfo_gsl_complex_2_complex_param)
    PHP_FE(gsl_complex_sub,			arginfo_gsl_complex_2_complex_param)
    PHP_FE(gsl_complex_mul,			arginfo_gsl_complex_2_complex_param)
    PHP_FE(gsl_complex_div,			arginfo_gsl_complex_2_complex_param)

    PHP_FE(gsl_complex_add_real,	arginfo_gsl_complex_1_complex_1_double_param)
    PHP_FE(gsl_complex_sub_real,	arginfo_gsl_complex_1_complex_1_double_param)
    PHP_FE(gsl_complex_mul_real,	arginfo_gsl_complex_1_complex_1_double_param)
    PHP_FE(gsl_complex_div_real,	arginfo_gsl_complex_1_complex_1_double_param)

    PHP_FE(gsl_complex_add_imag,	arginfo_gsl_complex_1_complex_1_double_param)
    PHP_FE(gsl_complex_sub_imag,	arginfo_gsl_complex_1_complex_1_double_param)
    PHP_FE(gsl_complex_mul_imag,	arginfo_gsl_complex_1_complex_1_double_param)
    PHP_FE(gsl_complex_div_imag,	arginfo_gsl_complex_1_complex_1_double_param)

    PHP_FE(gsl_complex_conjugate,	arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_inverse,		arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_negative,	arginfo_gsl_complex_1_complex_param)

    // 5.6 Elementary Complex Functions
    PHP_FE(gsl_complex_sqrt,		arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_sqrt_real,	arginfo_gsl_complex_1_double_param)
    PHP_FE(gsl_complex_pow,			arginfo_gsl_complex_2_complex_param)
    PHP_FE(gsl_complex_pow_real,	arginfo_gsl_complex_1_complex_1_double_param)
    PHP_FE(gsl_complex_exp,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_log,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_log10,		arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_log_b,		arginfo_gsl_complex_2_complex_param)

    // 5.7 Complex Trigonometric Functions
    PHP_FE(gsl_complex_sin,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_cos,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_tan,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_sec,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_csc,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_cot,			arginfo_gsl_complex_1_complex_param)

    // 5.8 Inverse Complex Trigonometric Functions
    PHP_FE(gsl_complex_arcsin,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arcsin_real,		arginfo_gsl_complex_1_double_param)
    PHP_FE(gsl_complex_arccos,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arccos_real,		arginfo_gsl_complex_1_double_param)
    PHP_FE(gsl_complex_arcsec,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arcsec_real,		arginfo_gsl_complex_1_double_param)
    PHP_FE(gsl_complex_arccsc,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arccsc_real,		arginfo_gsl_complex_1_double_param)
    PHP_FE(gsl_complex_arctan,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arccot,			arginfo_gsl_complex_1_complex_param)

    // 5.9 Complex Hyperbolic Functions
    PHP_FE(gsl_complex_sinh,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_cosh,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_tanh,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_sech,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_csch,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_coth,			arginfo_gsl_complex_1_complex_param)

    // 5.10 Inverse Complex Hyperbolic Functions
    PHP_FE(gsl_complex_arcsinh,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arccosh,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arccosh_real,	arginfo_gsl_complex_1_double_param)
    PHP_FE(gsl_complex_arctanh,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arctanh_real,	arginfo_gsl_complex_1_double_param)
    PHP_FE(gsl_complex_arcsech,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arccsch,			arginfo_gsl_complex_1_complex_param)
    PHP_FE(gsl_complex_arccoth,			arginfo_gsl_complex_1_complex_param)

    // polynomials
    PHP_FE(gsl_poly_eval,			arginfo_gsl_poly_eval)
    PHP_FE(gsl_poly_complex_eval,	arginfo_gsl_poly_complex_eval)

    PHP_FE_END
};
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(gsl)
{
#if defined(ZTS) && defined(COMPILE_DL_GSL)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(gsl)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "gsl support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ gsl_module_entry
 */
zend_module_entry gsl_module_entry = {
	STANDARD_MODULE_HEADER,
	"gsl",					/* Extension name */
	gsl_functions,			/* zend_function_entry */
	NULL,						/* PHP_MINIT - Module initialization */
	NULL,						/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(gsl),		/* PHP_RINIT - Request initialization */
	NULL,						/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(gsl),		/* PHP_MINFO - Module info */
	PHP_GSL_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GSL
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(gsl)
#endif
