#include <iostream>
#include <mgl2/qt.h>

using namespace std;

void mgls_prepare3d(mglData *a, mglData *b=0)
{
  register long i,j,k,n=100,m=100,l=100,i0;
  if(a) a->Create(n,m,l);   if(b) b->Create(n,m,l);
  mreal x,y,z;
  for(i=0;i<n;i++)  for(j=0;j<m;j++)  for(k=0;k<l;k++)
  {
    x=2*i/(n-1.)-1; y=2*j/(m-1.)-1; z=2*k/(l-1.)-1; i0 = i+n*(j+m*k);
    if(a) a->a[i0] = -2*(x*x + y*y + z*z*z*z - z*z - 0.1);
    if(b) b->a[i0] = 1-2*tanh((x+y)*(x+y));
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

void mgls_prepare3v(mglData *ex, mglData *ey, mglData *ez)
{
  register long i,j,k,n=10,i0;
  if(!ex || !ey || !ez) return;
  ex->Create(n,n,n);  ey->Create(n,n,n);  ez->Create(n,n,n);
  mreal x,y,z, r1,r2;
  for(i=0;i<n;i++)  for(j=0;j<n;j++)  for(k=0;k<n;k++)
  {
    x=2*i/(n-1.)-1; y=2*j/(n-1.)-1; z=2*k/(n-1.)-1; i0 = i+n*(j+k*n);
    r1 = pow(x*x+y*y+(z-0.3)*(z-0.3)+0.03,1.5);
    r2 = pow(x*x+y*y+(z+0.3)*(z+0.3)+0.03,1.5);
    ex->a[i0]=0.2*x/r1 - 0.2*x/r2;
    ey->a[i0]=0.2*y/r1 - 0.2*y/r2;
    ez->a[i0]=0.2*(z-0.3)/r1 - 0.2*(z+0.3)/r2;
  }
}

int sample(mglGraph *gr)
{
  mglData a,b,d;  mgls_prepare2v(&a,&b);  d = a;
  for(int i=0;i<a.nx*a.ny;i++)  d.a[i] = hypot(a.a[i],b.a[i]);
  mglData c;  mgls_prepare3d(&c);
  mglData v(10);  v.Fill(-0.5,1);

  mglData ex,ey,ez; mgls_prepare3v(&ex,&ey,&ez);

  //gr->SubPlot(2,2,3); 
  gr->Title("Surf3 + ContF3");gr->Rotate(50,60);
  gr->Box();  gr->ContF3(v,c,"z",0);  gr->ContF3(v,c,"x");  gr->ContF3(v,c);
  gr->SetCutBox(mglPoint(-1,-1,-1), mglPoint(1,0,1.1));
  gr->ContF3(v,c,"z",c.nz-1); gr->Surf3(-0.5,c);
 
  gr->SetCutBox(mglPoint(0), mglPoint(0));
  gr->Vect3(ex,ey,ez,"fx"); gr->Vect3(ex,ey,ez,"f");gr->Vect3(ex,ey,ez,"fz");
  gr->Grid3(ex,"Wx");   gr->Grid3(ex,"W");  gr->Grid3(ex,"Wz");  
  gr->Axis("xyz"); 
  gr->Label('x',"X",1); gr->Label('y',"Y",1); gr->Label('z',"Z",1);
return 0;
}


int main() {
  mglQT gr(sample,"MathGL examples");
  return gr.Run();
  return 0;
}
