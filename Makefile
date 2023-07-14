CC=gcc
all: test
shortcodes.c: shortcodes.rl
	ragel -G2 shortcodes.rl -o shortcodes.c
tests.so: shortcodes.c tests.c
	$(CC) -fPIC -shared -g -o $@ $^ -lbg -lcgreen
clean:
	rm -f shortcodes.c *.o *.so tests
test: tests.so
	cgreen-runner $^
debug:
	cgreen-debug tests.so
%o: %c
	$(CC) -g -c -o $@ $^
shortcodes.a: shortcodes.o
	ar rcs $@ $^
.PHONY: test debug
