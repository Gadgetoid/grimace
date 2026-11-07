#ifndef GRIMACE_MATH_H
#define GRIMACE_MATH_H

#ifdef __cplusplus
extern "C" {
#endif

struct _complex {
    double x;
    double y;
};

#define HUGE_VAL __builtin_huge_val()
#define HUGE_VALF __builtin_huge_valf()
#define HUGE_VALL __builtin_huge_vall()
#define INFINITY __builtin_inff()
#define NAN __builtin_nanf("")
#define FP_NAN 0
#define FP_INFINITE 1
#define FP_ZERO 2
#define FP_SUBNORMAL 3
#define FP_NORMAL 4

/**
 * Returns the arccosine of value in radians, from 0 to pi.
 *
 * @param value Value in the range -1 through 1.
 * @return The arccosine, or an indefinite value (quiet NaN) outside the range.
 *
 * @note Windows CE 2.0 and later.
 */
double acos(double value);
/**
 * Returns the arcsine of value in radians, from -pi/2 to pi/2.
 *
 * @param value Value in the range -1 through 1.
 * @return The arcsine, or an indefinite value (quiet NaN) outside the range.
 *
 * @note Windows CE 2.0 and later.
 */
double asin(double value);
/**
 * Returns the arctangent of value in radians, from -pi/2 to pi/2.
 *
 * @param value Value whose arctangent is calculated.
 * @return The arctangent.
 *
 * @note Windows CE 2.0 and later.
 */
double atan(double value);
/**
 * Returns the arctangent of y/x in radians, from -pi to pi.
 *
 * The signs of both inputs determine the result's quadrant. If both are
 * zero, the result is zero.
 *
 * @param y Y coordinate of the point.
 * @param x X coordinate of the point.
 * @return The arctangent of y/x.
 *
 * @note Windows CE 2.0 and later.
 */
double atan2(double y, double x);
/**
 * Returns the cosine of an angle in radians.
 *
 * For value >= 263 or value <= -263, the result loses significance and
 * the function raises _TLOSS and returns an indefinite value (quiet NaN).
 *
 * @param value Angle in radians.
 * @return The cosine, or an indefinite value when the angle is out of range.
 *
 * @note Windows CE 2.0 and later.
 */
double cos(double value);
/**
 * Returns the sine of an angle in radians.
 *
 * For value >= 263 or value <= -263, the result loses significance and
 * the function raises _TLOSS and returns an indefinite value (quiet NaN).
 *
 * @param value Angle in radians.
 * @return The sine, or an indefinite value when the angle is out of range.
 *
 * @note Windows CE 2.0 and later.
 */
double sin(double value);
/**
 * Returns the tangent of an angle in radians.
 *
 * For value >= 263 or value <= -263, the result loses significance and
 * the function raises _TLOSS and returns an indefinite value (a quiet NaN).
 * Use _matherr to customize math error handling.
 *
 * @param value Angle in radians.
 * @return The tangent, or an indefinite value when the angle is out of range.
 *
 * @note Windows CE 2.0 and later.
 */
double tan(double value);
/**
 * Returns the hyperbolic cosine of value.
 *
 * If the result is too large, returns HUGE_VAL.
 *
 * @param value Input value.
 * @return The hyperbolic cosine, or HUGE_VAL if the result is too large.
 *
 * @note Windows CE 2.0 and later.
 */
double cosh(double value);
/**
 * Returns the hyperbolic sine of value.
 *
 * If the result is too large, sinh returns HUGE_VAL with the result's sign.
 * Use _matherr to customize math error handling.
 *
 * @param value Input value.
 * @return The hyperbolic sine, or signed HUGE_VAL if the result is too large.
 *
 * @note Windows CE 2.0 and later.
 */
double sinh(double value);
/**
 * Returns the hyperbolic tangent of value. It has no error return.
 *
 * @param value Input value.
 * @return The hyperbolic tangent.
 *
 * @note Windows CE 2.0 and later.
 */
double tanh(double value);
/**
 * Returns e raised to value.
 *
 * Overflow returns INF; underflow returns 0.
 *
 * @param value Exponent.
 * @return The exponential, INF on overflow, or 0 on underflow.
 *
 * @note Windows CE 2.0 and later.
 */
double exp(double value);
/**
 * Returns the natural logarithm of value.
 *
 * Negative input returns an indefinite value (quiet NaN); zero returns INF.
 *
 * @param value Positive value whose logarithm is calculated.
 * @return The natural logarithm, an indefinite value for negative input,
 *         or INF for zero.
 *
 * @note Windows CE 2.0 and later.
 */
double log(double value);
/**
 * Returns the base-10 logarithm of value.
 *
 * Negative input returns an indefinite value (quiet NaN); zero returns INF.
 *
 * @param value Positive value whose logarithm is calculated.
 * @return The base-10 logarithm, an indefinite value for negative input,
 *         or INF for zero.
 *
 * @note Windows CE 2.0 and later.
 */
double log10(double value);
/**
 * Raises base to exponent.
 *
 * Zero to the zero power returns 1. Zero to a negative power returns INF.
 * Overflow and underflow do not print an error message.
 *
 * @param base Base value.
 * @param exponent Exponent.
 * @return base raised to exponent.
 *
 * @note Windows CE 2.0 and later.
 */
double pow(double base, double exponent);
/**
 * Returns the square root of value.
 *
 * Negative input produces an indefinite value (a quiet NaN). Use _matherr
 * to customize math error handling.
 *
 * @param value Nonnegative floating-point value.
 * @return The square root, or an indefinite value for negative input.
 *
 * @note Windows CE 2.0 and later.
 */
double sqrt(double value);
/**
 * Returns the smallest integer value greater than or equal to value.
 *
 * @param value Floating-point value.
 * @return The ceiling as a double.
 *
 * @note Windows CE 2.0 and later.
 */
double ceil(double value);
/**
 * Returns the largest integer value less than or equal to value.
 *
 * @param value Floating-point value.
 * @return The floor as a double.
 *
 * @note Windows CE 2.0 and later.
 */
double floor(double value);
/**
 * Returns the absolute value of value.
 *
 * @param value Floating-point value.
 * @return The absolute value.
 *
 * @note Windows CE 2.0 and later.
 */
double fabs(double value);
/**
 * Returns the floating-point remainder of dividend divided by divisor.
 *
 * The remainder has the sign of dividend and a magnitude less than
 * divisor's. A zero divisor returns a quiet NaN.
 *
 * @param dividend Value to divide.
 * @param divisor Divisor.
 * @return The remainder, or a quiet NaN if divisor is zero.
 *
 * @note Windows CE 2.0 and later.
 */
double fmod(double dividend, double divisor);
/**
 * Splits value into a mantissa and a power-of-two exponent.
 *
 * The mantissa's absolute value is at least 0.5 and less than 1, and
 * value equals mantissa times 2 to exponent. For zero, both results are 0.
 *
 * @param value Floating-point value to split.
 * @param exponent Receives the integer exponent.
 * @return The mantissa.
 *
 * @note Windows CE 2.0 and later.
 */
double frexp(double value, int *exponent);
/**
 * Multiplies value by 2 to the exponent.
 *
 * Overflow returns HUGE_VAL with the sign of value.
 *
 * @param value Floating-point value.
 * @param exponent Integer power of two.
 * @return The scaled value, or signed HUGE_VAL on overflow.
 *
 * @note Windows CE 2.0 and later.
 */
double ldexp(double value, int exponent);
/**
 * Splits value into integer and fractional parts.
 *
 * Both parts have the sign of value; the integer part is stored as a double.
 *
 * @param value Floating-point value to split.
 * @param integer Receives the integer part.
 * @return The signed fractional part.
 *
 * @note Windows CE 2.0 and later.
 */
double modf(double value, double *integer);
/**
 * Returns the magnitude of a complex number.
 *
 * The complex value has real and imaginary components. Overflow returns
 * HUGE_VAL.
 *
 * @param value Complex number whose magnitude is calculated.
 * @return The magnitude, or HUGE_VAL on overflow.
 *
 * @note Windows CE 2.0 and later.
 */
double _cabs(struct _complex value);
/**
 * Returns the hypotenuse for sides x and y.
 *
 * @param x First side length.
 * @param y Second side length.
 * @return The hypotenuse, or INF on overflow.
 *
 * @note Windows CE 2.0 and later.
 */
double _hypot(double x, double y);
/**
 * Returns value with its sign reversed.
 *
 * @param value Double-precision value to change.
 * @return The value with the opposite sign.
 *
 * @note Windows CE 2.0 and later.
 */
double _chgsign(double value);
/**
 * Returns value with the sign of sign.
 *
 * @param value Magnitude and value to return.
 * @param sign Value whose sign is copied.
 * @return value with the sign of sign.
 *
 * @note Windows CE 2.0 and later.
 */
double _copysign(double value, double sign);
/**
 * Tests whether value is finite.
 *
 * @param value Double-precision value to test.
 * @return Nonzero if value is neither infinite nor NaN; otherwise 0.
 *
 * @note Windows CE 2.0 and later.
 */
int _finite(double value);
/**
 * Tests whether value is a NaN.
 *
 * @param value Double-precision value to test.
 * @return Nonzero if value is NaN; otherwise 0.
 *
 * @note Windows CE 2.0 and later.
 */
int _isnan(double value);
/**
 * Returns the floating-point classification of value.
 *
 * The classification distinguishes signed zero, normal and denormal
 * values, infinities, and signaling or quiet NaNs.
 *
 * @param value Double-precision value to classify.
 * @return An _FPCLASS_* classification code.
 *
 * @note Windows CE 2.0 and later.
 */
int _fpclass(double value);
/**
 * Returns the unbiased exponent of value.
 *
 * Denormalized values are treated as if they were normalized.
 *
 * @param value Double-precision value to inspect.
 * @return The unbiased exponent.
 *
 * @note Windows CE 2.0 and later.
 */
double _logb(double value);
/**
 * Returns the nearest representable value to value toward direction.
 *
 * If the inputs are equal, value is returned without raising an
 * exception. If either input is a quiet NaN, the result is one of them.
 *
 * @param value Starting value.
 * @param direction Direction toward the neighboring representable value.
 * @return The nearest representable neighbor toward direction.
 *
 * @note Windows CE 2.0 and later.
 */
double _nextafter(double value, double direction);
/**
 * Scales value by a power of two.
 *
 * On overflow, returns HUGE_VAL with the sign of value.
 *
 * @param value Value to scale.
 * @param exponent Power of two to apply.
 * @return value multiplied by 2 to the exponent, or signed HUGE_VAL on overflow.
 *
 * @note Windows CE 2.0 and later.
 */
double _scalb(double value, long exponent);
double _frnd(double value);
double _fsqrt(double value);
/**
 * Returns the order-zero Bessel function of the first kind.
 *
 * @param value Argument to the function.
 * @return The order-zero Bessel function value.
 *
 * @note Windows CE 2.0 and later.
 */
double _j0(double value);
/**
 * Returns the order-one Bessel function of the first kind.
 *
 * @param value Argument to the function.
 * @return The order-one Bessel function value.
 *
 * @note Windows CE 2.0 and later.
 */
double _j1(double value);
/**
 * Returns the Bessel function of the first kind for the specified order.
 *
 * @param order Integer order of the function.
 * @param value Argument to the function.
 * @return The Bessel function value.
 *
 * @note Windows CE 2.0 and later.
 */
double _jn(int order, double value);
/**
 * Returns the order-zero Bessel function of the second kind.
 *
 * For negative value, the function reports _DOMAIN to stderr and returns
 * _HUGE_VAL. Use _matherr to customize error handling.
 *
 * @param value Argument to the function; must not be negative.
 * @return The order-zero Bessel function value, or _HUGE_VAL for negative input.
 *
 * @note Windows CE 2.0 and later.
 */
double _y0(double value);
/**
 * Returns the order-one Bessel function of the second kind.
 *
 * For negative value, the function reports _DOMAIN to stderr and returns
 * _HUGE_VAL. Use _matherr to customize error handling.
 *
 * @param value Argument to the function; must not be negative.
 * @return The order-one Bessel function value, or _HUGE_VAL for negative input.
 *
 * @note Windows CE 2.0 and later.
 */
double _y1(double value);
/**
 * Returns the Bessel function of the second kind for the specified order.
 *
 * For negative value, the function reports _DOMAIN to stderr and returns
 * _HUGE_VAL. Use _matherr to customize error handling.
 *
 * @param order Integer order of the function.
 * @param value Argument to the function; must not be negative.
 * @return The Bessel function value, or _HUGE_VAL for negative input.
 *
 * @note Windows CE 2.0 and later.
 */
double _yn(int order, double value);
/**
 * Returns and clears the floating-point status flags.
 *
 * The returned bits describe the status before it was cleared.
 *
 * @return Floating-point status flags.
 *
 * @note Windows CE 2.0 and later.
 */
unsigned int _clearfp(void);
/**
 * Gets or updates the floating-point control word.
 *
 * With mask set to 0, the current control word is returned. Otherwise,
 * bits set in mask are replaced with the corresponding bits from value.
 * Floating-point exceptions are masked by default.
 *
 * @param value New values for the control bits selected by mask.
 * @param mask Bits to read or update.
 * @return The floating-point control state.
 *
 * @note Windows CE 2.0 and later.
 */
unsigned int _controlfp(unsigned int value, unsigned int mask);
/**
 * Returns the floating-point status flags.
 *
 * The status includes pending unmasked exceptions, which are checked
 * before the flags are returned.
 *
 * @return Floating-point status flags.
 *
 * @note Windows CE 2.0 and later.
 */
unsigned int _statusfp(void);
/**
 * Reinitializes the floating-point math package.
 *
 * Use it when recovering from a floating-point exception before resuming
 * floating-point work.
 *
 * @note Windows CE 2.0 and later.
 */
void _fpreset(void);
double trunc(double value);
double round(double value);
long lround(double value);
long long llround(double value);
double fmin(double first, double second);
double fmax(double first, double second);
double fdim(double first, double second);
double log2(double value);
double exp2(double value);
double cbrt(double value);
double hypot(double x, double y);
double copysign(double value, double sign);
float sqrtf(float value);
float sinf(float value);
float cosf(float value);
float tanf(float value);
float asinf(float value);
float acosf(float value);
float atanf(float value);
float atan2f(float y, float x);
float sinhf(float value);
float coshf(float value);
float tanhf(float value);
float expf(float value);
float logf(float value);
float log10f(float value);
float log2f(float value);
float exp2f(float value);
float powf(float base, float exponent);
float floorf(float value);
float ceilf(float value);
float truncf(float value);
float roundf(float value);
float fmodf(float dividend, float divisor);
float fabsf(float value);
float fminf(float first, float second);
float fmaxf(float first, float second);
float hypotf(float x, float y);
float copysignf(float value, float sign);
float cbrtf(float value);
float ldexpf(float value, int exponent);
float frexpf(float value, int *exponent);
float modff(float value, float *integer);
long double sqrtl(long double value);
long double sinl(long double value);
long double cosl(long double value);
long double tanl(long double value);
long double asinl(long double value);
long double acosl(long double value);
long double atanl(long double value);
long double sinhl(long double value);
long double coshl(long double value);
long double tanhl(long double value);
long double expl(long double value);
long double logl(long double value);
long double log10l(long double value);
long double floorl(long double value);
long double ceill(long double value);
long double truncl(long double value);
long double roundl(long double value);
long double log2l(long double value);
long double exp2l(long double value);
long double cbrtl(long double value);
long double atan2l(long double y, long double x);
long double powl(long double base, long double exponent);
long double fmodl(long double dividend, long double divisor);
long double fminl(long double first, long double second);
long double fmaxl(long double first, long double second);
long double hypotl(long double x, long double y);
long double copysignl(long double value, long double sign);
long double fabsl(long double value);
long double ldexpl(long double value, int exponent);
long double frexpl(long double value, int *exponent);
long double modfl(long double value, long double *integer);

#ifdef __cplusplus
}
#endif

#endif
