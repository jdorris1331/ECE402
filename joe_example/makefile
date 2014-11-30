HOMEDIR = /Users/sidsdman13/joegit/ECE402
VARDIR  = variable
EXPDIR  = expression_parser
INPDIR  = infile_parser
NORMDIR = normalizer

CFLAGS += -I$(HOMEDIR)/$(VARDIR)/include -I$(HOMEDIR)/$(EXPDIR)/include -I$(HOMEDIR)/$(INPDIR)/include -I$(HOMEDIR)/$(NORMDIR)/include
LDFLAGS += -L$(HOMEDIR)/$(VARDIR)/lib -L$(HOMEDIR)/$(EXPDIR)/lib -L$(HOMEDIR)/$(INPDIR)/lib -L$(HOMEDIR)/$(NORMDIR)/lib

SRC_FILES = variable.cpp variablelist.cpp error.cpp operators.cpp expression_parser.cpp infile_parser.cpp normalizer.cpp 

O_FILES = $(SRC_FILES:%.cpp=%.o)

LIB = $(HOMEDIR)/$(VARDIR)/lib/variablelist.o $(HOMEDIR)/$(EXPDIR)/lib/expression_parser.o $(HOMEDIR)/$(VARDIR)/lib/variable.o $(HOMEDIR)/$(NORMDIR)/lib/normalizer.o $(HOMEDIR)/$(VARDIR)/lib/operators.o $(HOMEDIR)/$(EXPDIR)/lib/error.o $(HOMEDIR)/$(INPDIR)/lib/infile_parser.o cont_data.o 

all: voxels

voxels: $(O_FILES) cont_data.o
	g++ -o voxels -Wall $(LDFLAGS) $(CFLAGS) $(LIB) -lmgl-fltk -lmgl voxels.cpp

cont_data.o: cont_data.cpp
	cd $(HOMEDIR)/joe_example; g++ $(CFLAGS) -c cont_data.cpp

#%.o: %.cpp
#	$(CC) -c $(CFLAGS)  $< -o $@

operators.o: $(HOMEDIR)/$(VARDIR)/lib/operators.cpp
	cd $(HOMEDIR)/$(VARDIR)/lib; g++ -I$(HOMEDIR)/$(VARDIR)/include -c operators.cpp

expression_parser.o: $(HOMEDIR)/$(EXPDIR)/lib/expression_parser.cpp
	cd $(HOMEDIR)/$(EXPDIR)/lib; g++ $(CFLAGS) -c expression_parser.cpp

infile_parser.o: $(HOMEDIR)/$(INPDIR)/lib/infile_parser.cpp
	cd $(HOMEDIR)/$(INPDIR)/lib; g++ $(CFLAGS) -c infile_parser.cpp

normalizer.o: $(HOMEDIR)/$(NORMDIR)/lib/normalizer.cpp
	cd $(HOMEDIR)/$(NORMDIR)/lib; g++ $(CFLAGS) -c normalizer.cpp

variable.o: $(HOMEDIR)/$(VARDIR)/lib/variable.cpp
	cd $(HOMEDIR)/$(VARDIR)/lib; g++ -I$(HOMEDIR)/$(VARDIR)/include -c variable.cpp

variablelist.o: $(HOMEDIR)/$(VARDIR)/lib/variablelist.cpp
	cd $(HOMEDIR)/$(VARDIR)/lib; g++ $(CFLAGS) -c variablelist.cpp

error.o: $(HOMEDIR)/$(EXPDIR)/lib/error.cpp
	cd $(HOMEDIR)/$(EXPDIR)/lib; g++ -I$(HOMEDIR)/$(EXPDIR)/include -c error.cpp

clean: 
	rm -rf *o voxels
