#include <iostream>
#include <vector>
#include "operators.h"
#include "variable.h"

using namespace std;

int main() {
  vector<VAR> vars;
  vars.resize(10);
  vars[0].set_type(1);
  vars[1].set_type(1);
  vars[0].sf[1][1][1] = 2;
  vars[1].sf[1][1][1] = 3;
  sub(&vars[0],&vars[1],&vars[2]);
  cout << vars[2].sf[1][1][1] << endl;
}
