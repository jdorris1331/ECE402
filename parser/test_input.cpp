#include <iostream>

#include "infile_parser.h"
#include "variablelist.h"
using namespace std;

// create temporary variablelist and add each new value and return value

int main() {
  infile_parser fileP;
  Variablelist *vars = new Variablelist(100,100,100);
  fileP.parse("new_problem.txt", vars);
  vars->print();
  delete vars;
return 0;
}
