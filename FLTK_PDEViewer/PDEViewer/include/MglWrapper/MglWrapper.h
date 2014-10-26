#ifndef MGLWRAPPER_H
#define MGLWRAPPER_H

#include <iostream>
#include "mgl2/qt.h"

//class for interacting with the mathGL window
class MglWrapper
{
public:
    MglWrapper();
    void loadData(int size, double *x, double *y, double *z, double *c);
    void plot();

private:
    mglQT *gr;
    mglData *x, *y, *z, *c;
    int setup(mglGraph *gr);
};

#endif // MGLWRAPPER_H
