#include "normalizer.h"
#include<iostream>
//show all of the scalar fields based on order of priority
void normalize_scalar(vector<VAR> *vars, int* hide, int* priority, double* color_values,  mglData* plot_data) {
  int num_vars=vars->size();
  int current;

  srand(time(NULL));

  double value,lower,upper;

  for(int i=0;i<DIM_SIZE;i++) {
    for(int j=0;j<DIM_SIZE;j++) {
      for(int k=0;k<DIM_SIZE;k++) {
        current = i+DIM_SIZE*(j+DIM_SIZE*k);
        for(int l=0;l<num_vars;l++) {
          lower=vars->at(priority[l]).show_min;
          upper=vars->at(priority[l]).show_min;
          if(!hide[priority[l]]) {
            if(vars->at(priority[l]).type==1) {
              value=vars->at(priority[l]).sf[i][j][k]; 
              //need to change color to be able to show magnitude
              if(value >= lower && value <= upper) plot_data->a[current] = color_values[priority[l]];
            }
          }
        }
      }
    }
  }
}

//change vector field values to values to show on plot
void normalize_vector(vector<VAR> *vars, int vect_num, int scale, mglData* ex, mglData* ey, mglData* ez) {
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
        if(vars->at(vect_num).type==2) {
          value=vars->at(vect_num).vf[i][j][k][0];
          if(value >= lower && value <= upper) ex->a[current] = value;//(value-lower)/range*scale;
          value=vars->at(vect_num).vf[i][j][k][1];
          if(value >= lower && value <= upper) ex->a[current] = value;//(value-lower)/range*scale;
          value=vars->at(vect_num).vf[i][j][k][2];
          if(value >= lower && value <= upper) ex->a[current] = value;//(value-lower)/range*scale;
        }
      }
    }
  }
  }
}

         
void dumbNormalizer(VAR &  d, mglData* ex, mglData* ey, mglData* ez, int n)
{
	int i, j,  k, i0;
	for(i=0;i<n;i++)  for(j=0;j<n;j++)  for(k=0;k<n;k++)
  	{
    		i0 = i+n*(j+k*n);
    		ex->a[i0]= d.vf[i][j][k][0];
    		ey->a[i0]= d.vf[i][j][k][1];
    		ey->a[i0]= d.vf[i][j][k][2];
/*    		std::cout <<  d.vf[i][j][k][0] << std::endl;
    		std::cout <<  d.vf[i][j][k][1] << std::endl;
    		std::cout <<  d.vf[i][j][k][2] << std::endl;
		std::cout << "i: " << i << std::endl;
		std::cout << "j: " << j << std::endl;
		std::cout << "k: " << k << std::endl;
*/
  	}

		std::cout << "Returing\n" << std::endl;
} 
