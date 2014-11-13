
#ifndef VARIABLE_DEF
#define VARIABLE_DEF

#include "constants.h"

struct VAR
{
  VAR();
  ~VAR();
  char name[NAME_LEN_MAX+1];
  int type;
  double *** sf;
  double **** vf;
  double val;
  double warn_min;
  double warn_max;
  double show_min;
  double show_max;
};

#endif
