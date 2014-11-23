all: voxels

voxels: variable.o normalizer.o operators.o
	g++ variable.o normalizer.o operators.o -o voxels voxels.cpp -lmgl -lmgl-fltk

variable.o: variable.cpp
	g++ -c variable.cpp

normalizer.o: normalizer.cpp
	g++ -c normalizer.cpp

operators.o: operators.cpp
	g++ -c operators.cpp
clean: 
	rm -rf *o voxels
