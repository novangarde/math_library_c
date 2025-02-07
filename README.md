# math_library_c

My implementation of the Math library at C. Each function has prefix `mm_` (my math). Functions implemented: `abs`, `fabs`, `ceil`, `floor`, `sqrt`, `fmod`, `exp`, `log`, `pow`, `atan`, `atan_taylor`, `sin`, `cos`, `tan`, `asin`, `acos`.

## List of functions

| Function    | Description                                                                                            |
|-------------|--------------------------------------------------------------------------------------------------------|
| `abs`         | Returns the absolute value of an integer.                                                              |
| `fabs`        | Returns the absolute value of a floating-point number.                                                 |
| `ceil`        | Rounds up to the nearest integer (smallest integer not less than).                                     |
| `floor`       | Rounds down to the nearest integer (largest integer not greater than).                                 |
| `sqrt`        | Calculates the square root of a number.                                                                |
| `fmod`        | Computes the remainder when one number is divided by another for floating-point numbers.               |
| `exp`         | Evaluates (e) raised to a given power (e^x).                                                           |
| `log`         | Computes the natural logarithm (base (e)) of a number.                                                 |
| `pow`         | Raises one number to another's power (x^y).                                                            |
| `atan`        | Calculates arctangent (inverse tangent) in radians.                                                    |
| `atan_taylor` | Calculates the arctangent of a given value using the Taylor series expansion.                          |
| `sin`         | Basic trigonometric function sine                                                                      |
| `cos`         | Basic trigonometric function cosine                                                                    |
| `tan`         | Basic trigonometric function tangent                                                                   |
| `asin`        | Calculates arcsine – inverse sine operation returning angle in radians if input within domain [-1;1].  |
| `acos`        | Arccosine – returns angle whose cosine equals given input within domain [-1;1].                        |

## Makefile

`Makefile` has few main targets.

| Target        | Description                                           |
|---------------|-------------------------------------------------------|
| `all`         | Compiles the library                                  |
| `test`        | Starts unit-tests                                     |
| `gcov_report` | Makes coverage report                                 |
| `clean`       | Cleans the directory from object and executable files |

## Requirements

`check.h` library
