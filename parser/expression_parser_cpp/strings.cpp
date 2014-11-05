#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

#include "parser.h"
#include "variable.h"

using namespace std;

int main() {
VAR vars[3]; 

Parser prs(100,100,100);


  string test[3]; 
  test[0] = "4 + 5";
  test[1] = "var =4";
  test[2] = "Ans";
  
  //getline(cin, test);
  //cout << test;
  
  char** eqs;
  eqs = new char*[3];
  for(int i=0;i<3;i++) {
    eqs[i] = new char[255]; 
    memcpy(eqs[i],test[i].c_str(),test[i].size());
    eqs[i][test[i].size()] = 0;
 //   cout << eqs[i] << "\n";
  }

  prs.set_eqs(eqs, 3);
  prs.solve(vars);

  if(vars[0].type == 0) {
    cout << vars[0].val << endl;
  }
  //if(vars[1].type == 0) {
    cout << vars[1].val << endl;
  //}

return 0;
}
