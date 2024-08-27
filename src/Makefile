all: shortcodes.o
shortcodes.c: shortcodes.rl
	ragel -G2 shortcodes.rl -o shortcodes.c
clean:
	rm -f shortcodes.o
shortcodes.o: shortcodes.c
	$(CC) -O3 -c -o shortcodes.o shortcodes.c
%o: %c
	$(CC) -g -c -o $@ $^

test:
	/bin/true

.PHONY: all test clean
