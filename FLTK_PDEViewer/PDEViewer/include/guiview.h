#ifndef GUIVIEW_H
#define GUIVIEW_H

#include <Windows.h>
#include <FL/Fl_Window.H>
#include <FL/Fl_Pack.H>
//#include <FL/Fl_Scroll.H>
#include "ctrlmenubar.h"

class GUIView : public Fl_Window
{
private:
	CtrlMenuBar *mb;
	Fl_Pack *fraFrame, *fraGraph, *fraSliders;
	Fl_Group *fraMain[3];
	//Fl_Scroll *scrMain;

public:
    GUIView(const char *sFile);
};

#endif // GUIVIEW_H
