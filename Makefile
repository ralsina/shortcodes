run: shortcodes
	./shortcodes
shortcodes.c: shortcodes.rl
	ragel -G2 shortcodes.rl -o shortcodes.c
shortcodes: shortcodes.c
	tcc shortcodes.c -lbg -g -o shortcodes
