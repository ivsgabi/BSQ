#include <stddef.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "fct.h"

char *open_file(char *filename)
{
    char *buffer;
    int fd = 0;
    struct stat sb;
    int filesize = 0;
    int opening_result = 0;
    int reading_result = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return NULL;
    opening_result = stat(filename, &sb);
    if (opening_result < 0)
        return NULL;

    filesize = sb.st_size;
    if (filesize <= 0)
        return NULL;
    buffer = malloc(sizeof(char) * (filesize + 1));
    if (buffer == NULL)
        return NULL;
    reading_result = read(fd, buffer, sb.st_size);
    if (reading_result <= 0)
        return NULL;

    buffer[sb.st_size] = '\0';
    close(fd);
    return (buffer);  
}

char **alloc_array(char **array, int nb_lines, int nb_cols)
{
    array = malloc(sizeof(char *) * (nb_lines + 1));
    if (array == NULL)
        return NULL;

    for (int i = 0; i != nb_lines; i++) {
        array[i] = malloc(sizeof(char) * (nb_cols + 1));
    }
    if (array == NULL)
        return NULL;

    return (array);
}

char **fill_array(char **array, char *str, int nb_lines, int nb_cols) 
{
    int k = 0;

    for (int i = 0; i < nb_lines; i++) {
        for (int j = 0; j < nb_cols; j++) {
            while (str[k] != '\0' && str[k] != '\n') {
                array[i][j] = str[k];
                k++;
                j++;
            }
            if (str[k] == '\n') {
                k++; // Ignorer le caractère de nouvelle ligne
            }
        }
        array[i][nb_cols] = '\0';
    }
    array[nb_lines] = NULL;
    return array;
}

char **str_2_word_array(char *str)
{   
    char **array = NULL;
    int nb_lines = lines_counter(str);
    int nb_cols = cols_counter(str);

    array = alloc_array(array, nb_lines, nb_cols);
    if (array == NULL)
        return NULL;
    array = fill_array(array, str, nb_lines, nb_cols);
    return (array);
   
}