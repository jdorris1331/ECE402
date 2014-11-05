#include <iostream>

using namespace std;


void level2(double*);
void level(double *);

void level1(double* ret_val) {
//cout << *ret_val << endl;
level2(ret_val);
cout << *ret_val << endl;
}

void level2(double* ret_val) {
//cout << *ret_val <<endl;
*ret_val = 2;
cout << *ret_val << endl;
}


int main() {
double * test = new double;
level1(test);
cout << *test << endl;
delete test;
}
