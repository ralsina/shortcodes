run: shortcodes
	./shortcodes
shortcodes.c: shortcodes.rl
	ragel -G2 shortcodes.rl -o shortcodes.c
shortcodes: shortcodes.c
	tcc shortcodes.c bstrlib/bstrlib.c -g -o shortcodes
