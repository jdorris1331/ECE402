#ifndef CTRLSPINNERS_H
#define CTRLSPINNERS_H

#include <FL/Fl_Pack.H>
#include <FL/Fl_Scroll.H>
#include "spinnerbox.h"
#include <vector>

class CtrlSpinners : public Fl_Pack
{
private:
    Fl_Pack *fraSpinners[5];
	std::vector<SpinnerBox*> spinners;

	static void cb_updatePos(Fl_Widget *w, void *data);
	void updatePos();
	void redrawSpinners();

public:
	CtrlSpinners(const char *sFile);
};

#endif // CTRLSPINNERS_H
