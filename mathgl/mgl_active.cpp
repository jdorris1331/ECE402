#include <iostream>
#include <mgl2/qt.h>

using namespace std;

int sample(mglGraph *gr)
{
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
//-----------------------------------------------------
int main(int argc,char **argv)
{
  mglQT gr(sample,"MathGL examples");
  return gr.Run();
}
