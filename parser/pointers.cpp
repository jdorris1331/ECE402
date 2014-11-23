#include <iostream>
#include "functions.h"

using namespace std;


VAR* level2();
VAR* level();

VAR* level1(double* ret_val) {
//cout << *ret_val << endl;

return << level2(ret_val);
}

VAR* level2(double* ret_val) {
//cout << *ret_val <<endl;

vector<VAR> vars;
  vars.resize(3);
  vars[0].set_type(1);
  vars[1].set_type(1);
  vars[0].sf[1][1][1] = 2;
  vars[1].sf[1][1][1] = 3;
  sub(&vars[0],&vars[1],&vars[2]);ret_val = 2;

cout << &vars[2] << endl;
}


int main() {
double * test = new double;
VAR * test;
test = level1();
delete test;
}
