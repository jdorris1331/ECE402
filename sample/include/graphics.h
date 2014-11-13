#ifndef GRAPHICS_H 
#define GRAPHICS_H


#include <mgl2/fltk.h>
#include "animation.h"
#include <mgl2/mgl.h>
#include <string>

#include <time.h> 
class Graphics : public Animation 
{ 

        private:
		

	public:
		void axis(double x = 0 , double  y =  0 , double z = 0, double ticks = 1);
		void calculation();
		void calculation(int t, mglData* x, mglData* y, mglData * z, int n);
		void Run(){gr->Run();}
		void begin();
		//Graphics(){gr->zoom = true;}
		Graphics(){points = 100;}

};
#endif //CTRLGRAPH_H 
