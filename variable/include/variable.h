/*********************************************************
*     *****
*    *~~~~~*   Partial Differential Equations Resource
*     *o o*              (PDER)
*     *  *
*     * *     By: Joseph Dorris, Joey Allen, ALex Kotzman
*    **                   and Wilson Parker
*   *
*********************************************************/

#ifndef VARIABLE_DEF
#define VARIABLE_DEF

#include "constants.h"

class VAR
{
  public:
    VAR();
    ~VAR();
    VAR & operator=(const VAR &rhs);
    char name[NAME_LEN_MAX+1];
    void set_type(const int type);
    int get_type() const;
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
