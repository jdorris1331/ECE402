#include <iostream>
#include <vector>
#include "variable.h"
using namespace std;

VAR* add(VAR* A, VAR* B) {
  VAR * ret_val = new VAR;
  int type1 = A->get_type();
  int type2 = B->get_type();
  if(type1==0 && type2==0) {
    ret_val->set_type(0);
    ret_val->val = A->val + B->val;
  }
  if(type1 == 2 && type2 == 2){
  ret_val->set_type(2);
  for(int x = 0; x < DIM_SIZE; x++){ 
    for(int y = 0; y < DIM_SIZE; y++){
      for(int z = 0; z < DIM_SIZE; z++){ 
        for(int v = 0; v < 3; v++){
          ret_val->vf[x][y][z][v] = A->vf[x][y][z][v] + B->vf[x][y][z][v];
        }
      }                         
    }                   
  }             
  }     
  if(type1 == 1 && type2 == 1){
  ret_val->set_type(1);
  for(int x = 0; x < DIM_SIZE; x++){
    for(int y = 0; y < DIM_SIZE; y++){
      for(int z = 0; z < DIM_SIZE; z++){
        ret_val->sf[x][y][z] = A->sf[x][y][z] + B->sf[x][y][z];
      }                         
    }                   
  }             
  }     
  

  if((type1 == 1 && type2 == 0)){
  ret_val->set_type(1);
    for(int x = 0; x < DIM_SIZE; x++){
      for(int y = 0; y < DIM_SIZE; y++){
        for(int z = 0; z < DIM_SIZE; z++){ 
          ret_val->sf[x][y][z] = A->sf[x][y][z] + B->val;
        }
      }
    }
  }
  if((type1 == 0 && type2 == 1)){
  ret_val->set_type(1);
    for(int x = 0; x < DIM_SIZE; x++){
      for(int y = 0; y < DIM_SIZE; y++){
        for(int z = 0; z < DIM_SIZE; z++){
          ret_val->sf[x][y][z] = A->val + B->sf[x][y][z];
        }
      }
    }
  }
 if((type1==1 && type2==2) || (type1 == 2 && type2 == 1)) {
    ret_val->set_type(-1);
  }
  return ret_val;
}
  

int main() {
        vector<VAR> vars;
        vars.resize(10);
        vars[0].set_type(2);
        vars[1].set_type(2);
  for(int x = 0; x < 100; x++){
    for(int y = 0; y < 100; y++){
      for(int z = 0; z < 100; z++){
        for(int v = 0; v < 3; v++){
            vars[0].vf[x][y][z][v] = 1;
            vars[1].vf[x][y][z][v] = 2;
        }
      }
    }
  }
  VAR * ret_var;
 
  ret_var = add(&vars[0],&vars[1]);
  cout << ret_var->vf[0][0][0][0] << endl;
}
