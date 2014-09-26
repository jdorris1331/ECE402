#ifdef __MGL_WRAPPER__
#define __MGL_WRAPPER__

#include <iostream>
#include <mgl2/qt.h>

using namespace std;

//class for interacting with the mathGL window
class mgl_wrapper {
    public:
        mgl_wrapper();
        ~mgl_wrapper();

        void load_data(int size, double* x, double* y, double* z, double* c);
	void plot();
    private:
        mglQT* gr;
        mglData* x, y, z, c;
        int setup(mglGraph *gr);
};

		
#endif		
