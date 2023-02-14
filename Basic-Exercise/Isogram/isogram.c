#include "isogram.h"
#include<string.h>
#include <ctype.h>
#include <stdbool.h>

/*
Instructions
Determine if a word or phrase is an isogram.

An isogram (also known as a "non-pattern word") is a word or phrase without a repeating letter, however spaces and hyphens are allowed to appear multiple times.

Examples of isograms:

lumberjacks
background
downstream
six-year-old
The word isograms, however, is not an isogram, because the s repeats.
*/


bool is_isogram(const char phrase[]){
     if (phrase == NULL) {
        return false;
    }
    int letters[26] = {0};  //Crea un array para cada letra
    for (int i = 0; phrase[i] != '\0'; i++) {
        if (!isalpha(phrase[i])) {
            continue;
        }
        int index = tolower(phrase[i]) - 'a';
        if (letters[index] > 0) {
            return false;
        }
        letters[index]++;
    }
    return true;
    
}

/*
!isalpha(phrase[i]) es una condición que se utiliza para determinar si el carácter actual en la cadena phrase es una letra. La función isalpha de la biblioteca estándar de C devuelve un valor diferente de cero si el carácter que se le pasa es una letra (mayúscula o minúscula), y cero si no lo es. El operador ! antes de isalpha significa "no", por lo que !isalpha(phrase[i]) significa "si el carácter actual en phrase no es una letra, entonces sigue adelante con el siguiente carácter". En otras palabras, esta condición se utiliza para ignorar los espacios, signos de puntuación y otros caracteres no alfabéticos que puedan estar presentes en phrase

*/