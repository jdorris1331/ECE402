#include <iostream>
#include <vector>
#include "operators.h"
#include "variable.h"

using namespace std;

int main() {
  vector<VAR> vars;
  //vars.resize(10);
  VAR A, B;
  A.set_type(1);
  B.set_type(2);
  A.sf[1][1][1] = 2;
  B.vf[1][1][1][0] = 3;
  vars.push_back(A);
  cout << vars[0].sf[1][1][1];
//  vars.push_back(A);
//  vars.push_back(B);
  //cout << C.sf[1][1][1];
  //vars.push_back(C);
 // sub(&vars[0],&vars[1],&vars[2]);
 // cout << vars[2].sf[1][1][1] << endl;
}
