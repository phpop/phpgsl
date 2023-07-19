--TEST--
gsl_test2() Basic test
--SKIPIF--
<?php
if (!extension_loaded('gsl')) {
	echo 'skip';
}
?>
--FILE--
<?php
var_dump(gsl_test2());
var_dump(gsl_test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
