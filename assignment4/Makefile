all: reversi

reversi.o: reversi.h reversi.cpp
	g++ -std=c++11 -g -c reversi.cpp -o reversi.o

reversi: main.cpp reversi.o
	g++ -std=c++11 -g reversi.o main.cpp -o reversi

clean:
	rm *.o reversi
