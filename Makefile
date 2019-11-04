# main: main.o funcs.o
# 	g++ -o main main.o funcs.o
#
# tests: tests.o funcs.o
# 	g++ -o tests tests.o funcs.o
#
# main.o: main.cpp funcs/funcs.h
# 	g++ -c main.cpp
#
# tests.o: test/tests.cpp funcs/funcs.h
# 	g++ -c test/tests.cpp
#
# funcs.o: funcs/funcs.cpp funcs/funcs.h
# 	g++ -c funcs/funcs.cpp
#
# clean:
# 	rm main.o funcs.o tests.o main tests

FLAGS=-std=c++14

main: main.o funcs.o
	g++ $(FLAGS) -o main main.o funcs.o

tests: tests.o funcs.o
	g++ $(FLAGS) -o tests tests.o funcs.o

main.o: main.cpp funcs/funcs.h
	g++ $(FLAGS) -c main.cpp

funcs.o: funcs/funcs.cpp funcs/funcs.h
	g++ $(FLAGS) -c funcs/funcs.cpp

tests.o: test/tests.cpp funcs/funcs.h
	g++ $(FLAGS) -c test/tests.cpp

clean:
	rm funcs.o main.o tests.o
