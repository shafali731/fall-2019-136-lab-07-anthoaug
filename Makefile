main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

main.o: main.cpp funcs/funcs.h
	g++ -c main.cpp

tests.o: tests tests funcs/funcs.h
	g++ -c tests.cpp

funcs.o: funcs/funcs.cpp funcs/funcs.h
	g++ -c funcs.cpp