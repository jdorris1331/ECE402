#ifndef OPERATORS_DEF
#define OPERATORS_DEF

#include <iostream>
#include "variable.h"

using namespace std;

VAR* add(VAR* A, VAR* B);
VAR* sub(VAR* A, VAR* B);
VAR* mult(VAR* A, VAR* B);
VAR* divide(VAR* A, VAR* B);
VAR* grad(VAR* A);
void curl(VAR* A, VAR* ret_val);
void diverg(VAR* A, VAR* ret_val);
void laplac(VAR* A, VAR* ret_val);

#endif
