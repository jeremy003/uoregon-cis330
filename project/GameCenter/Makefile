all: gamecenter

checkerspiece.o: checkerspiece.h checkerspiece.cpp
	g++ -std=c++11 -c checkerspiece.cpp -o checkerspiece.o

checkers.o: checkers.h checkers.cpp checkerspiece.o
	g++ -std=c++11 -c checkerspiece.o checkers.cpp -o checkers.o

gamecenter: main.cpp checkers.o
	g++ -std=c++11 checkers.o main.cpp -o gamecenter

clean:
	rm *.o gamecenter
