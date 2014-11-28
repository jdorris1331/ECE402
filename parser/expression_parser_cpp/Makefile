all: strings

main: parser.o error.o functions.o variablelist.o
	g++ parser.o error.o functions.o variablelist.o -o main main.cpp

strings: parser.o error.o functions.o variablelist.o
	g++ parser.o error.o functions.o variablelist.o -o strings strings.cpp

pointers: variable.o functions.o
	g++ variable.o functions.o -o pointers pointers.cpp

variable.o: variable.cpp
	g++ -c variable.cpp

parser.o: parser.cpp
	g++ -c parser.cpp

error.o: error.cpp
	g++ -c error.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

variablelist.o: variablelist.cpp
	g++ -c variablelist.cpp

clean: 
	rm -rf *o strings
