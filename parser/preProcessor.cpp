#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

double*** add_field(double ***arg1, double ***arg2, int x, int y, int z) {
  int i,j,k;
  double ***ret_val = new double**[x];
  for(i=0;i<x;i++) {
    ret_val[i]=new double*[y];
    for(j=0;j<y;j++) {
      ret_val[i][j] = new double[z];
    }
  }

  for(i=0;i<x;i++) {
    for(j=0;j<y;j++) {
      for(k=0;k<z)k++) {
        ret_val=arg1[i][j][k]+arg2[i][j][k];
      }
    }
  }
  return ret_val;
}

double*** sub_field(double ***arg1, double ***arg2, int x, int y, int z) {
  int i,j,k;
  double ***ret_val = new double**[x];
  for(i=0;i<x;i++) {
    ret_val[i]=new double*[y];
    for(j=0;j<y;j++) {
      ret_val[i][j] = new double[z];
    }
  }

  for(i=0;i<x;i++) {
    for(j=0;j<y;j++) {
      for(k=0;k<z)k++) {
        ret_val=arg1[i][j][k]-arg2[i][j][k];
      }
    }
  }
  return ret_val;
}

double*** mult_field(double ***arg1, double ***arg2, int x, int y, int z) {
  int i,j,k;
  double ***ret_val = new double**[x];
  for(i=0;i<x;i++) {
    ret_val[i]=new double*[y];
    for(j=0;j<y;j++) {
      ret_val[i][j] = new double[z];
    }
  }

  for(i=0;i<x;i++) {
    for(j=0;j<y;j++) {
      for(k=0;k<z)k++) {
        ret_val=arg1[i][j][k]*arg2[i][j][k];
      }
    }
  }
  return ret_val;
}


double*** div_field(double ***arg1, double ***arg2, int x, int y, int z) {
  int i,j,k;
  double ***ret_val = new double**[x];
  for(i=0;i<x;i++) {
    ret_val[i]=new double*[y];
    for(j=0;j<y;j++) {
      ret_val[i][j] = new double[z];
    }
  }

  for(i=0;i<x;i++) {
    for(j=0;j<y;j++) {
      for(k=0;k<z)k++) {
        ret_val=arg1[i][j][k]/arg2[i][j][k];
      }
    }
  }
  return ret_val;
}



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
