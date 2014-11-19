#include<iostream> 
#include "graphics.h"
#include "initview.h"
#include <vector>
#include "variable.h"

#include<thread>

using namespace std;
int main()
{
	


	InitView init;
	init.show();
//	Graphics test;
	std::cout << "Hmm.cpp\n";
	//std::cout << "pthread: " << MGL_HAVE_PTHREAD  << std::endl;
	std:: cout << "main thread: " << std::this_thread::get_id();	
	//thread thread1(test.beginAnimation);
	//test.beginAnimation();	
//	sleep(40);	
//	test.Run();
	return(Fl::run());
}
