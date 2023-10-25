#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int **get_matrix(char **array, int nb_lines, int nb_cols)
{
    int **matrix = (int **)malloc(sizeof(int *) * (nb_lines + 1));
    
    for (int i = 0; i != nb_lines; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * (nb_cols));
    }

    for (int i = 0; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '\0'; j++) {
            if (array[i][j] == '.')
                matrix[i][j] = 1;
            else if (array[i][j] == 'o')
                matrix[i][j] = 0;
        }
    }
    matrix[nb_lines] = NULL;
    return (matrix);
}


char **inverted_minesweeper(char **array, int nb_lines, int nb_cols)
{
    int **matrix = get_matrix(array, nb_lines, nb_cols);
    display_matrix(matrix, nb_lines, nb_cols);
    return NULL;
}