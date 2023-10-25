#include <stddef.h>
#include <stdio.h>
#include "fct.h"

int main(int argc, char **argv)
{
    char *filename = NULL;
    char *str_map = NULL;
    char **array = NULL;
    char **result = NULL;
    int nb_lines = 0;
    int nb_cols = 0;

    if (args_errcases(argc, argv) != 0)
        return (84);

    filename = argv[1];
    str_map = open_file(filename);
    array = str_2_word_array(str_map);
    nb_lines = lines_counter(str_map);
    nb_cols = cols_counter(str_map);
    inverted_minesweeper(array, nb_lines, nb_cols);
    return (0);
}