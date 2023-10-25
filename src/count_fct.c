int lines_counter(char *str)
{
    int nb_lines = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            nb_lines++;
    }
    return nb_lines;
}

int cols_counter(char *buffer) 
{
    int nb_cols = 0;
    int i = 0;

    while (buffer[i] != '\0' && buffer[i] != '\n') {
        i++;
    }
    if (buffer[i] == '\n') {
        i++;
    }
    while (buffer[i] != '\0' && buffer[i] != '\n') {
        nb_cols++;
        i++;
    }

    return nb_cols;
}