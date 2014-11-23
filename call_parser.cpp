#inlcude <iostream>
#include <strings>
#include "infile_parser.h"
#include "variablelist.h"
#include "expression_parser.h"

using namespace std;

int main() {
  //create parser for problem description
  infile_parser fileP;

  //initalize list of variables and equations
  Variablelist *vars = new Variablelist(100,100,100);
  string *equations = new string[50];

  //parse the description file
  fileP.parse("new_problem.txt", vars, equations);

  //vars->print();

  //create equation parser
  Parser prs(100,100,100);

  char** eqs;
  eqs = new char*[3];
  for(int i=0;i<50;i++) {
    eqs[i] = new char[255];
    memcpy(eqs[i],test[i].c_str(),test[i].size());
    equations[i][test[i].size()] = 0;
    cout << eqs[i] << "\n";
  }
  delete[] equations;

  //set the equations
  prs.set_eqs(eqs, 50);

  //call this in loop for everytimestep
  prs.solve(vars);

  //delete stuff at end
  delete vars;
return 0;
}
