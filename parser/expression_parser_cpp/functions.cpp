#include "error.h"
#include "variable.h"
#include "functions.h"
using namespace std;

/*
 * calculate factorial of value
 * for example 5! = 5*4*3*2*1 = 120
 */
double factorial(double value)
{
    double res;
    int v = static_cast<int>(value);

    if (value != static_cast<double>(v))
    {
        throw Error(-1, -1, 400, "factorial");
    }

    res = v;
    v--;
    while (v > 1)
    {
        res *= v;
        v--;
    }

    if (res == 0) res = 1;        // 0! is per definition 1
    return res;
}

/*
 * calculate the sign of the given value
 */
double sign(double value)
{
    if (value > 0) return 1;
    if (value < 0) return -1;
    return 0;
}


void add(VAR* A, VAR* B, VAR* ret_val) {
  int type1 = A->get_type();
  int type2 = B->get_type();
  if(type1==0 && type2==0) {
    ret_val->set_type(0);
    ret_val->val = A->val + B->val;
  }
  if(type1 == 2 && type2 == 2){
	ret_val->set_type(2);
	for(int v = 0; v < 2; v++){
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					ret_val->vf[x][y][z][v] = A->vf[x][y][z][v] + B->vf[x][y][z][v];
				}
			}
		}
	}
  }
  if(type1 == 1 && type2 == 1){
	ret_val->set_type(1);
	for(int x = 0; x < DIM_SIZE; x++){
		for(int y = 0; y < DIM_SIZE; y++){
			for(int z = 0; z < DIM_SIZE; z++){
				ret_val->sf[x][y][z] = A->sf[x][y][z] + B->sf[x][y][z];
			}
		}
	}
  }
 

  if((type1 == 1 && type2 == 0)){
	ret_val->set_type(1);
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					ret_val->sf[x][y][z] = A->sf[x][y][z] + B->val;
				}
			}
		}
	}
  if((type1 == 0 && type2 == 1)){
	ret_val->set_type(1);
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					ret_val->sf[x][y][z] = A->val + B->sf[x][y][z];
				}
			}
		}
	}
 
 if((type1==1 && type2==2) || (type1 == 2 && type2 == 1)) {
    ret_val->set_type(-1);
  }
}

void sub(VAR* A, VAR* B, VAR* ret_val) {
  int type1 = A->get_type();
  int type2 = B->get_type();
  if(type1==0 && type2==0) {
    ret_val->set_type(0);
    ret_val->val = A->val - B->val;
  }
  if(type1 == 2 && type2 == 2){
	ret_val->set_type(2);
	for(int v = 0; v < 2; v++){
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					ret_val->vf[x][y][z][v] = A->vf[x][y][z][v] - B->vf[x][y][z][v];
				}
			}
		}
	}
  }
  if(type1 == 1 && type2 == 1){
	ret_val->set_type(1);
	for(int x = 0; x < DIM_SIZE; x++){
		for(int y = 0; y < DIM_SIZE; y++){
			for(int z = 0; z < DIM_SIZE; z++){
				ret_val->sf[x][y][z] = A->sf[x][y][z] - B->sf[x][y][z];
			}
		}
	}
  }
  if((type1 == 1 && type2 == 0)){
	ret_val->set_type(1);
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					ret_val->sf[x][y][z] = A->sf[x][y][z] - B->val;
				}
			}
		}
	}
  if((type1 == 0 && type2 == 1)){
	ret_val->set_type(1);
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					ret_val->sf[x][y][z] = A->val - B->sf[x][y][z];
				}
			}
		}
	}
  if((type1==1 && type2==2) || (type1 == 2 && type2 == 1)) {
    ret_val->set_type(-1);
  }
}

void mult(VAR* A, VAR* B, VAR* ret_val) {
  int type1 = A->get_type();
  int type2 = B->get_type();
  if(type1==0 && type2==0) {
    ret_val->set_type(0);
    ret_val->val = A->val - B->val;
  }
  if(type1 == 2 && type2 == 2){
	ret_val->set_type(2);
	for(int v = 0; v < 2; v++){
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					ret_val->vf[x][y][z][v] = A->vf[x][y][z][v] * B->vf[x][y][z][v];
				}
			}
		}
	}
  }
  if(type1 == 1 && type2 == 1){
	ret_val->set_type(1);
	for(int x = 0; x < DIM_SIZE; x++){
		for(int y = 0; y < DIM_SIZE; y++){
			for(int z = 0; z < DIM_SIZE; z++){
				ret_val->sf[x][y][z] = A->sf[x][y][z] * B->sf[x][y][z];
			}
		}
	}
  }
  if((type1 == 1 && type2 == 0)){
	ret_val->set_type(1);
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					ret_val->sf[x][y][z] = A->sf[x][y][z] * B->val;
				}
			}
		}
	}
  if((type1 == 0 && type2 == 1)){
	ret_val->set_type(1);
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					ret_val->sf[x][y][z] = A->val * B->sf[x][y][z];
				}
			}
		}
	}
  if((type1==1 && type2==2) || (type1 == 2 && type2 == 1)) {
    ret_val->set_type(-1);
  }
}

void divide(VAR* A, VAR* B, VAR* ret_val) {
  int type1 = A->get_type();
  int type2 = B->get_type();
  if(type1==0 && type2==0) {
    ret_val->set_type(0);
    ret_val->val = A->val - B->val;
  }
  if(type1 == 2 && type2 == 2){
	ret_val->set_type(1);
	for(int v = 0; v < 2; v++){
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					if(B->vf[x][y][z][v] != 0) ret_val->vf[x][y][z][v] = A->vf[x][y][z][v] / B->vf[x][y][z][v];
					else ret_val->vf[x][y][z][v] = -1;
				}
			}
		}
	}
  }
  if(type1 == 1 && type2 == 1){
	ret_val->set_type(1);
	for(int x = 0; x < DIM_SIZE; x++){
		for(int y = 0; y < DIM_SIZE; y++){
			for(int z = 0; z < DIM_SIZE; z++){
				if(B->sf[x][y][z] != 0) ret_val->sf[x][y][z] = A->sf[x][y][z] / B->sf[x][y][z];
				else ret_val->sf[x][y][z] = -1;
			}
		}
	}
  }
  if((type1 == 1 && type2 == 0)){
	ret_val->set_type(1);
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					if(B->val != 0) ret_val->sf[x][y][z] = A->sf[x][y][z] / B->val;
					else ret_val->sf[x][y][z] = -1;
				}
			}
		}
	}
  if((type1 == 0 && type2 == 1)){
	ret_val->set_type(1);
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					if(B->sf[x][y][z] != 0) ret_val->sf[x][y][z] = A->val / B->sf[x][y][z];
					else ret_val->sf[x][y][z] = -1;
				}
			}
		}
	}
  if((type1==1 && type2==2) || (type1 == 2 && type2 == 1)) {
    ret_val->set_type(-1);
  }
}

double cdf(VAR* A, int x, int y, int z, int v, int d){ //d is the derivative respect

	if(d == 0 && x != 0 && x != DIM_SIZE-1) return (A->vf[x+1][y][z][v] - A->vf[x-1][y][z][v])/2;
	else if(d == 0 && x == 0) return (A->vf[x+1][y][z][v] - 0)/2;
	else if(d == 0 && x == DIM_SIZE-1) return (0 - A->vf[x-1][y][z][v])/2;

	if(d == 1 && y != 0 && y != DIM_SIZE-1) return (A->vf[x][y+1][z][v] - A->vf[x][y-1][z][v])/2;
	else if(d == 1 && y == 0) return (A->vf[x][y+1][z][v] - 0)/2;
	else if(d == 1 && y == DIM_SIZE-1) return (0 - A->vf[x][y-1][z][v])/2;
	
	if(d == 2 && z != 0 && z != DIM_SIZE-1) return (A->vf[x][y][z+1][v] - A->vf[x][y][z-1][v])/2;
	else if(d == 2 && z == 0) return (A->vf[x][y][z+1][v] - 0)/2;
	else if(d == 2 && z == DIM_SIZE-1) return (0 - A->vf[x][y][z-1][v])/2;

return 0;
}

void grad(VAR* A, VAR* ret_val) {
  int type1 = A->get_type();
  
  if(type1 == 0 || type1 == 1){ ret_val->set_type(-1);}
  else {
  ret_val->set_type(type1);
	for(int v = 0; v < 2; v++){
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					if(v == 0) ret_val->vf[x][y][z][v] = cdf(A,x,y,z,v,0);
					if(v == 1) ret_val->vf[x][y][z][v] = cdf(A,x,y,z,v,1);
					if(v == 2) ret_val->vf[x][y][z][v] = cdf(A,x,y,z,v,2);
				}
			}
		}
	}
  } 
}

void curl(VAR* A, VAR* ret_val){
  int type1 = A->get_type();
  ret_val->set_type(type1);
	for(int v = 0; v < 2; v++){
		for(int x = 0; x < DIM_SIZE; x++){
			for(int y = 0; y < DIM_SIZE; y++){
				for(int z = 0; z < DIM_SIZE; z++){
					if(v == 0) ret_val->vf[x][y][z][v] = cdf(A,x,y,z,2,1) - cdf(A,x,y,z,1,2);
					if(v == 1) ret_val->vf[x][y][z][v] = cdf(A,x,y,z,0,2) - cdf(A,x,y,z,2,0);
					if(v == 2) ret_val->vf[x][y][z][v] = cdf(A,x,y,z,1,0) - cdf(A,x,y,z,0,1);
				}
			}
		}
	}
}

void diverg(VAR* A, VAR* ret_val){
  int type1 = A->get_type();
  ret_val->set_type(type1);
	for(int x = 0; x < DIM_SIZE; x++){
		for(int y = 0; y < DIM_SIZE; y++){
			for(int z = 0; z < DIM_SIZE; z++){
				ret_val->sf[x][y][z] = cdf(A,x,y,z,0,0) + cdf(A,x,y,z,1,1) + cdf(A,x,y,z,2,2);
			}
		}
	}
}
	
void laplac(VAR* A, VAR* ret_val){
        VAR* temp;
        grad(A,temp);
	diverg(temp,ret_val);
}

/*
int main() {
  VAR* A,B;
  type1 = 0;
  A->single = 3;
  type2 = 0;
  B->single = 2;
  cout << add(A,B).single;
  return 0;
}*/
