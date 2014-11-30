#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ofstream ofile("initial_test.txt");
  ofile << "X Y Z BOX1 BOX2\n";
  for(int i=0;i<100;i++) {
    for(int j=0;j<100;j++) {
      for(int k=0;k<100;k++) {
         ofile << i << " " << j << " " << k << " ";
         if((i>30) && (i<50) && (j>30) && (j<50) && (k>30) && (k<50)) ofile << 100.0;
         else ofile << 0.0;
         ofile << " ";
         if((i>60) && (i<80) && (j>60) && (j<80) && (k>60) && (k<80)) ofile << 100.0;
         else ofile << 0.0;
         ofile << "\n";
      }
    }
  }
  ofile.close();
  return 0; 
}
