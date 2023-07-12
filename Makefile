CC=tcc
all: tests
run: shortcodes
	./shortcodes
shortcodes.c: shortcodes.rl
	ragel -G2 shortcodes.rl -o shortcodes.c
shortcodes: shortcodes.c
	$(CC) shortcodes.c -lbg -g -o shortcodes
tests: shortcodes.c shortcodes.h tests.c
	$(CC) tests.c shortcodes.c -lbg -lcgreen -g -o tests
	./tests
clean:
	rm -f shortcodes shortcodes.c
