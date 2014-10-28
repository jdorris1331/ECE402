#include "..\include\sliderbox.h"
#include <iomanip>

void SliderBox::cb_update(Fl_Widget *w, void *data) { ((SliderBox*)data)->update(); }
void SliderBox::update()
{
	dblVal = sld->value() / dblScl;
	ss.clear();
	ss.str("");
	ss << std::fixed << std::setprecision(iPrc) << dblVal;
	sVal = ss.str();
	lblVal->label(sVal.c_str());
}

SliderBox::SliderBox(const char *name, int min, int max, int val, double scl, int prc) : Fl_Pack(0, 0, 160, 35, 0)
{
    iPrc = prc;
    dblScl = scl;
    dblVal = val/scl;
    ss.clear();
    ss.str("");
    ss << std::fixed << std::setprecision(prc) << dblVal;
    sVal = ss.str();

	this->box(FL_UP_BOX);

	lblName = new Fl_Output(6, 15, 50, 15, 0);
	lblName->box(FL_NO_BOX);
	lblName->insert(name);
	lblVal = new Fl_Output(105, 15, 50, 15, 0);
	lblVal->box(FL_NO_BOX);
	lblVal->insert(sVal.c_str());
	lblVal->align(FL_ALIGN_RIGHT);
	sld = new Fl_Hor_Nice_Slider(5, 1, 150, 15, 0);
	sld->bounds(min, max);

	sld->callback(cb_update, this);
}
