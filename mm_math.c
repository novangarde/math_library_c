#include "mm_math.h"

int mm_abs(int x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double mm_fabs(double x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double mm_ceil(double x) {
  long long int intPart = (long long int)x;
  if (mm_fabs(x - intPart) > 0.) {
    if (x > 0.) {
      intPart++;
    }
  }
  return intPart;
}

long double mm_floor(double x) {
  long double res = (long long int)x;
  if (mm_fabs(x - res) > 0.) {
    if (x < 0.) {
      res -= 1;
    }
  }
  return res;
}

long double mm_sqrt(double x) {
  if (x < 0) return 0.0 / 0.0;
  if (x == 0) return 0.0;
  long double res = x / 2.0;
  int max_iterations = 100;
  int iteration = 0;

  while (iteration < max_iterations) {
    res = 0.5 * (res + x / res);
    iteration++;
  }
  return res;
}

long double mm_fmod(double x, double y) {
  if (y == 0) return 0.0 / 0.0;

  long long int z = x / y;
  long double res = (long double)x - z * (long double)y;
  return res;
}

long double mm_exp(double x) {
  if (x > DBL_MAX) {
    return 1.0 / 0.0;
  } else if (x < -DBL_MAX) {
    return 0.0;
  }
  if (x < 0) {
    return 1.0 / mm_exp(-x);
  }
  long double term = 1.0;
  long double res = 1.0;
  long double n = 1.0;
  long double eps = 1e-15;

  while (mm_fabs(term) > eps) {
    term *= x / n;
    n += 1;
    res += term;

    if (res > DBL_MAX) {
      res = 1.0 / 0.0;
      break;
    }
  }
  return res;
}

long double mm_log(double x) {
  if (x == 0.0) return -1.0 / 0.0;
  if (x < 0.0) return 0.0 / 0.0;
  if (x == 1.0 / 0.0) return 1.0 / 0.0;

  long double res = 0.0;

  for (int i = 0; i < 100; i++) {
    res += 2 * (x - mm_exp(res)) / (x + mm_exp(res));
  }
  return res;
}

long double mm_pow(double base, double exp) {
  if (base == 0.0 && exp == 0.0) {
    return 1.0;
  } else if (exp == 0.0) {
    return 1.0;
  } else if (base == 0.0 && exp < 0.0) {
    return 1.0 / 0.0;
  } else if (base == 1.0) {
    return 1.0;
  }

  long double res;

  if (exp < 0.0) {
    res = 1.0 / mm_pow(base, -exp);
  } else {
    double int_part = (double)(long long)exp;
    double frac_part = exp - int_part;

    res = 1.0;
    for (long long i = 0; i < (long long)int_part; ++i) {
      res *= base;
    }

    if (frac_part != 0.0) {
      res *= mm_exp(frac_part * mm_log(base));
    }
  }

  return res;
}

long double mm_atan_taylor(double x, long double eps) {
  long double res = 0.0;
  long double term = x;
  long double term_squared = x * x;
  long double term_squared_2 = x;
  int sign = 1;

  for (int i = 1; mm_fabs(term_squared_2) > eps; i++) {
    res += sign * term_squared_2;
    term *= term_squared;
    term_squared_2 = term / (2 * i + 1);
    sign *= -1;
  }

  return res;
}

long double mm_atan(double x) {
  if (x > 1.0) {
    return PI / 2 - mm_atan_taylor(1.0 / x, 1e-15);
  } else if (x < -1.0) {
    return -PI / 2 - mm_atan_taylor(1.0 / x, 1e-15);
  } else {
    long double eps = 1e-15;
    return mm_atan_taylor(x, eps);
  }
}

long double mm_sin(double x) {
  // long double res = 0.0;
  for (; x < -2 * PI || 2 * PI < x;) {
    if (x > 2 * PI) {
      x -= 2 * PI;
    } else {
      x += 2 * PI;
    }
  }
  long double member = x;
  long double res = x;
  int sign = 1;
  long double eps = 1e-15;

  for (int i = 1; mm_fabs(member) > eps; i++) {
    member *= x * x / ((2 * i) * (2 * i + 1));
    sign *= (-1);
    res += sign * member;
  }
  return res;
}

long double mm_cos(double x) {
  for (; x < -2 * PI || 2 * PI < x;) {
    if (x > 2 * PI) {
      x -= 2 * PI;
    } else {
      x += 2 * PI;
    }
  }

  long double member = 1.0;
  long double res = 1.0;
  int sign = 1;
  long double eps = 1e-15;

  for (int i = 1; mm_fabs(member) > eps; i++) {
    member *= x * x / (2 * i * (2 * i - 1));
    sign *= (-1);
    res += sign * member;
  }
  return res;
}

long double mm_tan(double x) {
  long double sin_val = mm_sin(x);
  long double cos_val = mm_cos(x);

  if (cos_val < 1e-15 && cos_val > -1e-15) {
    return 0.0;
  }
  return sin_val / cos_val;
}

long double mm_asin(double x) {
  if (x < -1.0 || x > 1.0) return 0.0 / 0.0;

  long double res = 0.0;
  if (x == 1.0) res = PI / 2.0;
  if (x == -1.0) res = -1 * PI / 2.0;
  if (x >= -1.0 && x <= 1.0) {
    res = mm_atan(x / mm_sqrt(1.0 - x * x));
  }
  return res;
}

long double mm_acos(double x) {
  if (x < -1.0 || x > 1.0) return 0.0 / 0.0;

  long double res = 0.0;
  if (x == 0.0) res = PI / 2.0;
  if (x > 0.0 && x <= 1.0) {
    res = mm_atan(mm_sqrt(1 - x * x) / x);
  }
  if (x >= -1.0 && x < 0.0) {
    res = PI + mm_atan(mm_sqrt(1 - x * x) / x);
  }
  return res;
}
