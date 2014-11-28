all: strings

main: parser.o error.o functions.o variablelist.o
	g++ parser.o error.o functions.o variablelist.o -o main main.cpp

strings: operators.o variable.o parser.o error.o functions.o variablelist.o
	g++ operators.o variable.o parser.o error.o functions.o variablelist.o -o strings strings.cpp

operators.o: operators.cpp
	g++ -c operators.cpp

parser.o: parser.cpp
	g++ -c parser.cpp

variable.o: variable.cpp
	g++ -c variable.cpp

error.o: error.cpp
	g++ -c error.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

variablelist.o: variablelist.cpp
	g++ -c variablelist.cpp

clean: 
	rm -rf *o strings
