#include "variable.h"

VAR::VAR() {}

//always 100 right now- need to fix
VAR::~VAR() {
 if(type==0) {
      //delete var[i].val;
    }
    else if(type==1) {
      for(int j=0;j<100;j++) {
        for(int k=0;k<100;k++) {
          delete[] sf[j][k];
        }
        delete[] sf[j];
      }
      delete[] sf;
    }
    else if(type==2) {
      for(int j=0;j<100;j++) {
        for(int k=0;k<100;k++) {
          for(int l=0;l<100;l++) {
            delete[] vf[j][k][l];
          }
         delete[] vf[j][k];
        }
        delete[] vf[j];
      }
      delete vf;
    }
}
