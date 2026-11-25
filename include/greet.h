/* greet.h — интерфейс модуля приветствия.
 * Заголовок лежит отдельно от исходников: так его можно установить
 * в /usr/include и использовать из других программ.
 */
#ifndef GREET_H
#define GREET_H

/* Возвращает приветствие для name в статическом буфере. */
const char *greet(const char *name);

/* Сколько раз вызывали greet(). Нужно для теста. */
int greet_calls(void);

#endif /* GREET_H */
