all: binding test

binding:
	$(MAKE) -C src
test:
	crystal spec -v

.PHONY: binding test