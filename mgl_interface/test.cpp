#include <iostream>
#include "mgl_wrapper.h"

using namespace std;

int main() {
    double x[1000], y[1000], z[1000], c[1000];
    for(int i=0;i<1000;i++){
        x[i] = i;
        y[i] = i;
        z[i] = i;
        c[i] = i;
    }
    mgl_wrapper A;
    A.load_data(1000,x,y,z,c);
    A.plot()
}
