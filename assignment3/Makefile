all: reversi

reversi.o: reversi.h reversi.c
	gcc -c reversi.c -o reversi.o

reversi: main.c reversi.o
	gcc reversi.o main.c -o reversi

clean: 
	rm *.o reversi
