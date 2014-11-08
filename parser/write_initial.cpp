#include <iostream>
#include <fstream>

using namespace std;

int main() {
  int num_vars=2;
  ofstream outfile;
  outfile.open("initial.txt");
  outfile << "x y z var1 var2\n";
  for(int i=0;i<100;i++) {
    for(int j=0;j<100;j++) {
      for(int k=0;k<100;k++) {
        outfile << i << " " << j << " " << k; 
        for(int l=0;l<num_vars;l++) {
          outfile << " " << l; 
        }
        outfile << "\n";
      }
    }
  }
  outfile.close();
  return 0;
}
