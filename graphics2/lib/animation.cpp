#include "animation.h"

Animation::Animation(std::string title, int s, int p){	
	gr = new mglFLTK(title.c_str()); //Create a Window
				  //Default Title.
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


void Animation::beginAnimation(){

	std::thread calc_thread(&Animation::calculation, this);
	std::cout << "Begin Calculations\n";
	calc_thread.detach();
	std::cout << "BeginAnimation Returning\n";
}

void Animation::toggleAnimation(){
	std::cout << "called toggle animan\n";
	if(animation_begin == false)
	{
		animation_paused = false;
		animation_begin = true;
		beginAnimation();
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




