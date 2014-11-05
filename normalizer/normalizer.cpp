#include <iostream>
#include <cstdlib>
#include <time.h>
#include <mgl2/fltk.h>

using namespace std;

int main() {
  int num_vars = 3;
  int priority[3];
  priority[0]=2;
  priority[1]=0;
  priority[2]=1;
  double ranges[num_vars*2];
  ranges[0] = 0;
  ranges[1] = 25.4;
  ranges[2] = -30.8;
  ranges[3] = 100.2;
  ranges[4] = -1;
  ranges[5] = 0;

  int colors[3];
 
  colors[0]=1.0;
  colors[1]=2.0;
  colors[2]=3.0;
  
  int n=100*100*100;
  int current;
  mglData x(n),y(n),z(n),c(n);

  double ****var;
  var = new double***[3];

  for(int i=0;i<3;i++) {
    var[i] = new double**[100];
      for(int j=0;j<100;j++) {
	var[i][j] = new double*[100];
	  for(int k=0;k<100;k++) {
		var[i][j][k] = new double[100];
		for(int l=0;l<100;l++) var[i][j][k][l] = 0;
	  }
      }
  }

  srand(time(NULL));

  for(int i=0;i<100;i++) {
    for(int j=0;j<100;j++) {
      for(int k=0;k<100;k++) {
        current = (i*10000)+(j*100)+k;
//        cout << i << " " << j << " " << k << endl;
        x.a[current] = i;
        y.a[current] = j;
        z.a[current] = k;
        var[0][i][j][k] = (double)(rand() % 500) / 10;
        var[1][i][j][k] = (double)(rand() % 2000) / 10 - 50.0;
        var[2][i][j][k] = (double)(rand() % 500) / 100 - 2.0;
        
        for(int l=0;l<num_vars;l++) {
          for(int m=0;m<num_vars;m++) {
            if(priority[l] == m && c[current]==0) {
              if(var[m][i][j][k] > ranges[2*m] && var[m][i][j][k] < ranges[2*m+1]) { 
                c.a[current]=colors[m];
              }
            }
          }
        }
      }
    }
  }         

  for(int i=0;i<10;i++) {
    cout << x.a[i] << " " << y.a[i] << " " << z.a[i] << " " << c.a[i] << endl;
  }


  for(int i=0;i<3;i++) {
      for(int j=0;j<100;j++) {
	  for(int k=0;k<100;k++) {
		delete[] var[i][j][k];
	  }
	delete[] var[i][j];
      }
    delete[] var[i];
  }
  delete[] var;

return 0;
}
