#include "animation.h"

Animation::Animation(std::string title, int s, int p){	
	gr = new mglFLTK(title.c_str()); //Create a Window
				  //Default Title.
	gr->ToggleZoom(); //Allow toggle by mouse.
	speed = s;	//SetDefault amount of speed.
	points = 100;  //Set Default amount of points.
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

void Animation::drawVec3(mglData* ex, mglData* ey, mglData*ez)
{
	gr->Clf();
	gr->Vect3(*ex, *ey, *ez);
	gr->Update();
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
	mglData* tx = new mglData((t+1)*points);
	mglData* ty = new mglData((t+1)*points);
	mglData* tz = new mglData((t+1)*points);
	if(x && y && z){		
		//Update size of pointers.
		tx = new mglData((t+1)*points);
		ty = new mglData((t+1)*points);
		tz = new mglData((t+1)*points);
				
		//memcpy old ponter into new pointer		
		memcpy(tx->a, x->a, (t)*points*sizeof(mreal));
		memcpy(ty->a, y->a, (t)*points*sizeof(mreal));
		memcpy(tz->a, z->a, (t)*points*sizeof(mreal));
		delete x; delete y; delete z; //Delete Old memory.
		x = tx; y = ty; z = tz;
	}
	else{
		x = new mglData(points);
		y = new mglData(points);
		z = new mglData(points);
	}
}


void Animation::beginAnimation(){
	mglData *px = NULL, *py = NULL, *pz = NULL;
	mglData ex , ey , ez;
	int n = 100;
	ex.Create(n,n,n); ey.Create(n,n,n); ez.Create(n,n,n);
	int i, j,k;
	mreal  x,y,z, r1, r2;
	int i0;
  	gr->Rotate(50,60);
	for(int t = 0; t < 1; t++)
	{
		while(animation_paused == true)
		{
			std::this_thread::yield();
	//		drawVec3(&ex, &ey, &ez);	
		}
	/*			
		UpdatePointers(t, px, py, pz);
		if(t == 0){
			calculation(t, px, py, pz, 0);			
		}
		else{
			calculation(t, px, py, pz, t*points);			
		}
	*/
	//		drawDots(px, py, pz);
	
	vector<VAR> vars;
	vars.resize(10);
	for(int r = 0; r < 10; r++)
		vars[r].set_type(2);

	initVfield(vars[0], vars[1]);
	dumbNormalizer(vars[0], &ex, &ey, &ez, n);
	gr->Vect(ex, ey, ez);
	gr->Update();
	dumbNormalizer(vars[1], &ex, &ey, &ez, n);
	gr->Vect(ex, ey, ez);
	gr->Update();


	while(1)
	{
		grad(&vars[0], &vars[3]);
		grad(&vars[1], &vars[4]);
		
		vars[0] = vars[3];
		vars[1] = vars[4];


		dumbNormalizer(vars[0], &ex, &ey, &ez, n);
		gr->Vect(ex, ey, ez);
		gr->Update();
	
		dumbNormalizer(vars[1], &ex, &ey, &ez, n);
		gr->Vect(ex, ey, ez);
		gr->Update();
	}


	}
	std::cout << "Finished\n";

}
/*
void Animation::beginAnimation(){
	mglData *px = NULL, *py = NULL, *pz = NULL;
	gr->Rotate(60,50); 
	gr->Box();
	gr->SetRanges(-points, points, -points, points, -points, points);
	for(int t = 0; t < points; t++)
	{
		while(animation_paused == true)
		{
			std::this_thread::yield();
			drawDots(px,py,pz);	

		}
		UpdatePointers(t, px, py, pz);
		if(t == 0){
			calculation(t, px, py, pz, 0);			
		}
		else{
			calculation(t, px, py, pz, t*points);			
		}
			drawDots(px, py, pz);
			gr->View(50,60);
	}
}
*/
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


