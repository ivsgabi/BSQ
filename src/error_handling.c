#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "fct.h"

int args_errcases(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0)
        return (display_usage());
    if (argc != 2)
        return (84);
    if (open(argv[1], O_RDONLY) < 0)
        return (84);

    return (0);
}