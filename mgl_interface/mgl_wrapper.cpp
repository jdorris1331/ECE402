#include <iostream>
#include <mgl2/qt.h>

using namespace std;

mgl_wrapper:mgl_wrapper() {

}

mgl_wrapper:~mgl_wrapper() {
  
}

void mgl_wrapper:load_data(int size, double* temp_x, double* temp_y, double* temp_z, double* temp_c) {
    x = new mglData(size);
    y = new mglData(size);
    z = new mglData(size);
    c = new mglData(size);
    for(int i=0;i<size;i++) {
        x.a[i] = temp_x[i];
        y.a[i] = temp_y[i];
        z.a[i] = temp_z[i];
        c.a[i] = temp_c[i];
    }        
}

void mgl_wrapper:plot() {
    gr = new mglQT(setup,"3D_PDE");
}

int mgl_wrapper:setup(mglGraph *gr) {
    gr->Title("Test 1");  gr->Rotate(50,60);
    gr->Box();  gr->Dots(x,y,z);
    return 0;
}
/*
int main() {
    mgl_wrapper A;
    A.setup(
}
*/
