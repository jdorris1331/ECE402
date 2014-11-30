#ifndef CTRLSPINNERS_H
#define CTRLSPINNERS_H

//#include <Windows.h>
#include <vector>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include "graphics.h"
#include "spinnerbox.h"
#include "variablelist.h"
#include "variable.h"

class CtrlSpinners : public Fl_Pack
{
private:
	Fl_Pack *fraRows[2];
    Fl_Pack *fraSpinners[5];
	std::vector<SpinnerBox*> spinners;

	static void cb_updatePos(Fl_Widget *w, void *data);
	void updatePos();
	void redrawSpinners();
	
	Graphics *graph;
	Variablelist *vars;

public:
	CtrlSpinners(Graphics *myGraph, Variablelist *myVars);
};

#endif // CTRLSPINNERS_H
