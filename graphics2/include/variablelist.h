/**
 * @file VariableList.h
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


#ifndef USER_VARIABLES_H
#define USER_VARIABLES_H

#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>

#include "constants.h"
#include "variable.h"
using namespace std;


void toupper(char upper[], const char str[]);

class Variablelist {
    public:
	Variablelist();
	~Variablelist();
        bool exist(const char* name);
        bool add(const char* name, const int type);
        bool del(const char* name);

	int get_type(const char* name);
        bool get_value(const char* name, VAR* ret_var);
        bool get_value(const int id, VAR* ret_var);
        int  get_id(const char* name);
        bool set_value(const char* name, const double value);
	bool set_scalar_single(const char* name, int i, int j, int k, const double value);
        bool set_scalar_field(const char* name, const double value);
	bool set_vector_single(const char* name, int i, int j, int k, int dir, const double value);
        bool set_vector_field(const char* name, const double value);

        bool set_range(const char* name, const int type,const double min, const double max);
        double get_range(const char* name, const int type, const int lorH);
	void print();
       
        vector<VAR> var;
        //void set_varables(vector<VAR> * vars);
        //void get_variables(vector<VAR> * vars);
    private:
        //vector<VAR> var;
};


#endif
