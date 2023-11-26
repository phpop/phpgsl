#ifndef PHP_GSL_POLY_C
#define PHP_GSL_POLY_C

/* {{{ double gsl_poly_eval(const double c[], const int len, const double x)
 */

PHP_FUNCTION(gsl_poly_eval)
{
        double x;
        zval    *array,				/* array to check in */
                *entry;				/* pointer to array entry */
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
            /** @TODO Необходимо проверять индекс, чтобы он был целым и последовательным от 0..len-1 */
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
        zval    *array,				/* array to check in */
                *entry,             /* pointer to array entry */
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
            /** @TODO Необходимо проверять индекс, чтобы он был целым и последовательным от 0..len-1 */
            if (Z_TYPE_P(entry) == IS_LONG) {
                c[num_idx] = Z_LVAL_P(entry);
            } else if (Z_TYPE_P(entry) == IS_DOUBLE) {
                c[num_idx] = Z_DVAL_P(entry);
            }
        } ZEND_HASH_FOREACH_END();

        RETURN_GSL_COMPLEX(gsl_poly_complex_eval(c, len, val_z));
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
/* }}} */

#endif    /* PHP_GSL_POLY_C */