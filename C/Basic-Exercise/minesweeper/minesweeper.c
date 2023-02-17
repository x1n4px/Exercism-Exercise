#include "minesweeper.h"
#include <string.h>
#include <stdlib.h>
/*
 - - -
 - * -
 - - -

 1 1 1
 1 * 1
 1 1 1


*/
static size_t annotation_size = 0;

char** annotate(const char** minefield, const size_t rows)
{
    if (minefield == NULL) return NULL;
    annotation_size = rows;
    size_t cols = strlen(minefield[0]);
    char** output = malloc(rows*sizeof(char*));
    for (size_t i = 0; i < rows; i++) {
        output[i] = malloc(cols + 1);
        strcpy(output[i], minefield[i]);
    }
    for (int ri = 0; ri < (int)rows; ri++)
    {
        for (int ci = 0; ci < (int)cols; ci++) {
            if (output[ri][ci] == '*') {
                for (int r = ri - 1; r <= ri + 1; r++) {
                    for (int c = ci - 1; c <= ci + 1; c++) {
                        if ((r != ri || c != ci) && r >= 0 && r < (int)rows && c >= 0 && c < (int)cols && output[r][c] != '*') {
                            if (output[r][c] == ' ') output[r][c] = '0';
                            output[r][c] += 1;
                        }
                    }
                }
            }
        }
    }
    return output;
}

void free_annotation(char **annotation){
    for (size_t i = 0; i < annotation_size; i++)
    {
        free(annotation[i]);
    }
    free(annotation);
}
