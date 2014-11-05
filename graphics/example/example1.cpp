#include<iostream>
#include "graphics.h"
#include<thread>
int main()
{
	Graphics test;
	std::cout << "Hello.cpp\n";
	//std::cout << "pthread: " << MGL_HAVE_PTHREAD  << std::endl;
	
//	test.beginAnimation();
//	sleep(100);	
	test.Run();
}
