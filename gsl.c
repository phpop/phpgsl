#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_gsl.h"

#include <gsl/gsl_math.h>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ int gsl_isnan(const double x)
 */
PHP_FUNCTION(gsl_isnan)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_LONG(gsl_isnan(x));
}
/* }}} */

/* {{{ int gsl_isinf(const double x)
 */
PHP_FUNCTION(gsl_isinf)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_LONG(gsl_isinf(x));
}
/* }}} */

/* {{{ int gsl_finite(const double x)
 */
PHP_FUNCTION(gsl_finite)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_LONG(gsl_finite(x));
}
/* }}} */

/* {{{ double gsl_log1p(const double x)
 */
PHP_FUNCTION(gsl_log1p)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_log1p(x));
}
/* }}} */

/* {{{ double gsl_expm1(const double x)
 */
PHP_FUNCTION(gsl_expm1)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_expm1(x));
}
/* }}} */

/* {{{ double gsl_hypot(const double x, const double y)
 */
PHP_FUNCTION(gsl_hypot)
{
	double x, y;

	ZEND_PARSE_PARAMETERS_START(2, 2)
	Z_PARAM_DOUBLE(x)
	Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_hypot(x, y));
}
/* }}} */

/* {{{ double gsl_hypot3(const double x, const double y, const double z)
 */
PHP_FUNCTION(gsl_hypot3)
{
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
	Z_PARAM_DOUBLE(x)
	Z_PARAM_DOUBLE(y)
	Z_PARAM_DOUBLE(z)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_hypot3(x, y, z));
}
/* }}} */

/* {{{ double gsl_acosh(const double x)
 */
PHP_FUNCTION(gsl_acosh)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_acosh(x));
}
/* }}} */

/* {{{ double gsl_asinh(const double x)
 */
PHP_FUNCTION(gsl_asinh)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_asinh(x));
}
/* }}} */

/* {{{ double gsl_atanh(const double x)
 */
PHP_FUNCTION(gsl_atanh)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_atanh(x));
}
/* }}} */

/* {{{ double gsl_ldexp(double x, int e)
 */
PHP_FUNCTION(gsl_ldexp)
{
	double x;
	long e;

	ZEND_PARSE_PARAMETERS_START(2, 2)
	Z_PARAM_DOUBLE(x)
	Z_PARAM_LONG(e)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_ldexp(x, e));
}
/* }}} */

/* {{{ double gsl_frexp(double x, int * e)
 */
PHP_FUNCTION(gsl_frexp)
{
	double x;
	long e;

	ZEND_PARSE_PARAMETERS_START(2, 2)
	Z_PARAM_DOUBLE(x)
	Z_PARAM_LONG(e)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_frexp(x, (int *)&e));
}
/* }}} */

/* {{{ double gsl_pow_int(double x, int n)
 */
PHP_FUNCTION(gsl_pow_int)
{
	double x;
	long n;

	ZEND_PARSE_PARAMETERS_START(2, 2)
	Z_PARAM_DOUBLE(x)
	Z_PARAM_LONG(n)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_pow_int(x, n));
}
/* }}} */

/* {{{ double gsl_pow_2(const double x)
 */
PHP_FUNCTION(gsl_pow_2)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_pow_2(x));
}
/* }}} */

/* {{{ double gsl_pow_3(const double x)
 */
PHP_FUNCTION(gsl_pow_3)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_pow_3(x));
}
/* }}} */

/* {{{ double gsl_pow_4(const double x)
 */
PHP_FUNCTION(gsl_pow_4)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_pow_4(x));
}
/* }}} */

/* {{{ double gsl_pow_5(const double x)
 */
PHP_FUNCTION(gsl_pow_5)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_pow_5(x));
}
/* }}} */

/* {{{ double gsl_pow_6(const double x)
 */
PHP_FUNCTION(gsl_pow_6)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_pow_6(x));
}
/* }}} */

/* {{{ double gsl_pow_7(const double x)
 */
PHP_FUNCTION(gsl_pow_7)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_pow_7(x));
}
/* }}} */

/* {{{ double gsl_pow_8(const double x)
 */
PHP_FUNCTION(gsl_pow_8)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_pow_8(x));
}
/* }}} */

/* {{{ double gsl_pow_9(const double x)
 */
PHP_FUNCTION(gsl_pow_9)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
	Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_DOUBLE(gsl_pow_9(x));
}
/* }}} */

/* {{{ int gsl_fcmp(double x, double y, double epsilon)
 */
PHP_FUNCTION(gsl_fcmp)
{
	double x, y, eps;

	ZEND_PARSE_PARAMETERS_START(3, 3)
	Z_PARAM_DOUBLE(x)
	Z_PARAM_DOUBLE(y)
	Z_PARAM_DOUBLE(eps)
	ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

	RETURN_LONG(gsl_fcmp(x, y, eps));
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_isnan, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_isinf, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_finite, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_log1p, 0, 0, 1)
ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_expm1, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_hypot, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_hypot3, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_acosh, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_asinh, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_atanh, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_ldexp, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, e)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_frexp, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, e)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_pow_int, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_pow, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gsl_fcmp, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, eps)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ gsl_functions[]
 */
static const zend_function_entry gsl_functions[] = {
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
