#include "acronym.h"

char *abbreviate(const char *phrase){
    if(phrase == NULL) return NULL;
    if(strlen(phrase) == 0) return NULL;
    char buffer[strlen(phrase)];
    int count = 0;
    bool first_letter = true;
    for(int i=0; phrase[i] != '\0';i++){
        if(isalpha(phrase[i]) && first_letter){
            buffer[count] = toupper(phrase[i]);
            count++;
            first_letter = false;
        }else if(isspace(phrase[i]) || (phrase[i] == '-')){
            first_letter = true;
        }
    }
    char *result = malloc(count*sizeof(char)+1);
    strncpy(result, buffer, count);
    result[count] = '\0';
    return result;
}