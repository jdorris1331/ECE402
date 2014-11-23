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

Variablelist::Variablelist() {
  var.reserve(100);
}

Variablelist::~Variablelist() {
  //std::cout << "deleted stuff\n"; 
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
    //VAR new_var;
    
    //strncpy(new_var.name, name, 30);
    //new_var.set_type(type);

    int id = get_id(name);
    if (id == -1)
    {
        //cout << "Capacity " << var.capacity() << endl;
        //cout << "Variable vector size " << var.size() << endl;
        var.resize(var.size()+1);
        //cout << "New vector size " << var.size() << endl;
        // variable does not yet exist
        strncpy(var[var.size()-1].name,name,30);
        id = get_id(name);
        //cout << "id is " << id << endl;
        var[id].set_type(type);
    }
    else
    {
        // variable already exists. overwrite it
        var[id].set_type(type);
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
        //need to free memory
        var.pop_back();              // remove last item
        return true;
    }
    return false;
}

/*
 * Print desired stuff for debugging
 */
void Variablelist::print()
{
  for(int i=0;i<var.size();i++) {
    cout << var[i].name << " " << var[i].get_type() << endl;
    if(var[i].get_type()==0) cout << var[i].val << "\n"; 
    if(var[i].get_type()==1) cout << var[i].sf[1][2][3] << "\n";
    if(var[i].get_type()==2) cout << var[i].vf[0][0][0][0] << endl;
    cout << "Show range min=" << var[i].show_min << endl;
    cout << "Show range max=" << var[i].show_max << endl;
    cout << "Warn range min=" << var[i].warn_min << endl;
    cout << "Warn range min=" << var[i].warn_max << endl;
  }
}

/*
 * Get the type of the specified variable
 */
int Variablelist::get_type(const char* name)
{
    int id = get_id(name);
    return var[id].get_type();
}

/*
 * Get value of variable with given name
 */
bool Variablelist::get_value(const char* name, VAR* ret_var)
{
    int id = get_id(name);
    if (id != -1)
    {
        *ret_var = var[id];
        return true;
    }
    return false;
}


/*
 * Get value of variable with given id
 */
bool Variablelist::get_value(const int id, VAR* ret_var)
{
    if (id >= 0 && id < (int)var.size())
    {
        *ret_var = var[id];
        return true;
    }
    return false;
}

/*
 * Set the single value of the variable 
 */
bool Variablelist::set_value(const char* name,  double value)
{
    int id = get_id(name);
    if(var[id].get_type()!=0 && var[id].get_type()!=-1) {
      //cout << "value not set\n";
      return false;
    }
    //var[id].val = new double;
    var[id].val = value;
    //cout << value << endl;	
    return true;
}


/* 
 * Set a specific value in  scalar field for this type of variable
 */
bool Variablelist::set_scalar_single(const char* name, int i, int j, int k, const double val) {
  int id = get_id(name);
  if(var[id].get_type()==1) {
    var[id].sf[i][j][k] = val;
    return true;
  }
  return false;
}

/* 
 * Set the scalar field for this type of variable
 */
bool Variablelist::set_scalar_field(const char* name, const double value) {
  int id = get_id(name);
  var[id].set_type(1);
  if(var[id].get_type()==1) {
    for(int i=0;i<DIM_SIZE;i++) {
      for(int j=0;j<DIM_SIZE;j++) {
        for(int k=0;k<DIM_SIZE;k++) {
          var[id].sf[i][j][k] = value;//scalar_field[i][j][k];
        }
      }
    }
    return true;
  }

//need to create if not type 1 and clear old memory
/*
  else if(var[id].get_type()==-1) {
    //var[id].
    var[id].set_type(1); 
    //allocate memory
    var[id].sf = new double**[x];
    for(int i=0;i<x;i++) {
      var[id].sf[i] = new double*[y];
      for(int j=0;j<y;j++) {
        var[id].sf[i][j] = new double[z];
      } 
    }
    
    //store values
    for(int i=0;i<x;i++) {
      for(int j=0;j<y;j++) {
        for(int k=0;k<z;k++) {
          var[id].sf[i][j][k] = scalar_field[i][j][k];
        }
      }
    }
    return true;
  }
*/
  else return false;
}


/* 
 * Set a specific location of vector field for this type of variable
 */
bool Variablelist::set_vector_single(const char* name, int i, int j, int k, int dir, const double val) {
  int id = get_id(name);
  if(var[id].get_type()==2) {
    var[id].vf[i][j][k][dir] = val;
    return true;
  }
  return false;
}


/*
 * Set the vector field for this type of variable
 */
bool Variablelist::set_vector_field(const char* name, const double value) {
  int id = get_id(name);
  var[id].set_type(2);
  //if(var[id].get_type()==2) {
    for(int i=0;i<DIM_SIZE;i++) {
      for(int j=0;j<DIM_SIZE;j++) {
        for(int k=0;k<DIM_SIZE;k++) {
          for(int l=0;l<3;l++) {
            var[id].vf[i][j][k][l] = value;
            //cout << var[id].vf[i][j][k][l] << endl;
          }
        }
      }
    }
  return true;
  
  //need to create memory and clear old memory
//}
  //else if{
  //return false;
}

/*
 * Set ranges for a variable
 */
bool Variablelist::set_range(const char* name, const int type, const double min, const double max) {
  int id = get_id(name);
  if(id==-1) return false;
  if(type==0) {
    var[id].show_min=min;
    var[id].show_max=max;
    return true;
  }
  else if(type==1){
    var[id].warn_min=min;
    var[id].warn_max=max;
    return true; 
  }
  return false;
}

/*
 *  Get a range value for a variable
 */ 
double Variablelist::get_range(const char* name, const int type, const int LorH) {
  int id  = get_id(name);
  if(id==-1) return -1;
  if(type==0) {
    if(LorH==0) return var[id].show_min;
    else return var[id].show_max;
  }
  else if(type==1){
    if(LorH==0) return var[id].warn_min;
    else return var[id].warn_max;
  }
  else return -1;
}

/* 
 * Set the vector of VAR's for other to use
 */
/*void Variablelist::get_variables(vector<VAR>* ret_vars) {
 //for(
}*/


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
