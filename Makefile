CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror

pa07:
	gcc $(CFLAGS) path.c maze.c -o pa07

testpath: path.o
	gcc $(CFLAGS) maze.o instpath.o -o pa07

path.o:   path.h
	gcc $(CFLAGS) path.c pa07.c maze.c 


gdb: pa07
	gdb --args ./pa07 inputs/maze1 inputs/path1
