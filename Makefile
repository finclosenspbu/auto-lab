# Сборочные цели проекта: сборка, тест, установка.
# Именно эти цели вызывают CI и упаковщик пакета.

CC      = gcc
CFLAGS  = -std=c11 -Wall -Wextra -O2 -g -Iinclude -DVERSION=\"$(VERSION)\"
PREFIX  = /usr/local
VERSION = 1.1.0

BIN  = hello
OBJS = src/main.o src/greet.o

.PHONY: all test install clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^

src/%.o: src/%.c include/greet.h
	$(CC) $(CFLAGS) -c $< -o $@

tests/test_greet: tests/test_greet.c src/greet.o
	$(CC) $(CFLAGS) -o $@ $^

test: tests/test_greet
	./tests/test_greet

# DESTDIR — корень «будущей системы»: так пакет собирается без root.
install: $(BIN)
	install -d $(DESTDIR)$(PREFIX)/bin
	install -m 0755 $(BIN) $(DESTDIR)$(PREFIX)/bin/$(BIN)

clean:
	rm -f $(BIN) src/*.o tests/test_greet
