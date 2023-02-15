#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H
#include <stdint.h>

typedef struct rational
{
    int16_t numerator;
    int16_t denominator;
} rational_t;

/// Normalize 'r'.
rational_t reduce(rational_t r);
/// Calculate the sum of 'r1' and 'r2'.
rational_t add(rational_t r1, rational_t r2);
/// Calculate the difference of 'r1' and 'r2'.
rational_t subtract(rational_t r1, rational_t r2);
/// Calculate the product of 'r1' and 'r1'.
rational_t multiply(rational_t r1, rational_t r2);
/// Calculate the quotient of 'r1' and 'r2'.
rational_t divide(rational_t r1, rational_t r2);
/// Calculate the absolute value of 'r'.
rational_t absolute(rational_t r);
/// Calculate 'r' to the power of 'exp'.
rational_t exp_rational(rational_t r, int16_t n);
/// Calculate 'base' to the power of 'r'.
float exp_real(float x, rational_t r);


#endif 