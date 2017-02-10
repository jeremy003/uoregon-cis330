all: reversi

reversi.o: reversi.h reversi.cpp
	gcc -std=c++11 -g -c reversi.cpp -o reversi.o

chip.o: chip.h chip.cpp
	gcc -std=c++11 -g -c chip.cpp -o chip.o

reversi: main.cpp chip.o reversi.o
	gcc -std=c++11 -g chip.o reversi.o main.cpp -o reversi

clean:
	rm *.o reversi
