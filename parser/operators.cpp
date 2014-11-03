#include <iostream>

using namespace std;

struct variable {
  int type;
  string name;
  double *** scalar_field;
  double **** vector_field;
  double value;
};

variable add(variable A, variable B) {
  variable ret_val;
  if(A.type==0 && B.type==0) {
    ret_val.type = 0;
    ret_val.single = A.single + B.single;
  }
  if(A.type==1 && B.type==2) {
    ret_val.type = -1;
    return ret_val;
  }
  return ret_val;
}

int main() {
  variable A,B;
  A.type = 0;
  A.single = 3;
  B.type = 0;
  B.single = 2;
  cout << add(A,B).single;
  return 0;
}
