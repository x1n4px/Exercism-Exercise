#include "binary.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int convert(const char *input)
{
    int input_length = strlen(input);
    int sum = 0;

    for (int i = 0; i < input_length; i++)
    {

        int digit = input[input_length - 1 - i] - '0';
        if (digit != 0 && digit != 1)
        {
            return -1;
        }
        sum += digit * pow(2, i);
    }

    return sum;
}