#include "variable.h"

VAR::VAR() {
  type=-1;
}

//always DIM_SIZE right now- need to fix
VAR::~VAR() {
  if(type==0) {
    val=0;
  }
  else if(type==1) {
    for(int j=0;j<DIM_SIZE;j++) {
      for(int k=0;k<DIM_SIZE;k++) {
        delete[] sf[j][k];
      }
      delete[] sf[j];
    }
    delete[] sf;
  }
  else if(type==2) {
    for(int j=0;j<DIM_SIZE;j++) {
      for(int k=0;k<DIM_SIZE;k++) {
        for(int l=0;l<DIM_SIZE;l++) {
          delete[] vf[j][k][l];
        }
        delete[] vf[j][k];
      }
      delete[] vf[j];
    }
    delete vf;
  }
}
VAR& VAR::operator=(const VAR &rhs) {
    int temp = rhs.get_type(); 
    set_type(temp);
    if(get_type()==0) val = rhs.val;
    else if(this->get_type()==1) {
      for(int i=0;i<DIM_SIZE;i++) {
        for(int j=0;j<DIM_SIZE;j++) {
          for(int k=0;k<DIM_SIZE;k++) {
            this->sf[i][j][k]=rhs.sf[i][j][k];
          }
        }
      }
    }
    else if(this->get_type()==2) {
      for(int i=0;i<DIM_SIZE;i++) {
        for(int j=0;j<DIM_SIZE;j++) {
          for(int k=0;k<DIM_SIZE;k++) {
            for(int l=0;l<3;l++) {
              this->vf[i][j][k][l]=rhs.vf[i][j][k][l];
            }
          }
        }
      }
    }
  return *this;
}

void VAR::set_type(const int typex) {
  if(type==typex) {}
  else {
    if(type==1) {
      for(int j=0;j<DIM_SIZE;j++) {
        for(int k=0;k<DIM_SIZE;k++) {
          delete[] sf[j][k];
        }
        delete[] sf[j];
      }
      delete[] sf;
    }
    else if(type==2) {
      for(int j=0;j<DIM_SIZE;j++) {
        for(int k=0;k<DIM_SIZE;k++) {
          for(int l=0;l<DIM_SIZE;l++) {
            delete[] vf[j][k][l];
          }
          delete[] vf[j][k];
        }
        delete[] vf[j];
      }
      delete[] vf;
    }
    if(typex==1) {
      sf = new double**[DIM_SIZE];
        for(int i=0;i<DIM_SIZE;i++) {
          sf[i] = new double*[DIM_SIZE];
          for(int j=0;j<DIM_SIZE;j++) {
            sf[i][j] = new double[DIM_SIZE];
          }
        }
    }
    //vector field
    else if(typex == 2) {
        vf = new double***[DIM_SIZE];
        for(int i=0;i<DIM_SIZE;i++) {
          vf[i] = new double**[DIM_SIZE];
          for(int j=0;j<DIM_SIZE;j++) {
            vf[i][j] = new double*[DIM_SIZE];
            for(int k=0;k<DIM_SIZE;k++) {
              vf[i][j][k] = new double[3];
            }
          }
        }
      }  
  }
  type=typex;
}

int VAR::get_type() const {
  return type;
}
