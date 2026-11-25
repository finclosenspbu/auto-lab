/* greet.c — реализация модуля приветствия. */
#include "greet.h"

#include <stdio.h>

static int calls = 0;

const char *greet(const char *name)
{
    static char buffer[64];

    if (name == NULL || name[0] == '\0')
        name = "world";

    calls++;
    snprintf(buffer, sizeof buffer, "Welcome, %s!", name);
    return buffer;
}

int greet_calls(void)
{
    return calls;
}
