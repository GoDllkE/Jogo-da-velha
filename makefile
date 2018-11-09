extend: src/extend.c src/extend.h
	gcc -c src/extend.c src/extend.h
	mv extend.o compiled/

game: src/game.c compiled/extend.o
	gcc -c src/game.c
	mv game.o compiled/
	gcc compiled/game.o -o build/game

all: src/extend.c src/extend.h src/game.c
	gcc src/extend.c src/extend.h src/game.c -o build/game
