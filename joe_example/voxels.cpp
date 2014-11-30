#include <iostream>
#include <cstring>
#include <mgl2/fltk.h>
#include "variable.h"
#include "normalizer.h"
#include "constants.h"
#include "expression_parser.h"
#include "infile_parser.h"
#include "variablelist.h"

using namespace std;

int sample(mglGraph *gr)
{
  infile_parser fileP;


  Variablelist *vars = new Variablelist();
  vector<string> *equations= new vector<string>;
  fileP.parse("new_problem.pde", vars, equations);
  int hide[vars->var.size()];
  int priority[vars->var.size()];
  double colors[vars->var.size()];
  mglData x,y,z,c;
  //c.Create(DIM_SIZE,DIM_SIZE,DIM_SIZE);

  mglData ex,ey,ez;
  int vect_num = 2;
  ex.Create(DIM_SIZE,DIM_SIZE,DIM_SIZE);
  ey.Create(DIM_SIZE,DIM_SIZE,DIM_SIZE);
  ez.Create(DIM_SIZE,DIM_SIZE,DIM_SIZE);
  //normalize_vector(&vars,vect_num,&ex,&ey,&ez);

  
  for(int i=0;i<vars->var.size();i++) {
    hide[i]=0;
    priority[i]=i;
    colors[i] = 20*(i+1);
  }

  //to get sliders look at each type
  //  if 0 then set at val and have vary from show_min to show_max
  //  else then slider at show_min*.1 to show_min*10 start at show_min
  //   and slider at show_max*.1 to show_max*10 at show_max

  Parser prs;  

  char** eqs;
  eqs = new char*[equations->size()];
  for(int i=0;i<equations->size();i++) {
    eqs[i] = new char[255];
    memcpy(eqs[i],equations->at(i).c_str(),equations->at(i).size());
    eqs[i][equations->at(i).size()] = 0;
    cout << eqs[i] << "\n";
  }

  prs.set_eqs(eqs, 3);
  for(int i=0;i<1;i++) { 
    //prs.solve(vars);
    normalize_scalar(&(vars->var),hide,priority,colors,&x,&y,&z,&c);
    normalize_vector(&(vars->var),vect_num,&ex,&ey,&ez);
    //pass math gl data to plot
    //vars->print();
  }

  mglData v(10);  v.Fill(0,100);

  gr->Title("Surf3 + ContF3");gr->Rotate(50,60);
  gr->Alpha(true); gr->SetAlphaDef(.7);
  gr->SetOrigin(0,0,0); gr->Axis("_xyz");
  gr->Box(); gr->Dots(x,y,z,c);
  //gr->Box();  gr->Dens3(c,"x"); gr->Dens3(c); gr->Dens3(c,"z");

  /*gr->ContF3(v,c,"z",0);  gr->ContF3(v,c,"x");  gr->ContF3(v,c);
  gr->SetCutBox(mglPoint(-1,-1,-1), mglPoint(1,0,1.1));
  gr->ContF3(v,c,"z",c.nz-1); gr->Surf3(-0.5,c);


  gr->SetCutBox(mglPoint(0), mglPoint(0));*/
/*  gr->Title("Vect3 sample");  gr->SetOrigin(0,0,0);
  gr->Rotate(50,60);
  gr->Box();
  gr->Vect3(ex,ey,ez,"fx"); gr->Vect3(ex,ey,ez,"f");gr->Vect3(ex,ey,ez,"fz");
  //gr->Grid3(ex,"Wx");   gr->Grid3(ex,"W");  gr->Grid3(ex,"Wz");
  gr->Axis("xyz");
  gr->Label('x',"X",1); gr->Label('y',"Y",1); gr->Label('z',"Z",1);*/

  delete equations;
  delete vars;
  return 0;
}

int main() {
  mglFLTK gr(sample,"MathGL examples");
  return gr.Run();
  return 0;
}
