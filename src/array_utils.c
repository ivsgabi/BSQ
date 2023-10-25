#include <unistd.h>
#include <stdio.h>
#include "fct.h"

void display_array(char **array)
{
    for(int i = 0; array[i] != NULL; i++) {
        printf("%s\n", array[i]);
    }
}

void display_matrix(int **matrix, int nb_lines, int nb_cols)
{
    for (int i = 0; i != nb_lines; i++) {
        for (int j = 0; j != nb_cols; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}