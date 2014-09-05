#include <iostream>
#include <mgl2/mgl.h>

using namespace std;

int main() {
cout << "Hello world\n";

  mglGraph gr;
  int i, n=2000;
  mglData x(n),y(n),z(n),c(n);
  for(i=0;i<n;i++)
  {
    mreal t=M_PI*(mgl_rnd()-0.5), f=2*M_PI*mgl_rnd();
    x.a[i] = 0.9*cos(t)*cos(f);
    y.a[i] = 0.9*cos(t)*sin(f);
    z.a[i] = 0.6*sin(t);
    c.a[i] = cos(2*t);
  }
  gr.SubPlot(2,2,0); gr.Title("Dots sample");  gr.Rotate(50,60);
  gr.Box();  gr.Dots(x,y,z);
  gr.Alpha(true);
  gr.SubPlot(2,2,1); gr.Title("add transparency"); gr.Rotate(50,60);
  gr.Box();  gr.Dots(x,y,z,c);
  gr.SubPlot(2,2,2); gr.Title("add coloring"); gr.Rotate(50,60);
  gr.Box();  gr.Dots(x,y,z,x,c);
  gr.SubPlot(2,2,3); gr.Title("Only coloring");gr.Rotate(50,60);
  gr.Box();  gr.Tens(x,y,z,x," .");
  gr.WriteFrame("test.png");
  return 0;
}
