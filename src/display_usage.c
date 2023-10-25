#include <unistd.h>
#include "fct.h"

int display_usage(void)
{
    char *usage[] = {"Hey there! Here is my new version of the Biggest SQuare Project post TEK1.",
                    "To compile it, you have to execute the binary form of the code w/ a filename.",
                    "Example : mybsq maps-intermediae/gabismap.txt",
                    "Love.", NULL};
    display_array(usage);
    return (50);
}