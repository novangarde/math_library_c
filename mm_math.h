#include <float.h>
#include <limits.h>
#ifndef MM_MATH_H
#define MM_MATH_H

#define PI 3.14159265358979323846L

int mm_abs(int x);
long double mm_fabs(double x);
long double mm_ceil(double x);
long double mm_floor(double x);
long double mm_sqrt(double x);
long double mm_fmod(double x, double y);
long double mm_exp(double x);
long double mm_log(double x);
long double mm_pow(double base, double exp);
long double mm_atan(double x);
long double mm_atan_taylor(double x, long double eps);
long double mm_sin(double x);
long double mm_cos(double x);
long double mm_tan(double x);
long double mm_asin(double x);
long double mm_acos(double x);

#endif
