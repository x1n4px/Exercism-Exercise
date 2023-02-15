#include "square_root.h"
#include<math.h>
double square_root(double radicand) {
    double guess = radicand / 2;
    double temp;
    //fabs -> calculate the absolute value from the diff btw guess and radicant
    //if diff is less than 0.0001, the program return the actual guess
    while (fabs(guess * guess - radicand) > 0.0001) {
        temp = guess;
        guess = (guess + radicand / guess) / 2;
        if (temp == guess) break;
    }
    return guess;
}
