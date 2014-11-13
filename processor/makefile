all: op_test 

op_test: operators.o variable.o
	g++ variable.o operators.o -o op_test op_test.cpp

operators.o: operators.cpp
	g++ -c operators.cpp

variable.o: variable.cpp
	g++ -c variable.cpp

clean: 
	rm -rf *o op_test
