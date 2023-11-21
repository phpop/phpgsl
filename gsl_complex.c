#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_gsl_complex.h"

#include <gsl/gsl_complex.h>
#include <gsl/gsl_complex_math.h>

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

// Создает массив из 2-х элементов, первый из которых - действит. часть, второй - мнимая часть комплексного числа
#define RETVAL_GSL_COMPLEX(z) do { 	\
	zval real, imag;				\
	array_init_size(return_value, 2); 	\
	ZVAL_DOUBLE(real, GSL_REAL(z));		\
	ZVAL_DOUBLE(imag, GSL_IMAG(z));		\
	zend_hash_next_index_insert_new(Z_ARRVAL_P(return_value), &real);	\
	zend_hash_next_index_insert_new(Z_ARRVAL_P(return_value), &imag);	\
} while (0)

#define RETURN_GSL_COMPLEX(z) RETVAL_GSL_COMPLEX(z); return

// Возвращает gsl_complex из массива [x, iy]
static gsl_complex gslphp_get_zval_complex(zval *z) {
	gsl_complex val;
	double x = 0.0, y = 0.0;
	zval *zp;
	zend_array *zarr;

	zarr = Z_ARRVAL_P(z);

	zp = zend_hash_index_find(zarr, 0); // нулевой элемент - действительная часть
	if (zp != NULL) {
		// Если есть нулевой элемент то приводим его к double
		switch (Z_TYPE_INFO_P(zp)) {
			case IS_DOUBLE:
				x = Z_DVAL_P(zp);
				break;
			case IS_LONG:
				x = (double)Z_LVAL_P(zp);
				break;
			default:
				x = 0.0;
		}
	}

	zp = zend_hash_index_find(zarr, 1); // первый элемент - мнимая часть
	if (zp != NULL) {
		// Если есть первый элемент то приводим его к double
		switch (Z_TYPE_INFO_P(zp)) {
			case IS_DOUBLE:
				y = Z_DVAL_P(zp);
				break;
			case IS_LONG:
				y = (double)Z_LVAL_P(zp);
				break;
			default:
				y = 0.0;
		}
	}

	GSL_SET_COMPLEX(&val, x, y); // устанавливаем значение в комлексное число

	return val;
}

/* {{{ double gsl_real(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_real)
{
	zval *z;
	gsl_complex val;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	val = gslphp_get_zval_complex(z);

	RETURN_DOUBLE(GSL_REAL(val));
}
/* }}} */

/* {{{ double gsl_imag(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_imag)
{
	zval *z;
	gsl_complex val;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	val = gslphp_get_zval_complex(z);

	RETURN_DOUBLE(GSL_IMAG(val));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_rect(double x, double y)
 */
PHP_FUNCTION(gsl_complex_rect)
{
	double x, y;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_GSL_COMPLEX(gsl_complex_rect(x, y));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_polar(double r, double theta)
 */
PHP_FUNCTION(gsl_complex_polar)
{
	double r, theta;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(r)
		Z_PARAM_DOUBLE(theta)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_GSL_COMPLEX(gsl_complex_polar(r, theta));
}
/* }}}*/

/* {{{ double gsl_complex_arg(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arg)
{
	zval *z;
	gsl_complex val;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	val = gslphp_get_zval_complex(z);

	RETURN_DOUBLE(gsl_complex_arg(val));
}
/* }}} */

/* {{{ double gsl_complex_abs(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_abs)
{
	zval *z;
	gsl_complex val;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	val = gslphp_get_zval_complex(z);

	RETURN_DOUBLE(gsl_complex_abs(val));
}
/* }}} */

/* {{{ double gsl_complex_abs2(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_abs2)
{
	zval *z;
	gsl_complex val;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	val = gslphp_get_zval_complex(z);

	RETURN_DOUBLE(gsl_complex_abs2(val));
}
/* }}} */

/* {{{ double gsl_complex_logabs(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_logabs)
{
	zval *z;
	gsl_complex val;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	val = gslphp_get_zval_complex(z);

	RETURN_DOUBLE(gsl_complex_logabs(val));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_add(gsl_complex a, gsl_complex b)
 */
PHP_FUNCTION(gsl_complex_add)
{
	zval *a, *b;
	gsl_complex complex_a, complex_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(a)
		Z_PARAM_ARRAY(b)
	ZEND_PARSE_PARAMETERS_END();

	complex_a = gslphp_get_zval_complex(a);
	complex_b = gslphp_get_zval_complex(b);

	RETURN_GSL_COMPLEX(gsl_complex_add(complex_a, complex_b));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_sub(gsl_complex a, gsl_complex b)
 */
PHP_FUNCTION(gsl_complex_sub)
{
	zval *a, *b;
	gsl_complex complex_a, complex_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(a)
		Z_PARAM_ARRAY(b)
	ZEND_PARSE_PARAMETERS_END();

	complex_a = gslphp_get_zval_complex(a);
	complex_b = gslphp_get_zval_complex(b);

	RETURN_GSL_COMPLEX(gsl_complex_sub(complex_a, complex_b));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_mul(gsl_complex a, gsl_complex b)
 */
PHP_FUNCTION(gsl_complex_mul)
{
	zval *a, *b;
	gsl_complex complex_a, complex_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(a)
		Z_PARAM_ARRAY(b)
	ZEND_PARSE_PARAMETERS_END();

	complex_a = gslphp_get_zval_complex(a);
	complex_b = gslphp_get_zval_complex(b);

	RETURN_GSL_COMPLEX(gsl_complex_mul(complex_a, complex_b));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_div(gsl_complex a, gsl_complex b)
 */
PHP_FUNCTION(gsl_complex_div)
{
	zval *a, *b;
	gsl_complex complex_a, complex_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(a)
		Z_PARAM_ARRAY(b)
	ZEND_PARSE_PARAMETERS_END();

	complex_a = gslphp_get_zval_complex(a);
	complex_b = gslphp_get_zval_complex(b);

	RETURN_GSL_COMPLEX(gsl_complex_div(complex_a, complex_b));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_add_real(gsl_complex z, double x)
 */
PHP_FUNCTION(gsl_complex_add_real)
{
	zval *z;
	double x;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(z)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_add_real(complex_z, x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_sub_real(gsl_complex z, double x)
 */
PHP_FUNCTION(gsl_complex_sub_real)
{
	zval *z;
	double x;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(z)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_sub_real(complex_z, x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_mul_real(gsl_complex z, double x)
 */
PHP_FUNCTION(gsl_complex_mul_real)
{
	zval *z;
	double x;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(z)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_mul_real(complex_z, x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_div_real(gsl_complex z, double x)
 */
PHP_FUNCTION(gsl_complex_div_real)
{
	zval *z;
	double x;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(z)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_div_real(complex_z, x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_add_imag(gsl_complex z, double y)
 */
PHP_FUNCTION(gsl_complex_add_imag)
{
	zval *z;
	double y;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(z)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_add_imag(complex_z, y));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_sub_imag(gsl_complex z, double y)
 */
PHP_FUNCTION(gsl_complex_sub_imag)
{
	zval *z;
	double y;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(z)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_sub_imag(complex_z, y));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_mul_imag(gsl_complex z, double y)
 */
PHP_FUNCTION(gsl_complex_mul_imag)
{
	zval *z;
	double y;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(z)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_mul_imag(complex_z, y));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_div_imag(gsl_complex z, double y)
 */
PHP_FUNCTION(gsl_complex_div_imag)
{
	zval *z;
	double y;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(z)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_div_imag(complex_z, y));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_conjugate(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_conjugate)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_conjugate(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_inverse(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_inverse)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_inverse(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_negative(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_negative)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_negative(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_sqrt(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_sqrt)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_sqrt(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_sqrt_real(double x)
 */
PHP_FUNCTION(gsl_complex_sqrt_real)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_GSL_COMPLEX(gsl_complex_sqrt_real(x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_pow(gsl_complex a, gsl_complex b)
 */
PHP_FUNCTION(gsl_complex_pow)
{
	zval *a, *b;
	gsl_complex complex_a, complex_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(a)
		Z_PARAM_ARRAY(b)
	ZEND_PARSE_PARAMETERS_END();

	complex_a = gslphp_get_zval_complex(a);
	complex_b = gslphp_get_zval_complex(b);

	RETURN_GSL_COMPLEX(gsl_complex_pow(complex_a, complex_b));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_pow_real(gsl_complex z, double x)
 */
PHP_FUNCTION(gsl_complex_pow_real)
{
	zval *z;
	double x;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(z)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_pow_real(complex_z, x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_exp(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_exp)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_exp(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_log(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_log)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_log(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_log10(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_log10)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_log10(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_log_b(gsl_complex a, gsl_complex b)
 */
PHP_FUNCTION(gsl_complex_log_b)
{
	zval *a, *b;
	gsl_complex complex_a, complex_b;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ARRAY(a)
		Z_PARAM_ARRAY(b)
	ZEND_PARSE_PARAMETERS_END();

	complex_a = gslphp_get_zval_complex(a);
	complex_b = gslphp_get_zval_complex(b);

	RETURN_GSL_COMPLEX(gsl_complex_log_b(complex_a, complex_b));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_sin(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_sin)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_sin(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_cos(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_cos)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_cos(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_tan(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_tan)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_tan(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_sec(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_sec)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_sec(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_csc(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_csc)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_csc(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_cot(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_cot)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_cot(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arcsin(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arcsin)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arcsin(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arcsin_real(double x)
 */
PHP_FUNCTION(gsl_complex_arcsin_real)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_GSL_COMPLEX(gsl_complex_arcsin_real(x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arccos(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arccos)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arccos(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arccos_real(double x)
 */
PHP_FUNCTION(gsl_complex_arccos_real)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_GSL_COMPLEX(gsl_complex_arccos_real(x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arcsec(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arcsec)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arcsec(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arcsec_real(double x)
 */
PHP_FUNCTION(gsl_complex_arcsec_real)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_GSL_COMPLEX(gsl_complex_arcsec_real(x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arccsc(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arccsc)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arccsc(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arccsc_real(double x)
 */
PHP_FUNCTION(gsl_complex_arccsc_real)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_GSL_COMPLEX(gsl_complex_arccsc_real(x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arctan(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arctan)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arctan(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arccot(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arccot)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arccot(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_sinh(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_sinh)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_sinh(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_cosh(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_cosh)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_cosh(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_tanh(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_tanh)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_tanh(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_sech(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_sech)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_sech(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_csch(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_csch)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_csch(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_coth(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_coth)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_coth(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arcsinh(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arcsinh)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arcsinh(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arccosh(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arccosh)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arccosh(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arccosh_real(double x)
 */
PHP_FUNCTION(gsl_complex_arccosh_real)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_GSL_COMPLEX(gsl_complex_arccosh_real(x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arctanh(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arctanh)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arctanh(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arctanh_real(double x)
 */
PHP_FUNCTION(gsl_complex_arctanh_real)
{
	double x;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(x)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_GSL_COMPLEX(gsl_complex_arctanh_real(x));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arcsech(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arcsech)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arcsech(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arccsch(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arccsch)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arccsch(complex_z));
}
/* }}} */

/* {{{ gsl_complex gsl_complex_arccoth(gsl_complex z)
 */
PHP_FUNCTION(gsl_complex_arccoth)
{
	zval *z;
	gsl_complex complex_z;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(z)
	ZEND_PARSE_PARAMETERS_END();

	complex_z = gslphp_get_zval_complex(z);

	RETURN_GSL_COMPLEX(gsl_complex_arccoth(complex_z));
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_gsl_complex_2_double_param, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_complex_1_double_param, 0)
	ZEND_ARG_ARRAY_INFO(0, x, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_complex_1_complex_param, 0)
	ZEND_ARG_ARRAY_INFO(0, z, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_complex_2_complex_param, 0)
	ZEND_ARG_ARRAY_INFO(0, a, 0)
	ZEND_ARG_ARRAY_INFO(0, b, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_complex_1_complex_1_double_param, 0)
	ZEND_ARG_ARRAY_INFO(0, z, 0)
	ZEND_ARG_ARRAY_INFO(0, x, 0)
ZEND_END_ARG_INFO()

/* }}} */

/* {{{ gsl_complex_functions[]
 */
static const zend_function_entry gsl_complex_functions[] = {
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

	PHP_FE_END
};
/* }}} */

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(gsl_complex)
{
#if defined(ZTS) && defined(COMPILE_DL_GSL_COMPLEX)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(gsl_complex)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "gsl_complex support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ gsl_complex_module_entry
 */
zend_module_entry gsl_complex_module_entry = {
	STANDARD_MODULE_HEADER,
	"gsl_complex",					/* Extension name */
	gsl_complex_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(gsl_complex),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(gsl_complex),			/* PHP_MINFO - Module info */
	PHP_GSL_COMPLEX_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_GSL_COMPLEX
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(gsl_complex)
#endif
