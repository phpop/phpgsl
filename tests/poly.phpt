--TEST--
GSL polynomials test
--SKIPIF--
<?php
if (!extension_loaded('gsl')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(gsl_poly_eval([1], -1));
var_dump(gsl_poly_eval([1], 0));
var_dump(gsl_poly_eval([1], 1));
var_dump(gsl_poly_eval([1], 2));
var_dump(gsl_poly_eval([1], 3.0));
var_dump(gsl_poly_eval([1], -3.0));
//
var_dump(gsl_poly_eval([0, 1], -1)); // x (x = -1)
var_dump(gsl_poly_eval([0, 1], 0)); // x (x = 0)
var_dump(gsl_poly_eval([0, 1], 1)); // x (x = 1)
//
var_dump(gsl_poly_eval([1, 1, 1], 2)); // 1 + x + x^2 (x = 2)
var_dump(gsl_poly_eval([1, 1, 1], -2.0)); // 1 + x + x^2 (x = -2)
var_dump(gsl_poly_eval([1, 1, 1], 0.5)); // 1 + x + x^2 (x = 0.5)
//
var_dump(gsl_poly_complex_eval([1, 0, 0, 0, 1], [2, 0])); // 1 + x^4 (x = 2)
var_dump(gsl_poly_complex_eval([-2.0, 1.0, 1, -1, 2], [2, 0])); // -2 + x + x^2 - x^3 + 2x^4 (x = 2)
var_dump(gsl_poly_complex_eval([-2.0, 1.0, 1, -1, 2], [2, -2])); // -2 + x + x^2 - x^3 + 2x^4 (x = 2 - 2i)
var_dump(gsl_poly_complex_eval([-2.0, -5.0, 1], [2, 1])); // -2 - 5x + x^2 (x = 2 + i)
?>
--EXPECT--
float(1)
float(1)
float(1)
float(1)
float(1)
float(1)
float(-1)
float(0)
float(1)
float(7)
float(3)
float(1.75)
array(2) {
  [0]=>
  float(17)
  [1]=>
  float(0)
}
array(2) {
  [0]=>
  float(28)
  [1]=>
  float(0)
}
array(2) {
  [0]=>
  float(-112)
  [1]=>
  float(6)
}
array(2) {
  [0]=>
  float(-9)
  [1]=>
  float(-1)
}