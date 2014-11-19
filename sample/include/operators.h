#ifndef OPERATORS_DEF
#define OPERATORS_DEF

#include <iostream>
#include "variable.h"
#include <vector>
using namespace std;
vector<VAR> initVfield();
void add(VAR* A, VAR* B, VAR* ret_val);
void sub(VAR* A, VAR* B, VAR* ret_val);
void mult(VAR* A, VAR* B, VAR* ret_val);
void divide(VAR* A, VAR* B, VAR* ret_val);
void grad(VAR* A, VAR* ret_val);
void curl(VAR* A, VAR* ret_val);
void diverg(VAR* A, VAR* ret_val);
void laplac(VAR* A, VAR* ret_val);

#endif
