#include<iostream> 
#include "graphics.h"
#include "initview.h"
#include<thread>
int main()
{
	InitView init;
	init.show();
//	Graphics test;
	std::cout << "Hmm.cpp\n";
	//std::cout << "pthread: " << MGL_HAVE_PTHREAD  << std::endl;
	
	//thread thread1(test.beginAnimation);
	//test.beginAnimation();	
//	sleep(40);	
//	test.Run();
	return(Fl::run());
}
