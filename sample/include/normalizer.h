#include "variable.h"
#include <vector>
#include <mgl2/mgl.h>
using namespace std;




void dumbNormalizer(VAR & , mglData* ex, mglData* ey, mglData *ez, int n);


void normalize_scalar(vector<VAR> *vars, int* hide, int* priority, double* color_values,  mglData* plot_data);


void normalize_vector(vector<VAR> *vars, int vect_num, int scale, mglData* ex, mglData* ey, mglData* ez);
