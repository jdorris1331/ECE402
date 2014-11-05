
#ifndef VARIABLE_DEF
#define VARIABLE_DEF

#include "constants.h"

struct VAR
{
  char name[NAME_LEN_MAX+1];
  int type;
  double *** sf;
  double **** vf;
  double val;
};

#endif
