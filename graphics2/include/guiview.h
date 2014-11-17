#ifndef GUIVIEW_H
#define GUIVIEW_H

//#include <Windows.h>
#include <FL/Fl_Window.H>
#include <FL/Fl_Pack.H>
//#include <FL/Fl_Scroll.H>
#include "ctrlmenubar.h"
#include "graphics.h"

class GUIView : public Fl_Window
{
private:
	CtrlMenuBar *mb;
	Fl_Pack *fraFrame, *fraMain[3];
<<<<<<< HEAD
	//Fl_Scroll *scrMain;
=======
>>>>>>> 7e6d0e8dfba5947e7947ee29d3121dcc32be7391

	Graphics *graph;
	static void cb_launchGraph(Fl_Widget *w, void *data);
	void launchGraph();

public:
    GUIView(const char *sFile);
};

#endif // GUIVIEW_H
