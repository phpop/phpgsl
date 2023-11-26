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
var_dump(gsl_complex_real([-1, 1]));
var_dump(gsl_complex_real([0, 1.0]));
var_dump(gsl_complex_real([1, 1]));
//
var_dump(gsl_complex_imag([1.0, -1]));
var_dump(gsl_complex_imag([1, 0]));
var_dump(gsl_complex_imag([1, 1]));
//
var_dump(gsl_complex_rect(1.0, -1.0));
var_dump(gsl_complex_rect(-1, 1));
var_dump(gsl_complex_rect(-1.5, 0));
//
var_dump(gsl_complex_abs([2, 0]));
?>
--EXPECT--
float(-1)
float(0)
float(1)
float(-1)
float(0)
float(1)
array(2) {
  [0]=>
  float(1)
  [1]=>
  float(-1)
}
array(2) {
  [0]=>
  float(-1)
  [1]=>
  float(1)
}
array(2) {
  [0]=>
  float(-1.5)
  [1]=>
  float(0)
}
float(2)