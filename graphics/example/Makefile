CC = clang++ -std=c++11
CFLAGS =  $(MATHGLI) $(GSLI) $(FLTKI) $(HEADERS)
#INCLUDES
HEADERS = -I ../include
MATHGLI = -I /usr/local/cellar/mathgl/2.2.2.1/include 
GSLI = -I /usr/local/cellar/gsl/1.16/include 
FLTKI = -I /usr/local/cellar/fltk/1.3.2_1/include
#LIBS
AL = -L../lib -lanimation
MATHGLL = -L/usr/local/Cellar/MathGL/2.2.2.1/lib -lmgl -lmgl-fltk
LIBS = $(AL) $(MATHGLL)  
EXECUTABLES = example1

all: $(EXECUTABLES)

example1:	example1.o 
	$(CC) $(CFLAGS) -o $@ $^  $(LIBS)

%.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@ 


clean: 
	rm *.o






