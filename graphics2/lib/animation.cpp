#include "animation.h"

Animation::Animation(std::string title, int s, int p){	
	gr = new mglFLTK(title.c_str()); //Create a Window
				  //Default Title.
	gr->ToggleZoom(); //Allow toggle by mouse.
	speed = s;	//SetDefault amount of speed.
	points = p;  //Set Default amount of points.
	animation_paused = false;
	animation_begin = false;
}



void Animation::RunThread()
{
	std::thread graphThread(&Animation::Run, this);
	graphThread.detach();

}



void Animation::Run(){
	if(gr){
		gr->Run();
	}
}

Animation::~Animation(){
	if(gr){
		free(gr);
	}
}



void Animation::drawDots(mglData*  x, mglData *  y ,mglData *  z )
{

	gr->Clf(); //Clear the old graph.
	gr->Dots(*x, *y, *z);	
	gr->Update();
}


void Animation::UpdatePointers(int t, mglData* & x, mglData* & y, mglData* & z)
{
	//Update size fo points
	mglData* tx = new mglData((t+1)*100);
	mglData* ty = new mglData((t+1)*100);
	mglData* tz = new mglData((t+1)*100);
	if(x && y && z){		
		//Update size of pointers.
		tx = new mglData((t+1)*100);
		ty = new mglData((t+1)*100);
		tz = new mglData((t+1)*100);
				
		//memcpy old ponter into new pointer		
		memcpy(tx->a, x->a, (t)*100*sizeof(mreal));
		memcpy(ty->a, y->a, (t)*100*sizeof(mreal));
		memcpy(tz->a, z->a, (t)*100*sizeof(mreal));
		delete x; delete y; delete z; //Delete Old memory.
		x = tx; y = ty; z = tz;
	}
	else{
		x = new mglData(100);
		y = new mglData(100);
		z = new mglData(100);
	}


}


void Animation::beginAnimation(){
	mglData *px = NULL, *py = NULL, *pz = NULL;
	gr->Rotate(60,50); 
	gr->Box();
	gr->SetRanges(-100, 100, -100, 100, -100, 100);
	for(int t = 0; t < 100; t++)
	{
		while(animation_paused == true)
		{
			std::this_thread::yield();
			gr->Update();
		}
		UpdatePointers(t, px, py, pz);
		if(t == 0){
			calculation(t, px, py, pz, 0);			
		}
		else{
			calculation(t, px, py, pz, t*100);			
		}
			drawDots(px, py, pz);
			gr->View(50,60);
	}
}

void Animation::toggleAnimation(){
	std::cout << "called toggle animan\n";
	if(animation_begin == false)
	{
		animation_paused = false;
		animation_begin = true;
		std::thread animation (&Animation::beginAnimation, this);
		animation.detach();
		gr->Run();
	}
	else
		animation_paused = !animation_paused;
	std::cout << "Calling\n" << std::endl;
}


void Animation::update(){
	if(!animation_paused){
		if(gr)
		{
			gr->Update();
			std::cerr <<"updating graph\n";	
		}
		else
			std::cerr <<"Graph not read\n";
	}
}


