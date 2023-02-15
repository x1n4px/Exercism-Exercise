#include "rational_numbers.h"
#include<stdlib.h>
#include<math.h>
/// Normalize 'r'.
rational_t reduce(rational_t r)
{
    rational_t result;
    int gcd = 1; 
    int d = 1; //MCD

    //MCD
    while(d <= abs(r.numerator) && d <= abs(r.denominator)){
        if(r.numerator % d == 0 && r.denominator % d == 0){
            gcd = d;
        }
        d++;
    }

    result.numerator = r.numerator/gcd;
    result.denominator = r.denominator/gcd;
    if(result.numerator == 0){
        result.denominator = 1;
    }
    if(result.denominator < 0){
        result.numerator *= -1;
        result.denominator *= -1;
    }
    return (result);
}
/// Calculate the sum of 'r1' and 'r2'.
rational_t add(rational_t r1, rational_t r2)
{
    /*
    r1 = a1/b1       r2 = a2/b2
    r1 + r2 = a1/b1 + a2/b2 = (a1*b2 + a2*b1) / (b1*b2)
    */
    rational_t result;
    result.numerator = (r1.numerator * r2.denominator + r2.numerator * r1.denominator);
    result.denominator = (r1.denominator * r2.denominator);
    return (reduce(result));
}
/// Calculate the difference of 'r1' and 'r2'.
rational_t subtract(rational_t r1, rational_t r2)
{
    /*
    r1 = a1/b1       r2 = a2/b2
    r1 + r2 = a1/b1 - a2/b2 = (a1*b2 + a2*b1) / (b1*b2)
    */
    r2.numerator *= -1;
    return (add(r1,r2));
}

/// Calculate the product of 'r1' and 'r1'.
rational_t multiply(rational_t r1, rational_t r2)
{
    /*
   r1 = a1/b1       r2 = a2/b2
   r1 * r2 = (a1*a2) / (b2*b1)
   */
    rational_t result;

    result.numerator = (r1.numerator * r2.numerator);
    result.denominator = (r2.denominator * r1.denominator);
    return (reduce(result));
}

/// Calculate the quotient of 'r1' and 'r2'.
rational_t divide(rational_t r1, rational_t r2)
{
    /*
    r1 = a1/b1       r2 = a2/b2
    r1 * r2 = (a1*b2) / (a2*b1)
    */
    rational_t result;
        result.numerator = (r1.numerator * r2.denominator);
        result.denominator = (r1.denominator * r2.numerator);
        return (reduce(result));
}

/// Calculate the absolute value of 'r'.
rational_t absolute(rational_t r)
{
    r.numerator = abs(r.numerator);
    r.denominator = abs(r.denominator);
    return (reduce(r));
}

/// Calculate 'r' to the power of 'exp'.
rational_t exp_rational(rational_t r, int16_t n)
{
    rational_t result;
    if (n < 0)
    {
        n = abs(n);
        result.numerator = pow(r.denominator, n);
        result.denominator = pow(r.numerator, n);
    }
    else
    {
        result.numerator = pow(r.numerator, n);
        result.denominator = pow(r.denominator, n);
    }
    return (reduce(result));
}

/// Calculate 'base' to the power of 'r'.
float exp_real(float x, rational_t r)
{
    return (pow(x, (float)r.numerator / r.denominator));
}