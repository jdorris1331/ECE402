#include <iostream>

using namespace std;


double*** test_fun(int x_size, int y_size, int z_size, int dim, double ***A, double***B) {
	/*double ***B;
	B = new double**[10];
	for(int i=0; i< 10; i++) {
		B[i] = new double*[10];
		for(int j=0; j<10; j++) {
			B[i][j] = new double[10];
				for(int k=0; k<10;k++) { B[i][j][k] = 0;}
		}		
			
	}*/
	//x dimension example
	//B[1][2][1] = (A[0][2][1] - A[2][2][1])/2.0;
	B[1][2][1] = 6;
	return B;
}

double*** add(double***A, double***B, int x_size, int y_size, int z_size, double val, int op) {
	if(op==0) {
		for(int i=0;i<x_size;i++) {
			for(int j=0; j<y_size;j++) {
				for(int k=0;k<z_size;k++) {
					
					

int main() { 
	double ***var1;
	var1 = new double**[10];
	for(int i=0; i< 10; i++) {
		var1[i] = new double*[10];
		for(int j=0; j<10; j++) {
			var1[i][j] = new double[10];
				for(int k=0; k<10;k++) { var1[i][j][k] = 0;}
		}		
			
	}
	double ***var2;
	var2 = new double**[10];
        for(int i=0; i< 10; i++) {
                var2[i] = new double*[10];
                for(int j=0; j<10; j++) {
                        var2[i][j] = new double[10];
                                for(int k=0; k<10;k++) { var2[i][j][k] = 0;}
                }

        }



	var1 = test_fun(10,10,10,0,var1,var2);
	cout << var1[1][2][1] << endl;
return 0;
}
