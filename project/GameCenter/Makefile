all: gamecenter

checkerspiece.o: checkerspiece.hpp checkerspiece.cpp
	g++ -std=c++11 -c checkerspiece.cpp -o checkerspiece.o

checkers.o: checkers.hpp checkers.cpp checkerspiece.o
	g++ -std=c++11 -c checkers.cpp -o checkers.o

gamecenter: main.cpp checkerspiece.o checkers.o
	g++ -std=c++11 checkers.o checkerspiece.o main.cpp -o gamecenter

clean:
	rm *.o gamecenter
