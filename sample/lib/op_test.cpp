#include <iostream>
#include <vector>
#include "operators.h"
#include "variable.h"
#include <stdio.h>

using namespace std;



void initVfield(VAR & vars)
{
        for(int x = 0; x < 100; x++){
                for(int y = 0; y < 100; y++){
                        for(int z = 0; z < 100; z++){
                                for(int v = 0; v < 3; v++){
                                        if((x >= 90) && (y >= 90) && (z >= 90)) vars.vf[x][y][z][v] = 100;
                                      if((x >= 85 && x <= 90) && (y >= 85 && y <= 90) && (z >= 85 && z <= 90))  vars[1].vf[x][y][z][v] = 100;
                                        else{
                                                vars.vf[x][y][z][v] = 0;
                                              vars[1].vf[x][y][z][v] = 0;
                                        }
                                }
                        }
                }
        }

}




/*


int main() {
	vector<VAR> vars;
	vars.resize(10);
	vars[0].set_type(2);
	vars[1].set_type(2);
	for(int x = 0; x < 100; x++){
		for(int y = 0; y < 100; y++){
			for(int z = 0; z < 100; z++){
				for(int v = 0; v < 3; v++){
					if((x >= 97) && (y >= 97) && (z >= 97)) vars[0].vf[x][y][z][v] = 100;
	//				if((x >= 85 && x <= 90) && (y >= 85 && y <= 90) && (z >= 85 && z <= 90))  vars[1].vf[x][y][z][v] = 100;
					else{
						vars[0].vf[x][y][z][v] = 0;
		//				vars[1].vf[x][y][z][v] = 0;
					}
				}
			}
		}
	}				
	//divide(&vars[0],&vars[1],&vars[2]);
	for(int s = 0; s < 10; s++){
		grad(&vars[0],&vars[2]);
//		grad(&vars[1],&vars[3]);
		vars[0] = vars[2];
//		vars[1] = vars[3];
		for(int x = 95; x < 100; x++){
			for(int y = 80; y < 100; y++){
				printf("%.1f, ", vars[2].vf[x][y][97][1]);
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
*/
