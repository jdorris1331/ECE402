/*********************************************************
*     *****
*    *~~~~~*   Partial Differential Equations Resource
*     *o o*              (PDER)
*     *  *
*     * *     By: Joseph Dorris, Joey Allen, ALex Kotzman
*    **                   and Wilson Parker
*   *
*********************************************************/

#include "normalizer.h"

//show all of the scalar fields based on order of priority
void normalize_scalar(vector<VAR> *vars, int* hide, int* priority, double* color_values,  mglData* x, mglData* y, mglData* z, mglData* plot_data) {
/*  int num_vars=vars->size();
  int current;

  vector<int> x;
  vector<int> y;
  vector<int> z;
  vector<double> c;
  srand(time(NULL));

  double value,lower,upper;

  for(int i=0;i<DIM_SIZE;i++) {
    for(int j=0;j<DIM_SIZE;j++) {
      for(int k=0;k<DIM_SIZE;k++) {
        //current = i+DIM_SIZE*(j+DIM_SIZE*k);
        for(int l=0;l<num_vars;l++) {
          lower=vars->at(priority[l]).show_min;
          upper=vars->at(priority[l]).show_min;
          if(!hide[priority[l]]) {
            if(vars->at(priority[l]).get_type()==1) {
              value=vars->at(priority[l]).sf[i][j][k]; 
              //need to change color to be able to show magnitude
              if(value >= lower && value <= upper) {
                x.push_back(i) = color_values[priority[l]];
            }
          }
        }
      }
    }
  }*/
}

//change vector field values to values to show on plot
void normalize_vector(vector<VAR> *vars, int vect_num, mglData* ex, mglData* ey, mglData* ez) {
  int num_vars=vars->size();
  int current;

  double value,lower,upper;
  double range;
  if(vect_num>=0 && vect_num<vars->size()) {
  
  lower = vars->at(vect_num).show_min;
  upper = vars->at(vect_num).show_max;
  range = upper-lower;
  
  for(int i=0;i<DIM_SIZE;i++) {
    for(int j=0;j<DIM_SIZE;j++) {
      for(int k=0;k<DIM_SIZE;k++) {
        current = i+DIM_SIZE*(j+DIM_SIZE*k);
        if(vars->at(vect_num).get_type()==2) {
          value=vars->at(vect_num).vf[i][j][k][0];
          if(value >= lower && value <= upper) ex->a[current] = (value-lower)/range;
          value=vars->at(vect_num).vf[i][j][k][1];
          if(value >= lower && value <= upper) ex->a[current] = (value-lower)/range;
          value=vars->at(vect_num).vf[i][j][k][2];
          if(value >= lower && value <= upper) ex->a[current] = (value-lower)/range;
        }
      }
    }
  }
  }
}

          
