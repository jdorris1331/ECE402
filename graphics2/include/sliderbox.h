#ifndef SLIDERBOX_H
#define SLIDERBOX_H

//#include <Windows.h>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Hor_Nice_Slider.H>
#include <sstream>
#include "model.h"

class SliderBox : public Fl_Pack
{
private:
	double dblScl, dblVal;
	int iPrc;
	std::string sVal;
	std::stringstream ss;
	Fl_Pack *fraSli[2];

	static void cb_update(Fl_Widget *w, void *data);
	void update();

public:
    SliderBox(const char *name, int min, int max, int val, double scl, int prc, int w = 160, int h = 35);
    Fl_Output *lblName, *lblVal;
    Fl_Slider *sld;
};

#endif // SLIDERBOX_H
