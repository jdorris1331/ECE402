all: main

main: parser.o error.o functions.o variablelist.o
	g++ parser.o error.o functions.o variablelist.o -o main main.cpp

joe_test: parser.o error.o functions.o variablelist.o
	g++ parser.o error.o functions.o variablelist.o -o joe_test joe_test.cpp

parser.o: parser.cpp
	g++ -c parser.cpp

error.o: error.cpp
	g++ -c error.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

variablelist.o: variablelist.cpp
	g++ -c variablelist.cpp

clean: 
	rm -rf *o main
