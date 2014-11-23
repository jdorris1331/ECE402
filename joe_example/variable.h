
#ifndef VARIABLE_DEF
#define VARIABLE_DEF

#include "constants.h"

class VAR
{
  public:
    VAR();
    ~VAR();
    char name[NAME_LEN_MAX+1];
    void set_type(int type);
    int get_type();
    double val;
    double *** sf;
    double **** vf;
    double warn_min;
    double warn_max;
    double show_min;
    double show_max;
  private:
    int type;
};

#endif
