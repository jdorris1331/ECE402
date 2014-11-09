#ifndef SPINNERBOX_H
#define SPINNERBOX_H

#include <FL/Fl_Pack.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/Fl_Spinner.H>
#include "model.h"

class SpinnerBox : public Fl_Pack
{
private:
	Fl_Pack *fraSpi[2];
	Fl_Output *lblName;
	Fl_Input *txtColor;
	Fl_Button *btnColor;
	Fl_Spinner *spnPos;
	int count = 10;

	int pos;

	static void cb_setColor(Fl_Widget *w, void *data);
	void setColor();
	static void cb_changeColor(Fl_Widget *w, void *data);
	void changeColor();
	void updateColor(int r, int g, int b);
	static void cb_updatePos(Fl_Widget *w, void *data);
	void updatePos();

public:
    SpinnerBox(const char *name, const char *color, int position);
	void setCount(int ct);
	int getPos();
	void setPos(int p);
	void changeWhen(uchar w);
	SpinnerBox *last, *next;
};

#endif // SPINNERBOX_H
