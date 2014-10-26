#include "..\include\sliderbox.h"
#include <iomanip>

SliderBox::SliderBox(std::string name, int min, int max, int val,
                     double scl, int prc) : Fl_Pack(0, 0, 160, 35, 0)
{
    iPrc = prc;
    dblScl = scl;
    dblVal = val/scl;
    ss.clear();
    ss.str("");
    ss << std::fixed << std::setprecision(prc) << dblVal;
    sVal = ss.str();

	this->box(FL_UP_BOX);

	lblName = new Fl_Text_Display(6, 15, 50, 15, name);
	lblVal = new Fl_Text_Display(105, 15, 50, 15, sVal);
	lblVal->align(FL_ALIGN_RIGHT);
	sld = new Fl_Hor_Nice_Slider(5, 1, 150, 15, 0);
	sld->bounds(min, max);
	sld->scrollvalue(val, )
    sld->setValue(val);

    connect(sld, SIGNAL(valueChanged(int)), this, SLOT(update(int)));
}

void SliderBox::update(int val)
{
    dblVal = val/dblScl;
    ss.clear();
    ss.str("");
    ss << std::fixed << std::setprecision(iPrc) << dblVal;
    sVal = ss.str();
    lblVal->setText(QString::fromStdString(sVal));
}
