#include <iostream>
#include <mgl2/qt.h> 
using namespace std;

void mgls_prepare3d(mglData *a, mglData *b=0)
{
  register long i,j,k,n=61,m=50,l=40,i0;
  if(a) a->Create(n,m,l);   if(b) b->Create(n,m,l);
  mreal x,y,z;
  for(i=0;i<n;i++)  for(j=0;j<m;j++)  for(k=0;k<l;k++)
  {
    x=2*i/(n-1.)-1; y=2*j/(m-1.)-1; z=2*k/(l-1.)-1; i0 = i+n*(j+m*k);
    if(a) a->a[i0] = -2*(x*x + y*y + z*z*z*z - z*z - 0.1);
    if(b) b->a[i0] = 1-2*tanh((x+y)*(x+y));
  }
}

int sample(mglGraph *gr)
{
  mglData c;  mgls_prepare3d(&c);
  gr->Title("Dens3 sample");  gr->Rotate(50,60);
  gr->Alpha(true);  gr->SetAlphaDef(0.7);
  gr->SetOrigin(0,0,0); gr->Axis("_xyz"); gr->Box();
  gr->Dens3(c,"x"); gr->Dens3(c); gr->Dens3(c,"z");

  int i, n=10000;
  mglData x(n),y(n),z(n),d(n);
  for(i=0;i<n;i++)
  {
    mreal t=M_PI*(mgl_rnd()-0.5), f=2*M_PI*mgl_rnd();
    x.a[i] = 0.9*cos(t)*cos(f);
    y.a[i] = 0.9*cos(t)*sin(f);
    z.a[i] = 0.6*sin(t);
    d.a[i] = cos(2*t);
  }
  gr->Title("Dots sample"); 
  gr->Rotate(50,60);
  gr->Box();  gr->Dots(x,y,z);

  return 0;

}
/*
int sample2(mglGraph *gr) {
  int i, n=10000;
  mglData x(n),y(n),z(n),c(n);
  for(i=0;i<n;i++)
  {
    mreal t=M_PI*(mgl_rnd()-0.5), f=2*M_PI*mgl_rnd();
    x.a[i] = 0.9*cos(t)*cos(f);
    y.a[i] = 0.9*cos(t)*sin(f);
    z.a[i] = 0.6*sin(t);
    c.a[i] = cos(2*t);
  }
  gr->Title("Dots sample");  gr->Rotate(50,60);
  gr->Box();  gr->Dots(x,y,z);
  return 0;
}
*/

int main() {
  mglQT gr(sample,"MathGL examples");
  return gr.Run();
return 0;
}
