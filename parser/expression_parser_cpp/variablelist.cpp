/**
 * @file VariableList.cpp
 *
 * @brief The class VariableList can manages a list with variables.
 *
 * @license
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy
 * of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 *
 * Copyright (C) 2007-2011 Jos de Jong, http://www.speqmath.com
 *
 * @author 	Jos de Jong, <wjosdejong@gmail.com>
 * @date	2007, updated 2012-02-06
 */


#include "variablelist.h"
#include <iostream>
/*
 * Initialize the size of the space
 */

Variablelist::Variablelist(int size_x, int size_y, int size_z) {
  x = size_x;
  y = size_y;
  z = size_z;
  dim = 3;
}

Variablelist::~Variablelist() {

  for(int i=0;i<var.size();i++) {
    if(var[i].type==1) {
      for(int j=0;j<x;j++) {
        for(int k=0;k<y;k++) {
          delete[] var[i].sf[j][k];
        }
      }
    }
    else if(var[i].type==2) {
      for(int j=0;j<x;j++) {
        for(int k=0;k<y;k++) {
          for(int l=0;l<z;l++) {
            delete[] var[i].vf[j][k][l];
          }
        }
      }
    } 
  }
  std::cout << "deleted stuff\n"; 
}

/*
 * Returns true if the given name already exists in the variable list
 */
bool Variablelist::exist(const char* name)
{
    return (get_id(name) != -1);
}


/*
 * Add a name and value to the variable list
 */
bool Variablelist::add(const char* name, const int type)
{
    VAR new_var;
    strncpy(new_var.name, name, 30);
    new_var.type = type;

    int id = get_id(name);
    if (id == -1)
    {
        // variable does not yet exist
        var.push_back(new_var);
        id = get_id(name);
    }
    else
    {
        // variable already exists. overwrite it
        var[id] = new_var;
    }
    
    //scalar field
    if(var[id].type == 1) {
      var[id].sf = new double**[x];
      for(int i=0;i<x;i++) {
        var[id].sf[i] = new double*[y];
        for(int j=0;j<y;j++) {
          var[id].sf[i][j] = new double[z];
        } 
      }
    }
    //vector field
    else if(var[id].type == 2) {
      var[id].vf = new double***[x];
      for(int i=0;i<x;i++) {
        var[id].vf[i] = new double**[y];
        for(int j=0;j<y;j++) {
          var[id].vf[i][j] = new double*[z];
          for(int k=0;k<z;k++) {
            var[id].vf[i][j][k] = new double[dim];
          }
        }
      } 
    }
    return true;
}

/*
 * Delete given variablename from the variable list
 */
bool Variablelist::del(const char* name)
{
    int id = get_id(name);
    if (id != -1)
    {
        var[id] = var[var.size()-1]; // move last item to deleted item
        var.pop_back();              // remove last item
        return true;
    }
    return false;
}

/*
 * Get the type of the specified variable
 */
int Variablelist::get_type(const char* name)
{
    int id = get_id(name);
    return var[id].type;
}

/*
 * Get value of variable with given name
 */
bool Variablelist::get_value(const char* name, double* value)
{
    int id = get_id(name);
    if (id != -1)
    {
        *value = var[id].val;
        return true;
    }
    return false;
}


/*
 * Get value of variable with given id
 */
bool Variablelist::get_value(const int id, double* value)
{
    if (id >= 0 && id < (int)var.size())
    {
        *value = var[id].val;
        return true;
    }
    return false;
}

/*
 * Set the single value of the variable 
 */
bool Variablelist::set_value(const char* name, const double value)
{
    int id = get_id(name);
    if(var[id].type!=0) return false;

    var[id].val = value;	
    return true;
}

/* 
 * Set the scalar field for this type of variable
 */

bool Variablelist::set_scalar_field(const char* name, const double*** scalar_field) {
  int id = get_id(name);
  if(var[id].type!=1) return false;

  for(int i=0;i<x;i++) {
    for(int j=0;j<y;j++) {
      for(int k=0;k<z;k++) {
        var[id].sf[i][j][k] = scalar_field[i][j][k];
      }
    }
  }
  return true;
}

/*
 * Set the vector field for this type of variable
 */

bool Variablelist::set_vector_field(const char* name, const double**** vector_field) {
  int id = get_id(name);
  if(var[id].type!=2) return false;

  for(int i=0;i<x;i++) {
    for(int j=0;j<y;j++) {
      for(int k=0;k<z;k++) {
        for(int l=0;l<dim;l++) {
          var[id].vf[i][j][k][l] = vector_field[i][j][k][l];
        }
      }
    }
  }
  return true;
}



/*
 * Returns the id of the given name in the variable list. Returns -1 if name
 * is not present in the list. Name is case insensitive
 */
int Variablelist::get_id(const char* name)
{
    // first make the name uppercase
    char nameU[NAME_LEN_MAX+1];
    char varU[NAME_LEN_MAX+1];
    toupper(nameU, name);

    for (unsigned int i = 0; i < var.size(); i++)
    {
        toupper(varU, var[i].name);
        if (strcmp(nameU, varU) == 0)
        {
            return i;
        }
    }
    return -1;
}


/*
 * str is copied to upper and made uppercase
 * upper is the returned string
 * str should be null-terminated
 */
void toupper(char upper[], const char str[])
{
    int i = -1;
    do
    {
        i++;
        upper[i] = std::toupper(str[i]);
    }
    while (str[i] != '\0');
}
