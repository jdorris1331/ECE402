#ifndef CTRLSLIDERS_H
#define CTRLSLIDERS_H

//#include <Windows.h>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include "sliderbox.h"
#include "MglWrapper/MglWrapper.h"

class CtrlSliders : public Fl_Pack
{
private:
    MglWrapper *mgl;
    Fl_Pack *fraGraph, *fraSliders[5], *fraButtons[2];
    SliderBox *omega, *theta_BA, *theta_BP, *D_BAM, *D_BPM,
            *theta_C, *T_BA, *T_BC, *T_BAM, *T_BPM;

public:
	CtrlSliders(const char *sFile);
};

#endif // CTRLSLIDERS_H
