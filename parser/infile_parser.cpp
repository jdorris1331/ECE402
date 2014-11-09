#include "infile_parser.h"

using namespace std;

infile_parser::infile_parser() {}
infile_parser::~infile_parser() {}

bool infile_parser::parse(string file, Variablelist *vars) {
  ifstream infile(file);
  string line;
  int max_vars = 50;		
  int num_vars;
  string var_name [50];
  int var_type [max_vars];
  int var_range_warn [max_vars*2];
  int var_range_show [max_vars*2];
  //float ****var_values;
  double var1 = 1.0;
  //cout << var1;
  //vars->add("test",0);
  //vars->set_value("test",var1);
  for(int i=0;i<max_vars*2;i++) {
	var_range_warn[i]=0;
	var_range_show[i]=0;
  }

  int dim [6];
	
  for(int i=0;i<2;i++) {
    /*******************************************
        Variable name and type declarations
    *******************************************/ 
    if (i==0) {
      int var_count=0;
      while(getline(infile, line)) {
        istringstream iss(line);				
        string type, v_name;
        if(!(iss >> type >> v_name)) { break; }
        cout << type << " " << v_name << endl;				
        if(type!="##") {
          if(type=="scalar" || type=="s") vars->add(v_name.c_str(),1);//var_type[var_count]=0;
          else if(type=="vector" || type=="v") vars->add(v_name.c_str(),2);//var_type[var_count]=1;
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
        string type;
        if(!(iss >> name >> lower >> upper)) { break; }
        if(name!="##") {
          cout << name << " " << lower << " " << upper << endl;
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
                if(iss >> type) {
                  if(type=="warn") {
                    var_range_warn[2*j] = atoi(lower.c_str());
                    var_range_warn[(2*j)+1] = atoi(upper.c_str());
                  }
                  if(type=="show") {
                    var_range_show[2*j] = atoi(lower.c_str());
                    var_range_show[(2*j)+1]  = atoi(upper.c_str());
                  }
                }
                else {
                  var_range_show[2*j] = atoi(lower.c_str());
                  var_range_show[2*j+1] = atoi(upper.c_str());             
                }
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
        Constants

    *******************************************/
    else if (i==2) {
      bool initial = true;
      while(getline(infile, line)) {
        while(line[0]==' ') line.erase(0,1);
	//check for block of input
	if(line[0]=='#' && initial==false) break; 
	else if(line[0]!='#' && initial==true) initial=false;
	
	
	cout << line << endl;
        /*while
        isstringstream iss(line);
        string name;
        float value;
       */ 
      }    
    }
    /*******************************************
        Equations to solve 
        
    *******************************************/ 
    else if (i==3) {
    /*  while(getline(infile, line)) {
        istringstream iss(line);
        string name, lower, upper;
        if(!(iss >> name >> lower >> upper)) { break; }
    }*/
    }
    /*******************************************
        Initial conditions

    *******************************************/ 
    else if (i==4) {
      getline(infile, line);
      istringstream iss(line);
      iss >> initial_file; 
      cout << initial_file << endl;      
  /*
      bool initial=true;
      string v_order[53];
      float values[53];
      int x_length=dim[1]-dim[0];
      int y_length=dim[3]-dim[2];
      int z_length=dim[5]-dim[4];
      var_values = new double***[num_vars];
      for(int j=0;j<num_vars;j++) {
        var_values = new doulbe**[x_length];
        for(int k=0;k<x_length;k++) {
          var_values = new double*[y_length];
          for(int l=0;l<y_length;l++) {
            var_values = new double*[z_length];
          }
        }
      }
      while(getline(infile, line)) {
        istringstream iss(line);
        if(initial) {
          int index=0;
          while(iss >> v_order[index]) index++;
          inital=false;
        }
        else{
          for(int j=0;j<index;j++) iss >> values[j];
          
          if(v_order[
        
    }
}}*/
   }
 } 
 return 0;
}

bool infile_parser::get_initial(Variablelist *vars) {
  /*string line;

  ifstream infile(initial_file); 
  getline(infile, line);
   
  while(getline(infile, line)) {
    istringstream iss(line);
       
  }*/
  return false;
}
