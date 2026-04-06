#ifndef PHP_GSL_POLY_C
#define PHP_GSL_POLY_C

#include <gsl/gsl_poly.h>
#include <gsl/gsl_errno.h>

/* {{{ double gsl_poly_eval(const double c[], const int len, const double x)
 */

PHP_FUNCTION(gsl_poly_eval)
{
        double x;
        zval    *array,                         /* array to check in */
                *entry;                         /* pointer to array entry */
        zend_ulong num_idx;
        zend_string *str_idx;

        ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_ARRAY(array)
        Z_PARAM_DOUBLE(x)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        HashTable *target_hash = HASH_OF(array);
        int len = zend_hash_num_elements(target_hash);
        double c[len];

        ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(array), num_idx, str_idx, entry) {
            ZVAL_DEREF(entry);
            if (Z_TYPE_P(entry) == IS_LONG) {
                c[num_idx] = Z_LVAL_P(entry);
            } else if (Z_TYPE_P(entry) == IS_DOUBLE) {
                c[num_idx] = Z_DVAL_P(entry);
            }
        } ZEND_HASH_FOREACH_END();

        RETURN_DOUBLE(gsl_poly_eval(c, len, x));
}
/* }}} */

/* {{{ gsl_complex gsl_poly_complex_eval(const double c[], const int len, const gsl_complex z)
 */

PHP_FUNCTION(gsl_poly_complex_eval)
{
        zval    *array,
                *entry,
                *z;
        zend_ulong num_idx;
        zend_string *str_idx;
        gsl_complex val_z;


        ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_ARRAY(array)
        Z_PARAM_ARRAY(z)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        HashTable *target_hash = HASH_OF(array);
        int len = zend_hash_num_elements(target_hash);
        double c[len];

        val_z = gslphp_get_zval_complex(z);

        ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(array), num_idx, str_idx, entry) {
            ZVAL_DEREF(entry);
            if (Z_TYPE_P(entry) == IS_LONG) {
                c[num_idx] = Z_LVAL_P(entry);
            } else if (Z_TYPE_P(entry) == IS_DOUBLE) {
                c[num_idx] = Z_DVAL_P(entry);
            }
        } ZEND_HASH_FOREACH_END();

        RETURN_GSL_COMPLEX(gsl_poly_complex_eval(c, len, val_z));
}
/* }}} */

/* {{{ int gsl_poly_solve_quadratic(double a, double b, double c, double *x0, double *x1)
 */

PHP_FUNCTION(gsl_poly_solve_quadratic)
{
        double a, b, c;
        double x0 = 0.0, x1 = 0.0;
        int roots;

        ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_DOUBLE(a)
        Z_PARAM_DOUBLE(b)
        Z_PARAM_DOUBLE(c)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        roots = gsl_poly_solve_quadratic(a, b, c, &x0, &x1);

        array_init(return_value);
        add_index_long(return_value, 0, roots);
        add_index_double(return_value, 1, x0);
        add_index_double(return_value, 2, x1);
}
/* }}} */

/* {{{ int gsl_poly_complex_solve_quadratic(double a, double b, double c, gsl_complex *z0, gsl_complex *z1)
 */

PHP_FUNCTION(gsl_poly_complex_solve_quadratic)
{
        double a, b, c;
        gsl_complex z0, z1;
        int roots;

        ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_DOUBLE(a)
        Z_PARAM_DOUBLE(b)
        Z_PARAM_DOUBLE(c)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        roots = gsl_poly_complex_solve_quadratic(a, b, c, &z0, &z1);

        array_init(return_value);
        add_index_long(return_value, 0, roots);
        
        zval z0_arr, z1_arr;
        array_init_size(&z0_arr, 2);
        add_index_double(&z0_arr, 0, GSL_REAL(z0));
        add_index_double(&z0_arr, 1, GSL_IMAG(z0));
        add_index_zval(return_value, 1, &z0_arr);

        array_init_size(&z1_arr, 2);
        add_index_double(&z1_arr, 0, GSL_REAL(z1));
        add_index_double(&z1_arr, 1, GSL_IMAG(z1));
        add_index_zval(return_value, 2, &z1_arr);
}
/* }}} */

/* {{{ int gsl_poly_solve_cubic(double a, double b, double c, double *x0, double *x1, double *x2)
 */

PHP_FUNCTION(gsl_poly_solve_cubic)
{
        double a, b, c;
        double x0 = 0.0, x1 = 0.0, x2 = 0.0;
        int roots;

        ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_DOUBLE(a)
        Z_PARAM_DOUBLE(b)
        Z_PARAM_DOUBLE(c)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        roots = gsl_poly_solve_cubic(a, b, c, &x0, &x1, &x2);

        array_init(return_value);
        add_index_long(return_value, 0, roots);
        add_index_double(return_value, 1, x0);
        add_index_double(return_value, 2, x1);
        add_index_double(return_value, 3, x2);
}
/* }}} */

/* {{{ int gsl_poly_complex_solve_cubic(double a, double b, double c, gsl_complex *z0, gsl_complex *z1, gsl_complex *z2)
 */

PHP_FUNCTION(gsl_poly_complex_solve_cubic)
{
        double a, b, c;
        gsl_complex z0, z1, z2;
        int roots;

        ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_DOUBLE(a)
        Z_PARAM_DOUBLE(b)
        Z_PARAM_DOUBLE(c)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        roots = gsl_poly_complex_solve_cubic(a, b, c, &z0, &z1, &z2);

        array_init(return_value);
        add_index_long(return_value, 0, roots);
        
        zval z0_arr, z1_arr, z2_arr;
        array_init_size(&z0_arr, 2);
        add_index_double(&z0_arr, 0, GSL_REAL(z0));
        add_index_double(&z0_arr, 1, GSL_IMAG(z0));
        add_index_zval(return_value, 1, &z0_arr);

        array_init_size(&z1_arr, 2);
        add_index_double(&z1_arr, 0, GSL_REAL(z1));
        add_index_double(&z1_arr, 1, GSL_IMAG(z1));
        add_index_zval(return_value, 2, &z1_arr);

        array_init_size(&z2_arr, 2);
        add_index_double(&z2_arr, 0, GSL_REAL(z2));
        add_index_double(&z2_arr, 1, GSL_IMAG(z2));
        add_index_zval(return_value, 3, &z2_arr);
}
/* }}} */

/* {{{ gsl_poly_complex_workspace *gsl_poly_complex_workspace_alloc(size_t n)
 */

PHP_FUNCTION(gsl_poly_complex_workspace_alloc)
{
        zend_long n;
        gsl_poly_complex_workspace *w;

        ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(n)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        w = gsl_poly_complex_workspace_alloc(n);

        if (w == NULL) {
            RETURN_FALSE;
        }

        RETURN_LONG((zend_long)(uintptr_t)w);
}
/* }}} */

/* {{{ void gsl_poly_complex_workspace_free(gsl_poly_complex_workspace *w)
 */

PHP_FUNCTION(gsl_poly_complex_workspace_free)
{
        zend_long w_ptr;
        gsl_poly_complex_workspace *w;

        ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_LONG(w_ptr)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        w = (gsl_poly_complex_workspace *)(uintptr_t)w_ptr;
        gsl_poly_complex_workspace_free(w);

        RETURN_TRUE;
}
/* }}} */

/* {{{ int gsl_poly_complex_solve(const double *a, size_t n, gsl_poly_complex_workspace *w, gsl_complex_packed_ptr z)
 */

PHP_FUNCTION(gsl_poly_complex_solve)
{
        zval *array, *entry;
        zend_long w_ptr;
        zend_ulong num_idx;
        zend_string *str_idx;
        gsl_poly_complex_workspace *w;

        ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_ARRAY(array)
        Z_PARAM_LONG(w_ptr)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        HashTable *target_hash = HASH_OF(array);
        size_t n = zend_hash_num_elements(target_hash);
        double *a = emalloc(n * sizeof(double));
        
        int i = 0;
        ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(array), num_idx, str_idx, entry) {
            ZVAL_DEREF(entry);
            if (Z_TYPE_P(entry) == IS_LONG) {
                a[i++] = (double)Z_LVAL_P(entry);
            } else if (Z_TYPE_P(entry) == IS_DOUBLE) {
                a[i++] = Z_DVAL_P(entry);
            }
        } ZEND_HASH_FOREACH_END();

        w = (gsl_poly_complex_workspace *)(uintptr_t)w_ptr;
        
        double *z = emalloc(2 * (n - 1) * sizeof(double));
        
        int result = gsl_poly_complex_solve(a, n, w, (gsl_complex_packed_ptr)z);

        if (result == GSL_SUCCESS) {
            array_init(return_value);
            for (size_t j = 0; j < n - 1; j++) {
                zval root_arr;
                array_init_size(&root_arr, 2);
                add_index_double(&root_arr, 0, z[2 * j]);
                add_index_double(&root_arr, 1, z[2 * j + 1]);
                add_index_zval(return_value, j, &root_arr);
            }
        } else {
            RETVAL_FALSE;
        }

        efree(a);
        efree(z);
}
/* }}} */

/* {{{ int gsl_poly_dd_init(double dd[], const double x[], const double y[], size_t size)
 */

PHP_FUNCTION(gsl_poly_dd_init)
{
        zval *x_array, *y_array;
        zval *x_entry, *y_entry;
        zend_ulong num_idx;
        zend_string *str_idx;

        ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_ARRAY(x_array)
        Z_PARAM_ARRAY(y_array)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        HashTable *x_hash = HASH_OF(x_array);
        HashTable *y_hash = HASH_OF(y_array);
        size_t size = zend_hash_num_elements(x_hash);

        if (zend_hash_num_elements(y_hash) != size) {
            php_error_docref(NULL, E_WARNING, "Arrays must have the same size");
            RETURN_FALSE;
        }

        double *x = emalloc(size * sizeof(double));
        double *y = emalloc(size * sizeof(double));
        double *dd = emalloc(size * sizeof(double));

        int i = 0;
        ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(x_array), num_idx, str_idx, x_entry) {
            ZVAL_DEREF(x_entry);
            if (Z_TYPE_P(x_entry) == IS_LONG) {
                x[i] = (double)Z_LVAL_P(x_entry);
            } else if (Z_TYPE_P(x_entry) == IS_DOUBLE) {
                x[i] = Z_DVAL_P(x_entry);
            }
            i++;
        } ZEND_HASH_FOREACH_END();

        i = 0;
        ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(y_array), num_idx, str_idx, y_entry) {
            ZVAL_DEREF(y_entry);
            if (Z_TYPE_P(y_entry) == IS_LONG) {
                y[i] = (double)Z_LVAL_P(y_entry);
            } else if (Z_TYPE_P(y_entry) == IS_DOUBLE) {
                y[i] = Z_DVAL_P(y_entry);
            }
            i++;
        } ZEND_HASH_FOREACH_END();

        int result = gsl_poly_dd_init(dd, x, y, size);

        if (result == GSL_SUCCESS) {
            array_init(return_value);
            for (size_t j = 0; j < size; j++) {
                add_index_double(return_value, j, dd[j]);
            }
        } else {
            RETVAL_FALSE;
        }

        efree(x);
        efree(y);
        efree(dd);
}
/* }}} */

/* {{{ double gsl_poly_dd_eval(const double dd[], const double xa[], const size_t size, const double x)
 */

PHP_FUNCTION(gsl_poly_dd_eval)
{
        zval *dd_array, *xa_array;
        zval *dd_entry, *xa_entry;
        zend_ulong num_idx;
        zend_string *str_idx;
        double x;

        ZEND_PARSE_PARAMETERS_START(3, 3)
        Z_PARAM_ARRAY(dd_array)
        Z_PARAM_ARRAY(xa_array)
        Z_PARAM_DOUBLE(x)
        ZEND_PARSE_PARAMETERS_END_EX(RETURN_FALSE);

        HashTable *dd_hash = HASH_OF(dd_array);
        HashTable *xa_hash = HASH_OF(xa_array);
        size_t size = zend_hash_num_elements(dd_hash);

        if (zend_hash_num_elements(xa_hash) != size) {
            php_error_docref(NULL, E_WARNING, "Arrays must have the same size");
            RETURN_FALSE;
        }

        double *dd = emalloc(size * sizeof(double));
        double *xa = emalloc(size * sizeof(double));

        int i = 0;
        ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(dd_array), num_idx, str_idx, dd_entry) {
            ZVAL_DEREF(dd_entry);
            if (Z_TYPE_P(dd_entry) == IS_LONG) {
                dd[i] = (double)Z_LVAL_P(dd_entry);
            } else if (Z_TYPE_P(dd_entry) == IS_DOUBLE) {
                dd[i] = Z_DVAL_P(dd_entry);
            }
            i++;
        } ZEND_HASH_FOREACH_END();

        i = 0;
        ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(xa_array), num_idx, str_idx, xa_entry) {
            ZVAL_DEREF(xa_entry);
            if (Z_TYPE_P(xa_entry) == IS_LONG) {
                xa[i] = (double)Z_LVAL_P(xa_entry);
            } else if (Z_TYPE_P(xa_entry) == IS_DOUBLE) {
                xa[i] = Z_DVAL_P(xa_entry);
            }
            i++;
        } ZEND_HASH_FOREACH_END();

        double result = gsl_poly_dd_eval(dd, xa, size, x);

        efree(dd);
        efree(xa);

        RETURN_DOUBLE(result);
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_eval, 0)
ZEND_ARG_ARRAY_INFO(0, c, 0)
ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_complex_eval, 0)
ZEND_ARG_ARRAY_INFO(0, c, 0)
ZEND_ARG_ARRAY_INFO(0, z, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_solve_quadratic, 0)
ZEND_ARG_INFO(0, a)
ZEND_ARG_INFO(0, b)
ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_complex_solve_quadratic, 0)
ZEND_ARG_INFO(0, a)
ZEND_ARG_INFO(0, b)
ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_solve_cubic, 0)
ZEND_ARG_INFO(0, a)
ZEND_ARG_INFO(0, b)
ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_complex_solve_cubic, 0)
ZEND_ARG_INFO(0, a)
ZEND_ARG_INFO(0, b)
ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_complex_workspace_alloc, 0)
ZEND_ARG_INFO(0, n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_complex_workspace_free, 0)
ZEND_ARG_INFO(0, workspace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_complex_solve, 0)
ZEND_ARG_ARRAY_INFO(0, a, 0)
ZEND_ARG_INFO(0, workspace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_dd_init, 0)
ZEND_ARG_ARRAY_INFO(0, x, 0)
ZEND_ARG_ARRAY_INFO(0, y, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_gsl_poly_dd_eval, 0)
ZEND_ARG_ARRAY_INFO(0, dd, 0)
ZEND_ARG_ARRAY_INFO(0, xa, 0)
ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()
/* }}} */

#endif    /* PHP_GSL_POLY_C */
