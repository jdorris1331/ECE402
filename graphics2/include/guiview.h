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
	//Fl_Scroll *scrMain;

	Graphics *graph;
	static void cb_launchGraph(Fl_Widget *w, void *data);
	void launchGraph();

public:
    GUIView(const char *sFile);
};

#endif // GUIVIEW_H
