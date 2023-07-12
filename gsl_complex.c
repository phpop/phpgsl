#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_gsl.h"

#include <gsl/gsl_complex.h>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ gsl_complex gsl_complex_rect(double x, double y)
 */
PHP_FUNCTION(gsl_complex_rect)
{
	double x, y;
	gsl_complex z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	z = gsl_complex_rect(x, y);
	
	array_init_size(return_value, 2); // массив из 2-х элементов (действит. и мнимая часть)
	zend_hash_next_index_insert_new(Z_ARRVAL_P(return_value), GSL_REAL(z));
	zend_hash_next_index_insert_new(Z_ARRVAL_P(return_value), GSL_IMAG(z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_polar(double r, double theta)
 */
PHP_FUNCTION(gsl_complex_polar)
{
	double r, theta;
	gsl_complex z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(r)
		Z_PARAM_DOUBLE(theta)
	ZEND_PARSE_PARAMETERS_END();

	z = gsl_complex_polar(r, theta);
	
	array_init_size(return_value, 2); // массив из 2-х элементов (действит. и мнимая часть)
	zend_hash_next_index_insert_new(Z_ARRVAL_P(return_value), GSL_REAL(z));
	zend_hash_next_index_insert_new(Z_ARRVAL_P(return_value), GSL_IMAG(z));
}
/* }}}*/

/* {{{ double gsl_complex_arg(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arg)
{
	zval *z;
	gsl_complex val;
	double x, y;
	double result;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(z)
	ZEND_PARSE_PARAMETERS_END();
	
	if (Z_TYPE_P(z) != IS_ARRAY) {
		php_error_docref(NULL, E_WARNING, "Invalid complex number");
		RETURN_FALSE;
	}

	x = ZVAL_DOUBLE(zend_hash_index_find(z, 0)); // нулевой элемент - действительная часть
	y = ZVAL_DOUBLE(zend_hash_index_find(z, 1)); // первый элемент - мнимая часть
	GSL_SET_COMPLEX(&val, x, y) // устанавливаем значение в комлексное число
	result = gsl_complex_arg(val);
	
	RETURN_DOUBLE(result);
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_gsl_complex_rect, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

	ZEND_ARG_INFO(0, r)
	ZEND_ARG_INFO(0, theta)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_complex_arg, 0)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ gsl_complex_functions[]
 */
static const zend_function_entry gsl_complex_functions[] = {
	PHP_FE(gsl_complex_rect,		arginfo_gsl_complex_rect)
	PHP_FE(gsl_complex_polar,		arginfo_gsl_complex_polar)
	PHP_FE(gsl_complex_arg,		arginfo_gsl_complex_arg)
	PHP_FE_END
};
/* }}} */
