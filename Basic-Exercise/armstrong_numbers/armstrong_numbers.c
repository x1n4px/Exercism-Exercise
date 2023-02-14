#include "armstrong_numbers.h"
#include<math.h>
bool is_armstrong_number(int candidate){
    int num_original = candidate;
    int num_digitos = 0;
    int suma_digitos = 0;
    while (candidate != 0) {
        num_digitos++;
        candidate /= 10;
    }
    candidate = num_original;
    while (candidate != 0) {
        int digito = candidate % 10;
        suma_digitos += pow(digito, num_digitos);
        candidate /= 10;
    }
    return (suma_digitos == num_original);

    
}