#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void write_header(ofstream& outfile) {
  //ofstream outfile(file.c_str());
  outfile << "#include <iostream>\n";
  outfile << "#include <cstdlib>\n";
  outfile << "using namespace std;\n\n";
  outfile << "int main() { \n";
  outfile << "cout << \"hello world\" << endl;\n";
  outfile << "return 0;}\n";
}

void write_solve_code(string file, string equation) {
  
}

int main() {
  string file = "solve.cpp";
  ofstream outfile(file.c_str());
  write_header(outfile);
  outfile.close();
  system("./compile.sh"); 
  return 0;  
}
