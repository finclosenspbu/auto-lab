/* main.c — точка входа утилиты hello. */
#include "greet.h"

#include <stdio.h>
#include <string.h>

#ifndef VERSION
#define VERSION "unknown"
#endif

int main(int argc, char **argv)
{
    if (argc > 1 && strcmp(argv[1], "--version") == 0) {
        printf("hello %s\n", VERSION);
        return 0;
    }

    const char *name = (argc > 1) ? argv[1] : "world";
    printf("%s\n", greet(name));
    return 0;
}
