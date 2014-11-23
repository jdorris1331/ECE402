all: test_input

test_input: infile_parser.o variable.o variablelist.o
	g++ infile_parser.o variable.o variablelist.o -o test_input test_input.cpp

variable.o: variable.cpp
	g++ -c variable.cpp

infile_parser.o: infile_parser.cpp
	g++ -c infile_parser.cpp

variablelist.o: variablelist.cpp
	g++ -c variablelist.cpp

op_test: operators.o variable.o
	g++ variable.o operators.o -o op_test op_test.cpp

operators.o: operators.cpp
	g++ -c operators.cpp

clean:
	rm -rf *o test_input
