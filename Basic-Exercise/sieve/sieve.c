#include "sieve.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
    //Init primes at 0
    for(size_t i = 0; i < max_primes; i++){
        primes[i] = 0;
    }

    //Create a boolean list -> all numbers from 2 to limit
    uint32_t count = 0;
    bool *is_prime = (bool *)malloc(sizeof(bool) * (limit-1));
    for(uint32_t i=0; i<limit-1;i++){
        is_prime[i] = true;
    }

    //check all multiples from a prime number as no prime
    for(uint32_t p = 2; p*p<=limit; p++){
        if(is_prime[p-2]){
            for(uint32_t i = p*p; i<=limit; i+=p){
                is_prime[i-2] = false;
            }
        }
    }
    //Save all prime numbers in the list
    for (uint32_t i = 2; i <= limit; i++) {
        if (is_prime[i - 2]) {
            if (count >= max_primes) {
                break;
            }
            primes[count++] = i;
        }
    }

    //free memory from boolean list
    free(is_prime);

    //Return the amount of prime number
    return count;
    
}
