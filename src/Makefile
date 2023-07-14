all: shortcodes.o
shortcodes.c: shortcodes.rl
	ragel -G2 shortcodes.rl -o shortcodes.c
clean:
	rm -f shortcodes.o
%o: %c
	$(CC) -g -c -o $@ $^
