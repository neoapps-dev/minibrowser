CC = gcc
CFLAGS = `pkg-config --cflags gtk+-3.0 webkit2gtk-4.0`
LDFLAGS = `pkg-config --libs gtk+-3.0 webkit2gtk-4.0`
SRC = main.c
OUT = minibrowser

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -f $(OUT)

install: clean all
	cp ./minibrowser /usr/bin/minibrowser
