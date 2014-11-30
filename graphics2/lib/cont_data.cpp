#include "cont_data.h"

cont_data::cont_data() {
  vList = new Variablelist();
  equations = new vector<string>;

}

cont_data::~cont_data() {
  delete vList;
  delete equations;
  delete[] hide;
  delete[] priority;
  delete[] colors;
}

int cont_data::parse(string file) {
  infile_parser fileP;
  fileP.parse(file.c_str(), vList, equations);
  hide = new int[vList->var.size()];
  priority = new int[vList->var.size()];
  colors = new double[vList->var.size()];
  for(int i=0;i<vList->var.size();i++) {
    priority[i]=i;
    hide[i]=0;
    colors[i]= i+1.0;
  }
  return 1;
}

int cont_data::solve() {
  Parser prs;
  char** eqs;
  eqs = new char*[equations->size()];
  for(int i=0;i<equations->size();i++) {
    eqs[i] = new char[255];
    memcpy(eqs[i],equations->at(i).c_str(),equations->at(i).size());
    eqs[i][equations->at(i).size()] = 0;
  }

  prs.set_eqs(eqs, 3);
  prs.solve(vList);
  normalize_scalar(&(vList->var),hide,priority,colors,&x,&y,&z,&c);
  normalize_vector(&(vList->var),vect_num,&ex,&ey,&ez);
  //pass math gl data to plot
  vList->print();
}
