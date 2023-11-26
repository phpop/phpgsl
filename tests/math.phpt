--TEST--
GSL math test
--SKIPIF--
<?php
if (!extension_loaded('gsl')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(gsl_pow_2(0));
var_dump(gsl_pow_2(2));
var_dump(gsl_pow_2(3));
var_dump(gsl_pow_2(-5));
var_dump(gsl_pow_2(1.2));
var_dump(gsl_pow_2(-2.2));
?>
--EXPECT--
float(0)
float(4)
float(9)
float(25)
float(1.44)
float(4.84)