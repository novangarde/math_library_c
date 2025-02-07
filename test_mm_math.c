#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "mm_math.h"

START_TEST(test_mm_abs) {
  ck_assert_ldouble_eq(mm_abs(5), abs(5));
  ck_assert_ldouble_eq(mm_abs(-7), abs(-7));
  ck_assert_ldouble_eq(mm_abs(0), abs(0));
  ck_assert_ldouble_eq(mm_abs(53465445), abs(53465445));
  ck_assert_ldouble_eq(mm_abs(-634354), abs(-634354));
  ck_assert_ldouble_eq(mm_abs(2147483647), abs(2147483647));
  ck_assert_ldouble_eq(mm_abs(-2147483647), abs(-2147483647));
}

START_TEST(test_mm_fabs) {
  ck_assert_ldouble_eq(mm_fabs(3.5), fabs(3.5));
  ck_assert_ldouble_eq(mm_fabs(-2.8), fabs(-2.8));
  ck_assert_ldouble_eq(mm_fabs(0.0), fabs(0.0));
  ck_assert_ldouble_eq(mm_fabs(12413.312454), fabs(12413.312454));
  ck_assert_ldouble_eq(mm_fabs(564645.896456), fabs(564645.896456));
  ck_assert_ldouble_eq(mm_fabs(0.0000001), fabs(0.0000001));
  ck_assert_ldouble_eq(mm_fabs(-0.0000001), fabs(-0.0000001));
}

START_TEST(test_mm_ceil) {
  ck_assert_ldouble_eq(mm_ceil(3.2), ceil(3.2));
  ck_assert_ldouble_eq(mm_ceil(-4.7), ceil(-4.7));
  ck_assert_ldouble_eq(mm_ceil(2.0), ceil(2.0));
  ck_assert_ldouble_eq(mm_ceil(12413.312454354452312),
                       ceil(12413.312454354452312));
  ck_assert_ldouble_eq(mm_ceil(-564645.896456546454508),
                       ceil(-564645.896456546454508));
  ck_assert_ldouble_eq(mm_ceil(0.0000000000000001), ceil(0.0000000000000001));
  ck_assert_ldouble_eq(mm_ceil(-0.0000000000000001),
                       ceil(-0.0000000000000001));
}

START_TEST(test_mm_floor) {
  ck_assert_ldouble_eq(mm_floor(3.2), floor(3.2));
  ck_assert_ldouble_eq(mm_floor(-4.7), floor(-4.7));
  ck_assert_ldouble_eq(mm_floor(2.0), floor(2.0));
  ck_assert_ldouble_eq(mm_floor(12413.312454354452312),
                       floor(12413.312454354452312));
  ck_assert_ldouble_eq(mm_floor(-564645.896456546454508),
                       floor(-564645.896456546454508));
  ck_assert_ldouble_eq(mm_floor(0.0000000000000001),
                       floor(0.0000000000000001));
  ck_assert_ldouble_eq(mm_floor(-0.0000000000000001),
                       floor(-0.0000000000000001));
}

START_TEST(test_mm_sqrt) {
  ck_assert_ldouble_eq_tol(mm_sqrt(9.0), sqrt(9.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sqrt(25.0), sqrt(25.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sqrt(2.0), sqrt(2.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sqrt(12413.312454), sqrt(12413.312454), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sqrt(0.000000001), sqrt(0.000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sqrt(0.0), sqrt(0.0), 1e-7);
}

START_TEST(test_mm_fmod) {
  ck_assert_ldouble_eq(mm_fmod(5.7, 3.2), fmod(5.7, 3.2));
  ck_assert_ldouble_eq(mm_fmod(-8.5, 2.0), fmod(-8.5, 2.0));
  ck_assert_ldouble_eq(mm_fmod(12413.312454354452312, 2.0),
                       fmod(12413.312454354452312, 2.0));
  ck_assert_ldouble_eq(mm_fmod(0.0000000000000001, 2.0),
                       fmod(0.0000000000000001, 2.0));
  ck_assert_ldouble_eq(mm_fmod(-0.0000000000000001, 2.0),
                       fmod(-0.0000000000000001, 2.0));
  ck_assert_ldouble_eq(mm_fmod(0.0, 2.0), fmod(0.0, 2.0));
}

START_TEST(test_mm_exp) {
  ck_assert_ldouble_eq_tol(mm_exp(1.0), exp(1.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_exp(0.0), exp(0.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_exp(10.0), exp(10.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_exp(-10.0), exp(-10.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_exp(-11112413.312454354452312),
                           exp(-11112413.312454354452312), 1e-7);
  ck_assert_ldouble_eq_tol(mm_exp(-15.345353), exp(-15.345353), 1e-7);
  ck_assert_ldouble_eq_tol(mm_exp(-1000000000000.0), exp(-1000000000000.0),
                           1e-7);
}

START_TEST(test_mm_log) {
  ck_assert_ldouble_eq_tol(mm_log(2.0), log(2.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_log(1.0), log(1.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_log(12413.312454354452312),
                           log(12413.312454354452312), 1e-7);
  ck_assert_ldouble_eq_tol(mm_log(0.00001), log(0.00001), 1e-7);
}

START_TEST(test_mm_pow) {
  ck_assert_ldouble_eq_tol(mm_pow(2.0, 3.0), pow(2.0, 3.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(10.312454, 5.0), pow(10.312454, 5.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(4.0, 0.5), pow(4.0, 0.5), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(4.0, 0.0), pow(4.0, 0.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(4.0, 1.0), pow(4.0, 1.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(-40.0, 3.0), pow(-40.0, 3.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(-40.0, 2.0), pow(-40.0, 2.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(4.0, -0.5), pow(4.0, -0.5), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(4.6, -0.000001), pow(4.6, -0.000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(0.0, 0.0), pow(0.0, 0.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(5.6, 0.0), pow(5.6, 0.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(0.0, 2344.8), pow(0.0, 2344.8), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(1.0, 6.0), pow(1.0, 6.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_pow(100.0, 10.0), pow(100.0, 10.0), 1e-7);
}

START_TEST(test_mm_atan) {
  ck_assert_ldouble_eq_tol(mm_atan(5.0), atan(5.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_atan(0.5), atan(0.5), 1e-7);
  ck_assert_ldouble_eq_tol(mm_atan(-0.8), atan(-0.8), 1e-7);
  ck_assert_ldouble_eq_tol(mm_atan(12413.312454354452312),
                           atan(12413.312454354452312), 1e-7);
  ck_assert_ldouble_eq_tol(mm_atan(-564645.896456546454508),
                           atan(-564645.896456546454508), 1e-7);
  ck_assert_ldouble_eq_tol(mm_atan(0.0000000000000001),
                           atan(0.0000000000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_atan(-0.0000000000000001),
                           atan(-0.0000000000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_atan(0.0), atan(0.0), 1e-7);
}

START_TEST(test_mm_sin) {
  ck_assert_ldouble_eq_tol(mm_sin(0.8), sin(0.8), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sin(-1.2), sin(-1.2), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sin(5.0), sin(5.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sin(12413.312454354452312),
                           sin(12413.312454354452312), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sin(-56464.896456), sin(-56464.896456), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sin(0.0000000000000001), sin(0.0000000000000001),
                           1e-7);
  ck_assert_ldouble_eq_tol(mm_sin(-0.0000000000000001),
                           sin(-0.0000000000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_sin(0.0), sin(0.0), 1e-7);
}

START_TEST(test_mm_cos) {
  ck_assert_ldouble_eq_tol(mm_cos(0.8), cos(0.8), 1e-7);
  ck_assert_ldouble_eq_tol(mm_cos(-1.2), cos(-1.2), 1e-7);
  ck_assert_ldouble_eq_tol(mm_cos(5.0), cos(5.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_cos(12413.312454354452312),
                           cos(12413.312454354452312), 1e-7);
  ck_assert_ldouble_eq_tol(mm_cos(-56464.896456), cos(-56464.896456), 1e-7);
  ck_assert_ldouble_eq_tol(mm_cos(0.0000000000000001), cos(0.0000000000000001),
                           1e-7);
  ck_assert_ldouble_eq_tol(mm_cos(-0.0000000000000001),
                           cos(-0.0000000000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_cos(0.0), cos(0.0), 1e-7);
}

START_TEST(test_mm_tan) {
  ck_assert_ldouble_eq_tol(mm_tan(0.4), tan(0.4), 1e-7);
  ck_assert_ldouble_eq_tol(mm_tan(-0.3), tan(-0.3), 1e-7);
  ck_assert_ldouble_eq_tol(mm_tan(12413.312454354452312),
                           tan(12413.312454354452312), 1e-7);
  ck_assert_ldouble_eq_tol(mm_tan(-56464.896456), tan(-56464.896456), 1e-7);
  ck_assert_ldouble_eq_tol(mm_tan(0.0000000000000001), tan(0.0000000000000001),
                           1e-7);
  ck_assert_ldouble_eq_tol(mm_tan(-0.0000000000000001),
                           tan(-0.0000000000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_tan(0.0), tan(0.0), 1e-7);
}

START_TEST(test_mm_asin) {
  ck_assert_ldouble_eq_tol(mm_asin(0.7), asin(0.7), 1e-7);
  ck_assert_ldouble_eq_tol(mm_asin(-0.4), asin(-0.4), 1e-7);
  ck_assert_ldouble_eq_tol(mm_asin(0.4), asin(0.4), 1e-7);
  ck_assert_ldouble_eq_tol(mm_asin(-0.3), asin(-0.3), 1e-7);
  ck_assert_ldouble_eq_tol(mm_asin(0.0000000000000001),
                           asin(0.0000000000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_asin(-0.0000000000000001),
                           asin(-0.0000000000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_asin(0.0), asin(0.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_asin(1.0), asin(1.0), 1e-7);
  ck_assert_ldouble_eq_tol(mm_asin(-1.0), asin(-1.0), 1e-7);
}

START_TEST(test_mm_acos) {
  ck_assert_ldouble_eq_tol(mm_acos(0.2), acos(0.2), 1e-7);
  ck_assert_ldouble_eq_tol(mm_acos(-0.9), acos(-0.9), 1e-7);
  ck_assert_ldouble_eq_tol(mm_acos(0.4), acos(0.4), 1e-7);
  ck_assert_ldouble_eq_tol(mm_acos(-0.3), acos(-0.3), 1e-7);
  ck_assert_ldouble_eq_tol(mm_acos(0.0000000000000001),
                           acos(0.0000000000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_acos(-0.0000000000000001),
                           acos(-0.0000000000000001), 1e-7);
  ck_assert_ldouble_eq_tol(mm_acos(0.0), acos(0.0), 1e-7);
}

START_TEST(test_mm_nan_inf) {
  ck_assert(isnan(mm_fmod(10.0, 0.0)));
  ck_assert(isnan(mm_log(-564645.896456546454508)));
  ck_assert(isnan(mm_pow(-40.0, 0.5)));
  ck_assert(isnan(mm_asin(2.0)));
  ck_assert(isnan(mm_asin(-2.0)));
  ck_assert(isnan(mm_acos(2.0)));
  ck_assert(isnan(mm_acos(-2.0)));

  ck_assert(isinf(mm_exp(12413.312454354452312)));
  ck_assert(isinf(mm_exp(1e300)));
  ck_assert(isinf(mm_log(0.0)));
  ck_assert(isinf(mm_log(1.0 / 0.0)));
  ck_assert(isinf(mm_pow(0.0, -4.8)));
}

Suite *mm_math_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("mm_math");

  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_mm_abs);
  tcase_add_test(tc_core, test_mm_fabs);
  tcase_add_test(tc_core, test_mm_ceil);
  tcase_add_test(tc_core, test_mm_floor);
  tcase_add_test(tc_core, test_mm_sqrt);
  tcase_add_test(tc_core, test_mm_fmod);
  tcase_add_test(tc_core, test_mm_exp);
  tcase_add_test(tc_core, test_mm_log);
  tcase_add_test(tc_core, test_mm_pow);
  tcase_add_test(tc_core, test_mm_atan);
  tcase_add_test(tc_core, test_mm_sin);
  tcase_add_test(tc_core, test_mm_cos);
  tcase_add_test(tc_core, test_mm_tan);
  tcase_add_test(tc_core, test_mm_asin);
  tcase_add_test(tc_core, test_mm_acos);
  tcase_add_test(tc_core, test_mm_nan_inf);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *runner;

  s = mm_math_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int num_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (num_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
