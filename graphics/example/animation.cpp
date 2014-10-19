#include "animation.h"

Animation::Animation(std::string title, int s, int p){	
	gr = new mglFLTK(title.c_str()); //Create a Window
				  //Default Title.
	speed = s;	//SetDefault amount of speed.
	points = p;  //Set Default amount of points.
	animation_paused = false;
	

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
}


void Animation::pauseAnimation(){
	animation_paused = true;
}


void Animation::update(){

	if(!animation_paused){
		if(gr)
			gr->Update();
	}
}






