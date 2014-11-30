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
/*
void mgls_prepare3d(VAR *a, VAR *b=0)
{
  int i,j,k,n=100,m=100,l=100;
  //if(a) a->Create(n,m,l);   if(b) b->Create(n,m,l);
  double x,y,z;
  for(i=0;i<n;i++)  for(j=0;j<m;j++)  for(k=0;k<l;k++)
  {
    x=2*i/(n-1.)-1; y=2*j/(m-1.)-1; z=2*k/(l-1.)-1;
    a->sf[i][j][k] = -2*(x*x + y*y + z*z*z*z - z*z - 0.1);
    b->sf[i][j][k] = 1-2*tanh((x+y)*(x+y));
  }
}

void mgls_prepare2v(mglData *a, mglData *b)
{
  register long i,j,n=20,m=30,i0;
  if(a) a->Create(n,m);   if(b) b->Create(n,m);
  mreal x,y;
  for(i=0;i<n;i++)  for(j=0;j<m;j++)
  {
    x=i/(n-1.); y=j/(m-1.); i0 = i+n*j;
    if(a) a->a[i0] = 0.6*sin(2*M_PI*x)*sin(3*M_PI*y)+0.4*cos(3*M_PI*x*y);
    if(b) b->a[i0] = 0.6*cos(2*M_PI*x)*cos(3*M_PI*y)+0.4*cos(3*M_PI*x*y);
  }
}

void mgls_prepare3v(VAR* A)
{
  int i,j,k,n=100;
  //if(!ex || !ey || !ez) return;
  //ex->Create(n,n,n);  ey->Create(n,n,n);  ez->Create(n,n,n);
  double x,y,z, r1,r2;
  
  for(i=0;i<n;i++)  for(j=0;j<n;j++)  for(k=0;k<n;k++)
  {
    x=2*i/(n-1.)-1; y=2*j/(n-1.)-1; z=2*k/(n-1.)-1;
    r1 = pow(x*x+y*y+(z-0.3)*(z-0.3)+0.03,1.5);
    r2 = pow(x*x+y*y+(z+0.3)*(z+0.3)+0.03,1.5);
    A->vf[i][j][k][0]=0.2*x/r1 - 0.2*x/r2;
    A->vf[i][j][k][1]=0.2*y/r1 - 0.2*y/r2;
    A->vf[i][j][k][2]=0.2*(z-0.3)/r1 - 0.2*(z+0.3)/r2;
  }
}

int sample(mglGraph *gr)
{
vector<VAR> vars;
vars.resize(10);*/
/*****
 CALC 1
****/
/*
vars[0].set_type(1);
vars[1].set_type(1);
vars[2].set_type(1);
//vars[0].sf;
//vars[1].sf;

//sub(&vars[0],&vars[1],&vars[2]);
*/
/*****
 CALC 2
*****/
/*
vars[3].set_type(1);
vars[4].set_type(1);
vars[5].set_type(1);

//div(&vars[3],&vars[4],&vars[5]);

mgls_prepare3d(&vars[2],&vars[5]);
*/
/****
 Calc 3  
***/
/*
vars[8].set_type(2);
mgls_prepare3v(&vars[8]);


int hide[10]= {1,1,0,1,1,0,1,1,1,1};
int priority[10] = {9,8,7,6,4,3,1,0,5,2};
double colors[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
mglData c;
c.Create(DIM_SIZE,DIM_SIZE,DIM_SIZE);
normalize_scalar(&vars,hide,priority,colors,&c);

mglData ex,ey,ez;
int vect_num = 8;
ex.Create(DIM_SIZE,DIM_SIZE,DIM_SIZE);
ey.Create(DIM_SIZE,DIM_SIZE,DIM_SIZE);
ez.Create(DIM_SIZE,DIM_SIZE,DIM_SIZE);
normalize_vector(&vars,vect_num,&ex,&ey,&ez);
*/
  /*mglData a,b,d;  mgls_prepare2v(&a,&b);  d = a;
  //for(int i=0;i<a.nx*a.ny;i++)  d.a[i] = hypot(a.a[i],b.a[i]);
  //mglData c;//  mgls_prepare3d(&c);
  */
/*
  mglData v(10);  v.Fill(0,100);


  //mglData ex,ey,ez;// mgls_prepare3v(&ex,&ey,&ez);

  //gr->SubPlot(2,2,3); 
  gr->Title("Surf3 + ContF3");gr->Rotate(50,60);*/
/*  gr->Box();  gr->ContF3(v,c,"z",0);  gr->ContF3(v,c,"x");  gr->ContF3(v,c);
  gr->SetCutBox(mglPoint(-1,-1,-1), mglPoint(1,0,1.1));
  gr->ContF3(v,c,"z",c.nz-1); gr->Surf3(-0.5,c);
 */
/*
  gr->SetCutBox(mglPoint(0), mglPoint(0));
  gr->Vect3(ex,ey,ez,"fx"); gr->Vect3(ex,ey,ez,"f");gr->Vect3(ex,ey,ez,"fz");
  gr->Grid3(ex,"Wx");   gr->Grid3(ex,"W");  gr->Grid3(ex,"Wz");  
  gr->Axis("xyz"); 
  gr->Label('x',"X",1); gr->Label('y',"Y",1); gr->Label('z',"Z",1);



return 0;
}
*/

int main() {
  infile_parser fileP;

  //vector<VAR> user_vars;

  Variablelist *vars = new Variablelist();
  vector<string> *equations= new vector<string>;
  fileP.parse("new_problem.pde", vars, equations);

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
  prs.solve(vars);
  vars->print();
 // mglFLTK gr(sample,"MathGL examples");
  delete equations;
  delete vars;
 // return gr.Run();
  return 0;
}
