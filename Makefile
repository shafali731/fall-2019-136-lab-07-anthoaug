main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

main.o: main.cpp funcs/funcs.h
	g++ -c main.cpp

tests.o: test/tests.cpp funcs/funcs.h
	g++ -c test/tests.cpp

funcs.o: funcs/funcs.cpp funcs/funcs.h
	g++ -c funcs/funcs.cpp

clean:
	rm main.o funcs.o tests.o main tests