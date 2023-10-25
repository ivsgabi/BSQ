char *open_file(char *filename);
int args_errcases(int argc, char **argv);
int display_usage(void);
void display_array(char **array);
char **str_2_word_array(char *str);
int lines_counter(char *str);
int cols_counter(char *buffer);
char **inverted_minesweeper(char **array, int nb_lines, int nb_cols);
void display_matrix(int **matrix, int nb_lines, int nb_cols);
