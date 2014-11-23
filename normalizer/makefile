all: test_input

test_input: infile_parser.o variablelist.o
	g++ infile_parser.o variablelist.o -o test_input test_input.cpp

infile_parser.o: infile_parser.cpp
	g++ -c infile_parser.cpp

variablelist.o: variablelist.cpp
	g++ -c variablelist.cpp

clean: 
	rm -rf *o test_input
