#ifndef SLIDERBOX_H
#define SLIDERBOX_H

#include <string>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Text_Display.H>
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

public:
    SliderBox(std::string name, int min, int max, int val,
              double scl, int prc);
    Fl_Text_Display *lblName, *lblVal;
    Fl_Slider *sld;

//signals:
    void moved(int pos);

//public slots:
    void update(int val);
};

#endif // SLIDERBOX_H
