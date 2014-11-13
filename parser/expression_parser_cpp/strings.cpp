#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "parser.h"
#include "variablelist.h"

using namespace std;

int main() {
Variablelist * vars = new Variablelist(100,100,100); 

Parser prs(100,100,100);

vars->add("DT",0);
vars->set_value("DT",.1);
vars->add("T",0);
vars->set_value("T",0);

  string test[4]; 
  
  test[0] = "l=4e5";
  test[1] = "sin(2)";
  test[2] = "T=2";
  test[3] = "T=T+dt";
  

  //getline(cin, test);
  //cout << test;
  
  char** eqs;
  eqs = new char*[4];
  for(int i=0;i<4;i++) {
    eqs[i] = new char[255]; 
    memcpy(eqs[i],test[i].c_str(),test[i].size());
    eqs[i][test[i].size()] = 0;
    cout << eqs[i] << "\n";
  }

  prs.set_eqs(eqs, 4);
  prs.solve(vars);

  vars->print();

/*  if(vars[0].type == 0) {
    cout << vars[0].val << endl;
  }
  //if(vars[1].type == 0) {
    cout << vars[1].val << endl;
  //}
*/

delete vars;

return 0;
}
