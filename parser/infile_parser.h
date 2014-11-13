#ifndef INFILE_PARSER_H
#define INFILE_PARSER_H

// declarations
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "constants.h"
#include "variablelist.h"

using namespace std;

class infile_parser
{
    // public functions
    public:
        infile_parser();
	~infile_parser();
        bool parse(string file, vector<VAR>* vars, vector<string> * equations);
        //bool get_initial(Variablelist * vars);
    // enumerations
    private:
        bool get_initial(vector<VAR> * vars);
	vector<string> initial_files;
};

#endif
