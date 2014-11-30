#ifndef CTRLSLIDERS_H
#define CTRLSLIDERS_H

//#include <Windows.h>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include "graphics.h"
#include "sliderbox.h"
#include "MglWrapper/MglWrapper.h"
#include "variablelist.h"
#include "variable.h"

class CtrlSliders : public Fl_Pack
{
private:
    MglWrapper *mgl;
    Fl_Pack *fraGraph, *fraSliders[5], *fraButtons[2];
    SliderBox *omega, *theta_BA, *theta_BP, *D_BAM, *D_BPM,
            *theta_C, *T_BA, *T_BC, *T_BAM, *T_BPM;
			
	Graphics *graph;
	Variablelist *vars;

public:
	CtrlSliders(Graphics *myGraph, Variablelist *myVars);
};

#endif // CTRLSLIDERS_H
