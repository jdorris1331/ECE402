CC = clang++ -std=c++11
HEADERS = -I../include
MATHGLI = -I/usr/local/cellar/mathgl/2.2.2.1/include 
GSLI = -I/usr/local/cellar/gsl/1.16/include
FLTK = -I/usr/local/cellar/fltk/1.3.2_1/include
LIBS = -L../lib -l
CFLAGS = -Wall $(HEADERS) $(MATHGLI) $(GSLI) $(FLTK) 
AR = ar
CPP_FILES := $(wildcard *.cpp)
OBJ_FILES := $(notdir $(CPP_FILES:.cpp=.o))

.PHONY: all clean

all: libanimation.a

libanimation.a: $(OBJ_FILES)
	$(AR) rvu $@ $(OBJ_FILES)
	ranlib $@


%.o: %.cpp
	$(CC) -c $(CFLAGS)  $< -o $@

clean:
	rm -f *.o libanimation.a





