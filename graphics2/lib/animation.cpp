#include "animation.h"

Animation::Animation(std::string title, int s, int p){	
	gr = new mglFLTK(title.c_str()); //Create a Window
				  //Default Title.
	speed = s;	//SetDefault amount of speed.
	points = p;  //Set Default amount of points.
	animation_paused = false;
	animation_begin = false;
	gr->ToggleZoom(); //Allow toggle by mouse.
	gr->ToggleRotate(); //Allow for mouse rotation.
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


void Animation::beginAnimation(){

	mglData x(50), y(50), z(50);
	gr->Rotate(50,60);
	//`gr->Box();
	gr->SetRanges(-90, 90, -90, 90, -90, 90);
	for(int t = 0; t < 1000; t++)
	{

		while(animation_paused == true)
		{
			std::this_thread::yield();
			gr->Update();
		}
	//	std::thread calc_thread(&Animation::calculation,  this, t, &x, &y, &z, 200);
		calculation(t, &x, &y, &z, 50);			
		//calc_thread.join();
		gr->Dots(x,y,z);
		gr->Update();	
	}
	std::cout << "Begin Calculations\n";
	//calc_thread.detach();
	std::cout << "BeginAnimation Returning\n";
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


