#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "expression_parser.h"
#include "variablelist.h"

using namespace std;

int main() {
Variablelist * vars = new Variablelist(); 

Parser prs;

vars->add("DT",2);
vars->set_vector_field("DT",.1);
//vars->set_value("DT",.1);
vars->add("T",2);
vars->set_vector_field("T",0);
//vars->print();
cout << endl;

  string test[4]; 
  
  test[0] = "l=T+dt";
  test[1] = "j=t-dt*T";
  test[2] = "T=(rand(T)%100)/100";
  

  //getline(cin, test);
  //cout << test;
  
  char** eqs;
  eqs = new char*[4];
  for(int i=0;i<3;i++) {
    eqs[i] = new char[255]; 
    memcpy(eqs[i],test[i].c_str(),test[i].size());
    eqs[i][test[i].size()] = 0;
//    cout << eqs[i] << "\n";
  }

  prs.set_eqs(eqs, 3);
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
