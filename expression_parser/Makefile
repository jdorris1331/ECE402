HOMEDIR = /Users/sidsdman13/joegit/ECE402
VARDIR  = variable
EXPDIR  = expression_parser
INPDIR  = infile_parser
NORMDIR = normalizer

CFLAGS += -I$(HOMEDIR)/$(VARDIR)/include -I$(HOMEDIR)/$(EXPDIR)/include -I$(HOMEDIR)/$(INPDIR)/include -I$(HOMEDIR)/$(NORMDIR)/include
LDFLAGS += -L$(HOMEDIR)/$(VARDIR)/lib -L$(HOMEDIR)/$(EXPDIR)/lib -L$(HOMEDIR)/$(INPDIR)/lib -L$(HOMEDIR)/$(NORMDIR)/lib

SRC_FILES = variable.cpp variablelist.cpp expression_parser.cpp error.cpp operators.cpp functions.cpp infile_parser.cpp normalizer.cpp 

O_FILES = $(SRC_FILES:%.cpp=%.o)

all: strings

strings: $(O_FILES) strings.o
	g++ $(LDFLAGS) strings.o -o strings

strings.o: 
	g++ $(CFLAGS) -c strings.cpp

#%.o: %.cpp
#	$(CC) -c $(CFLAGS)  $< -o $@

$(HOMEDIR)/(VARDIR)/operators.o: operators.cpp
	g++ -c $(HOMEDIR)/(VARDIR)/operators.cpp

expression_parser.o: expression_parser.cpp
	g++ -c expression_parser.cpp

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
