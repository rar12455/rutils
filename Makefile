CC      = cc
CFLAGS  = -Wall -Wextra -Werror -std=c99 -O2
PREFIX  = /usr/local

BIN     = ls
SRC     = src/ls.c

all: $(BIN)

ls: src/ls.c
	$(CC) $(CFLAGS) -o $@ $<

install: all
	install -Dm755 ls $(DESTDIR)$(PREFIX)/bin/ls

clean:
	rm -f $(BIN)

.PHONY: all clean install
