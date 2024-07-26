all: shortcodes.o
shortcodes.c: shortcodes.rl
	ragel -G2 shortcodes.rl -o shortcodes.c
clean:
	rm -f shortcodes.o
shortcodes.o: shortcodes.c
	$(CC) -O3 -c -o shortcodes.o shortcodes.c
