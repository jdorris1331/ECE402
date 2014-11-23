#include <iostream>
#include <cstdlib>
#include <time.h>
#include <mgl2/fltk.h>

#include "variable.h"
#include "constants.h"

using namespace std;

void normalize_scalar(vector<VAR> *vars, int* hide, int* priority, double* color_values, mglData* plot_data);
void normalize_vector(vector<VAR> *vars, int vect_num, mglData* ex, mglData*ey, mglData* ez);
