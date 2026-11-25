/* hot.c — две функции с очень разной ценой: удобно для профилирования.
 *
 * Обычная сборка:      gcc -O2 -o hot hot.c && ./hot 30
 * С профилированием:   gcc -O2 -pg -o hot hot.c && ./hot 30 && gprof -b ./hot gmon.out | head -20
 */
#include <stdio.h>
#include <stdlib.h>

/* Наивная рекурсия: экспоненциальная сложность — главный «горячий» участок. */
static unsigned long fib(int n)
{
    if (n < 2)
        return (unsigned long)n;
    return fib(n - 1) + fib(n - 2);
}

/* Линейный проход: вызывается часто, но стоит дёшево. */
static unsigned long sum_squares(int n)
{
    unsigned long sum = 0;
    for (int i = 1; i <= n; i++)
        sum += (unsigned long)i * (unsigned long)i;
    return sum;
}

int main(int argc, char **argv)
{
    int n = (argc > 1) ? atoi(argv[1]) : 34;
    unsigned long big = 0;

    unsigned long f = fib(n);
    for (int k = 0; k < 200000; k++)
        big += sum_squares(200);

    printf("fib(%d) = %lu\n", n, f);
    printf("sum     = %lu\n", big);
    return 0;
}
