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


// Создает массив из 2-х элементов, первый из которых - действит. часть, второй - мнимая часть комплексного числа
#define RETVAL_GSL_COMPLEX(z) do { 	\
	zval real, imag;                 \
    array_init_size(return_value, 2); 	\
	ZVAL_DOUBLE(&real, GSL_REAL(z));		\
	ZVAL_DOUBLE(&imag, GSL_IMAG(z));    \
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
                printf("x=%lf\n", x);
    printf("y=%lf\n", y);

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
ZEND_ARG_INFO(0, x)
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
