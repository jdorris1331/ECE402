#include "graphics.h"
#include <unistd.h>
#include <iostream>
void Graphics::axis(double x, double y, double z, double ticks){
	
	gr->Axis();
	gr->Rotate(90,90);
	gr->Box();

}


void Graphics::calculation(){
	mglData a;
	mreal x,y,z;
	gr->Rotate(50,60);
	//gr->Light(true);
	//gr->Alpha(true);
	register long i,j,k, n = 10, m = 10, l = 10, i0;
	a.Create(n,m,l);
	bool begin = true;
  for(i=0;i<n;i++)  for(j=0;j<m;j++)  for(k=0;k<l;k++)
  {
    	x=2*i/(n-1.)-1; y=2*j/(m-1.)-1; z=2*k/(l-1.)-1; i0 = i+n*(j+m*k);
     	a.a[i0] = -2*(x*x + y*y + z*z*z*z - z*z - 0.1);
  	

	if(begin == true)
	{
		sleep(1);
		begin = false;	
	}
	//axis();	
	//gr->Plot(y, x, z);
		gr->Clf();
		gr->Box();
		gr->Surf3(a);
		//gr->Dens3(a);
		//gr->ContF(a);
		//gr->Axial(a);
		//gr->Surf3C(a);
//			gr->Update();
  		update(); 
		

  }	
//	gr->Run();

	while(1);
}
