all: test_input

test_input: infile_parser.o variable.o variablelist.o
	g++ -std=c++11 infile_parser.o variable.o variablelist.o -o test_input test_input.cpp

variable.o: variable.cpp
	g++ -std=c++11 -c variable.cpp

infile_parser.o: infile_parser.cpp
	g++ -std=c++11 -c infile_parser.cpp

variablelist.o: variablelist.cpp
	g++ -std=c++11 -c variablelist.cpp

op_test: operators.o variable.o
	g++ -std=c++11 variable.o operators.o -o op_test op_test.cpp

operators.o: operators.cpp
	g++ -std=c++11 -c operators.cpp

clean:
	rm -rf *o test_input
