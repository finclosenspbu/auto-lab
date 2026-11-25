/* main.c — точка входа утилиты hello.
 * Аргумент командной строки — имя, с которым здороваемся.
 */
#include "greet.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    const char *name = (argc > 1) ? argv[1] : "world";
    printf("%s\n", greet(name));
    return 0;
}
