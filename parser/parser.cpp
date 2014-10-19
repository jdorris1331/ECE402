#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  ifstream infile(argv[1]);
  string line;
		
  int num_vars;
  string var_name [50];
  int var_type [50];
  int var_range [100];

  int dim [6];
	
  for(int i=0;i<5;i++) {
    /*******************************************
        Variable name and type declarations
    *******************************************/ 
    if (i==0) {
      int var_count=0;
      while(getline(infile, line)) {
        istringstream iss(line);				
        string type, v_name;
        if(!(iss >> type >> v_name)) { break; }
				
        if(type!="##") {
          if(type=="scalar" || type=="s") var_type[var_count]=0;
          else if(type=="vector" || type=="v") var_type[var_count]=1;
          else {
            cerr << "Incorrect variable type in variable section: ";
            cerr << type << endl;
            return 1;
          }

          var_name[var_count] = v_name;

          var_count++;
					
        }
        num_vars=var_count;
      }
    }
    /*******************************************
        Ranges for dimensions and variables
        ranges for variables
    *******************************************/ 
    else if (i==1) {
      while(getline(infile, line)) {
        istringstream iss(line);
        string name, lower, upper;
        if(!(iss >> name >> lower >> upper)) { break; }
        if(name!="##") {
          if(name=="x") {
            dim[0] = atoi(lower.c_str());
            dim[1] = atoi(upper.c_str());
          }
          else if(name=="y") {
            dim[2] = atoi(lower.c_str());
            dim[3] = atoi(upper.c_str());
          }
          else if(name=="z") {
            dim[4] = atoi(lower.c_str());
            dim[5] = atoi(upper.c_str());
          }
          else {
            bool valid=false;
            for(int j=0;j<num_vars;j++) {
              if(name==var_name[j]) {
                valid=true;
                var_range[2*j] = atoi(lower.c_str());
                var_range[(2*j)+1] = atoi(upper.c_str());             
              } 
            }
            if(valid==false) {
              cerr << "Incorrect name of variable in range section: ";
              cerr << name << endl;
              return 1;
            }
          }          
        }	
      }
    //cout << num_vars << endl;
    //for(int j=0;j<num_vars;j++) {
    //cout << var_name[j] << " " << var_range[2*j] << " " << var_range[(2*j)+1] << endl;
    //} 
    }
    /*******************************************
        Equations to solve 
        
    *******************************************/ 
    else if (i==2) {
      while(getline(infile, line)) {
        istringstream iss(line);
        string name, lower, upper;
        if(!(iss >> name >> lower >> upper)) { break; }
    }
  } 
  return 0;
}
