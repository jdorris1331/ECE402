#include <iostream>
#include <vector>
#include "infile_parser.h"
#include "variablelist.h"
#include "variable.h"
using namespace std;

// create temporary variablelist and add each new value and return value

int main() {
  infile_parser fileP;
  VAR* ret_var;
  Variablelist *vars = new Variablelist(100,100,100);
  vector<string> * equations = new vector<string>;
  fileP.parse("new_problem.txt", vars, equations);
  //vars->get_value("DT", ret_var);
  //cout << ret_var->val << endl;
  for(int i=0;i<equations->size();i++) {
   // cout << equations->at(i) << endl;
  }

  //to get sliders look at each type 
  //  if 0 then set at val and have vary from show_min to show_max
  //  else then slider at show_min*.1 to show_min*10 start at show_min
  //   and slider at show_max*.1 to show_max*10 at show_max

  delete equations;
  delete vars;
return 0;
}
