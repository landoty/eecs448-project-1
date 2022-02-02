ships: ship.o test.o
	g++ -std=c++11 -g -Wall ship.o test.o -o ships
test.o: test.cpp ship.h
	g++ -std=c++11 -g -Wall -c test.cpp
ship.o: ship.cpp ship.h
	g++ -std=c++11 -g -Wall -c ship.cpp
clean:
	rm *.o ships
