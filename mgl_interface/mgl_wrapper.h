#ifdef __MGL_WRAPPER__
#define __MGL_WRAPPER__

#include <iostream>

using namespace std;

class mgl_wrapper {
    public:
        mgl_wrapper();
        ~mgl_wrapper();

        load_data(int size, double* x, double* y, double* z, double* c);
	plot();
    private:
        mglQT* gr;
        mglData* x, y, z, c;
};

		
#endif		
