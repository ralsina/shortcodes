all: binding test

binding:
	$(MAKE) -C src
test:
	crystal spec -v

clean:
	rm src/*.o src/shortcodes.c

.PHONY: binding test clean all
