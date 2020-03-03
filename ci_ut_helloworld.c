#include <stdio.h>
#include "ci_ut_helloworld_config.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Hello world, this a CI UT example.\n");
    } else {
        printf("%s version is %d.%d\nfull arguments are: ", 
                argv[0],
                ci_ut_helloworld_config_VERSION_MAJOR,
                ci_ut_helloworld_config_VERSION_MINOR);
        for (int i=0; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    }
    return 0;
}
