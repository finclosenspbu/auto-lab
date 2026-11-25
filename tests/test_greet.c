/* test_greet.c — минимальный тест без фреймворка.
 *
 * Сборка и запуск: make test
 * Возвращает 0, если все проверки прошли, и 1 при первой ошибке —
 * именно это нужно CI: ненулевой код останавливает сборку.
 */
#include "greet.h"

#include <stdio.h>
#include <string.h>

static int failures = 0;

static void check(int ok, const char *what)
{
    if (!ok) {
        printf("FAIL: %s\n", what);
        failures++;
    } else {
        printf("ok:   %s\n", what);
    }
}

int main(void)
{
    check(strcmp(greet("Linux"), "Hello, Linux!") == 0, "обычное имя");
    check(strcmp(greet(NULL), "Hello, world!") == 0, "NULL заменяется на world");
    check(strcmp(greet(""), "Hello, world!") == 0, "пустая строка заменяется");
    check(greet_calls() == 3, "счётчик вызовов");

    if (failures) {
        printf("\n%d проверок не прошло\n", failures);
        return 1;
    }

    printf("\nвсе проверки прошли\n");
    return 0;
}
