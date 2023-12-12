#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "fct.h"

int **get_matrix(char **array, int nb_lines, int nb_cols)
{
    int **matrix = malloc(sizeof(int *) * (nb_lines));
    if (matrix == NULL)
        return NULL;
    
    for (int i = 0; i != nb_lines; i++) {
        matrix[i] = malloc(sizeof(int) * (nb_cols));
    }

    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            if (array[i][j] == '.')
                matrix[i][j] = 1;
            else if (array[i][j] == 'o')
                matrix[i][j] = 0;
        }
    }
    matrix[nb_lines - 1] = NULL;
    return (matrix);
}

int gt_minimum_value(char value01, char value02, char value03)
{
    int nb01 = value01 - '0';
    int nb02 = value02 - '0';
    int nb03 = value03 - '0';
    int min = 0;

    if ((nb01 < nb02) && (nb01 < nb03))
        min = nb01;
    else if ((nb02 < nb01) && (nb02 < nb03))
        min = nb02;
    else
        min = nb03;
    
    return min;
}


char **inverted_minesweeper(char **array, int nb_lines, int nb_cols)
{
    int result = 0;

    int **matrix = get_matrix(array, nb_lines, nb_cols);
    if (matrix == NULL)
        return NULL;

    int **matrix_cpy = get_matrix(array, nb_lines, nb_cols);
    if (matrix_cpy == NULL)
        return NULL;
    
    for (int i = 0; i < nb_lines; i++) {
        for (int j = 0; j < nb_cols; j++) {
            if (i + 1 < nb_lines && j + 1 < nb_cols && matrix[i][j] != 0) {
                printf("%d\n", matrix[i][j]);
                matrix_cpy[i][j] =  1 + gt_minimum_value(matrix_cpy[i][j+1], matrix_cpy[i+1][j], matrix_cpy[i+1][j+1]);
            }
            if (matrix_cpy[i][j] > result)
                result = matrix_cpy[i][j];
        }
    }
    display_matrix(matrix_cpy, nb_lines, nb_cols);
    return NULL;
}
