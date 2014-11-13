#include "infile_parser.h"

using namespace std;

infile_parser::infile_parser() {}
infile_parser::~infile_parser() {}

bool infile_parser::parse(string file, Variablelist *vars, vector<string>* eqs) {
  ifstream infile(file);
  string line;
  int max_vars = 50;
  double dim_points = 100.0;		
  
  int dim [6];
	

  for(int i=0;i<5;i++) {
    /*******************************************
        Variable name and type declarations
    *******************************************/ 
    if (i==0) {
      cout << "*****VARIABLES*****\n";
      int var_count=0;
      int initial=true;
   
      //read in lines
      while(getline(infile, line)) {
  
        //skip extra space
        if((line.size()<2)) continue;
        while(line[0]==' ') line.erase(0,1);
        if((line.size()<2)) continue;

        //check for new section or comments
        if((line.at(0)=='#' && line.at(1)=='#') && initial==true) {continue;}
        if(line.at(0)=='#' && line.at(1)=='#') break;
        if(line.at(0)=='#') {continue;}
        
        //read in variables and types
        //else {
          //turn into stringstream
          istringstream iss(line);				
          string type, v_name;
          int value;
          //get type and name
          if(!(iss >> type >> v_name >> value)) { break; }
          cout << type << " " << v_name << endl;				
        
          //add to 
          if(type=="scalar" || type=="s") {
            vars->add(v_name.c_str(),1);
            vars->set_scalar_field(v_name.c_str(),value);
          }
          else if(type=="vector" || type=="v") {
            vars->add(v_name.c_str(),2);
            vars->set_vector_field(v_name.c_str(),value);
          }
          else {
            cerr << "Incorrect variable type in variable section: ";
            cerr << type << endl;
            return 1;
          }
          initial=false;
          //var_name[var_count] = v_name;

          //var_count++;
          //}
					
        }
        //num_vars=var_count;
    }
    /*******************************************
        Constants

    *******************************************/
    else if (i==1) {
      cout << "*****CONSTANTS*****\n";
      bool initial = true;
      while(getline(infile, line)) {

        //skip extra space
        if((line.size()<2)) continue;
        while(line[0]==' ') line.erase(0,1);
        if((line.size()<2)) continue;

        //check for new section or comments
        if((line.at(0)=='#' && line.at(1)=='#') && initial==true) {continue;}
        if(line.at(0)=='#' && line.at(1)=='#') break;
        if(line.at(0)=='#') {continue;}

        //read in variables and types
          istringstream iss(line);
          string c_name, val;
          //get type and name
          if(!(iss >> c_name >> val)) { break; }
          cout << c_name << " " << val << endl;
          vars->add(c_name.c_str(),0);
          vars->set_value(c_name.c_str(),atof(val.c_str()));
          initial=false;
      }
    }
    /*******************************************
        Ranges for dimensions and variables
        ranges for variables
    *******************************************/ 
    else if (i==2) {
      cout << "****RANGES******\n";
      bool initial=true;
      while(getline(infile, line)) {
        //skip extra space
        if((line.size()<2)) continue;
        while(line[0]==' ') line.erase(0,1);
        if((line.size()<2)) continue;

        //check for new section or comments
        if((line.at(0)=='#' && line.at(1)=='#') && initial==true) {continue;}
        if(line.at(0)=='#' && line.at(1)=='#') break;
        if(line.at(0)=='#') {continue;}

        //read in variables and types
        else {
          istringstream iss(line);
          string name, lower, upper;
          string type;
          initial=false;
          if(!(iss >> name >> lower >> upper >> type)) { break; }
            //cout << name << " " << lower << " " << upper << endl;
          if(name=="x" || name=="X") {
            dim[0] = atof(lower.c_str());
            dim[1] = atof(upper.c_str());

            vars->add("X",1); 
            double tempx=dim[0];
            double dx=(dim[1]-dim[0])/dim_points;
            //cout << "dx=" << dx << endl;
            for(int j=0;j<dim_points;j++) {
              for(int k=0;k<dim_points;k++) {
                for(int l=0;l<dim_points;l++) {    
                  vars->set_scalar_single("X",j,k,l,tempx);
                }
              }
              tempx+=dx;
            }
              //vars->set_scalar_field_single("X",tempx);
            }
            //  dim[0] = atoi(lower.c_str());
            //  dim[1] = atoi(upper.c_str());
            else if(name=="y" || name=="Y") {
              dim[2] = atof(lower.c_str());
              dim[3] = atof(upper.c_str());

              vars->add("Y",1);
              double tempy=dim[2];
              double dy=(dim[3]-dim[2])/dim_points;
              for(int j=0;j<dim_points;j++) {
                for(int k=0;k<dim_points;k++) {
                  for(int l=0;l<dim_points;l++) {
                    vars->set_scalar_single("Y",k,j,l,tempy);
                  }
                }
                tempy+=dy;
              }
            }
            else if(name=="z" || name=="Z") {
              dim[4] = atof(lower.c_str());
              dim[5] = atof(upper.c_str());
      
              vars->add("Z",1);
              double tempz=dim[4];
              double dz=(dim[5]-dim[4])/dim_points;
              for(int j=0;j<dim_points;j++) {
                for(int k=0;k<dim_points;k++) {
                  for(int l=0;l<dim_points;l++) {
                    vars->set_scalar_single("Z",k,l,j,tempz);
                  }
                }
                tempz+=dz;
              }  
            }
            else {
              bool valid=true;
              if(type=="show") { 
	        if(!(vars->set_range(name.c_str(),0,atof(lower.c_str()),atof(upper.c_str())))) 
                  valid=false;
              }
              else if(type=="warn") {
                if(!(vars->set_range(name.c_str(),1,atof(lower.c_str()),atof(upper.c_str()))))
                  valid=false;
              }
              else valid=false;
 

              if(valid==false) {
                cerr << "Incorrect name of variable in range section: ";
                cerr << name << endl;
                return 1;
              }
            }          
          }	
        }
      }
   
    /*******************************************
        Constants

    *******************************************/
    /*else if (i==2) {
      cout << "*****CONSTANTS*****\n";
      bool initial = true;
      while(getline(infile, line)) {
       
        //skip extra space 
        if((line.size()<2)) continue;
        while(line[0]==' ') line.erase(0,1);
        if((line.size()<2)) continue;

        //check for new section or comments
        if((line.at(0)=='#' && line.at(1)=='#') && initial==true) {continue;}
        if(line.at(0)=='#' && line.at(1)=='#') break;
        if(line.at(0)=='#') {continue;}

        //read in variables and types
       // else {
          istringstream iss(line);
          string c_name, val;
          //get type and name
          if(!(iss >> c_name >> val)) { break; }
          cout << c_name << " " << val << endl; 
          vars->add(c_name.c_str(),0);
          vars->set_value(c_name.c_str(),atof(val.c_str()));
          initial=false;
       // }	
      }    
    }*/
    /*******************************************
        Equations to solve 
        
    *******************************************/ 
    else if (i==3) {
      //int eqs_num=0;
      bool initial=true;
      cout << "******EQUATIONS******\n";
      while(getline(infile, line)) {
        
        //skip extra space
        if((line.size()<2)) continue;
        while(line[0]==' ') line.erase(0,1);
        if((line.size()<2)) continue;

        //check for new section or comments
        if((line.at(0)=='#' && line.at(1)=='#') && initial==true) {continue;}
        if(line.at(0)=='#' && line.at(1)=='#') break;
        if(line.at(0)=='#') {continue;}
       
        //get equations 
        eqs->push_back(line);
        initial=false;
      }
    }
    /*******************************************
        Initial conditions

    *******************************************/ 
    else if (i==4) {
      cout << "*****INITIAL****\n";
      int initial=true;
      int current=0;
      while(getline(infile, line)) {

        //skip extra space      
        if((line.size()<2)) continue;
        while(line[0]==' ') line.erase(0,1);
        if((line.size()<2)) continue;

        //check for new section or comments
        if((line.at(0)=='#' && line.at(1)=='#') && initial==true) {continue;}
        if(line.at(0)=='#' && line.at(1)=='#') break;
        if(line.at(0)=='#') {continue;}

            initial_files.push_back(line);
            cout << initial_files[current] << endl;
            current++;
      }
    }
  }
get_initial(vars);
return 0;
}

bool infile_parser::get_initial(Variablelist * vars) {
  string line;
  string var_name;
  for(int i=0;i<initial_files.size();i++) {
    vector<string> order;
    vector<int> type;
    cout << "OPENING " << initial_files[i] << endl;
    ifstream infile(initial_files[i]); 
    getline(infile, line);
    istringstream iss(line);
    iss >> var_name >> var_name >> var_name;
    while(iss>>var_name) {
      //cout << var_name << endl;
      if(vars->exist(var_name.c_str())) {
        order.push_back(var_name);
        type.push_back(0);
      }
      else if(vars->exist(var_name.substr(0,var_name.size()-2).c_str())) {
        //cout << var_name.substr(0,var_name.size()-2)<< endl;
        order.push_back(var_name.substr(0,var_name.size()-2));
        if(var_name.substr(var_name.size()-1,1)=="x") type.push_back(1);
        else if(var_name.substr(var_name.size()-1,1)=="y") type.push_back(2);
        else if(var_name.substr(var_name.size()-1,1)=="z") type.push_back(3);
      }
      else {
        cerr << "Variable is incorrect\n";
        return false;
      }
      //cout << var_name << endl;
    }

    while(getline(infile, line)) {
      istringstream iss(line);
      int x,y,z;
      double value;
      //need to change to actual xyz coordinates
      iss >> x >> y >> z;
      //cout << x << " " << y << " " << z << " ";
      int current=0;
      while(iss >> value) {
        //cout << value << " ";
        string temp_name=order[current];
        int vec_type = type[current]-1;
        if(type[current]==0) vars->set_scalar_single(temp_name.c_str(),x,y,z,value);
        else vars->set_vector_single(temp_name.c_str(),x,y,z,vec_type,value);
        current++;
      }
      //cout << endl;
    }
  }
  return false;
}
