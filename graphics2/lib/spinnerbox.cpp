#include "..\include\spinnerbox.h"
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>

void SpinnerBox::setCount(int ct)
{
	count = ct;
	spnPos->maximum(ct);
}
int SpinnerBox::getPos()
{
	return spnPos->value();
}
void SpinnerBox::setPos(int p)
{
	pos = p;
	spnPos->value(p);
}

void SpinnerBox::cb_setColor(Fl_Widget *w, void *data) { ((SpinnerBox*)data)->setColor(); }
void SpinnerBox::setColor()
{
	int r, g, b, inc;
	if (txtColor->size() == 6) { inc = 0;  }
	else if (txtColor->size() == 8) { inc = 2; }
	else { return; }

	std::stringstream ss;
	ss.clear();
	ss.str("");
	ss << txtColor->value()[inc] << txtColor->value()[inc+1];
	ss >> std::hex >> r;
	ss.clear();
	ss.str("");
	ss << txtColor->value()[inc+2] << txtColor->value()[inc+3];
	ss >> std::hex >> g;
	ss.clear();
	ss.str("");
	ss << txtColor->value()[inc+4] << txtColor->value()[inc+5];
	ss >> std::hex >> b;
	updateColor(r, g, b);
}
void SpinnerBox::cb_changeColor(Fl_Widget *w, void *data) { ((SpinnerBox*)data)->changeColor(); }
void SpinnerBox::changeColor()
{
	uchar r, g, b = 0;
	if (fl_color_chooser(0, r, g, b, 2) == 1) { updateColor(r, g, b); }
}
void SpinnerBox::updateColor(int r, int g, int b)
{
	std::stringstream ssHex;
	ssHex.clear();
	ssHex.str("");
	ssHex << "0x";
	ssHex << std::hex << std::setfill('0') << std::setw(2) << r;
	ssHex << std::hex << std::setfill('0') << std::setw(2) << g;
	ssHex << std::hex << std::setfill('0') << std::setw(2) << b;
	txtColor->value(ssHex.str().c_str());
	btnColor->color(fl_rgb_color(r, g, b));
	btnColor->redraw();
}

void SpinnerBox::cb_updatePos(Fl_Widget *w, void *data) { ((SpinnerBox*)data)->updatePos(); }
void SpinnerBox::updatePos()
{
	/*std::cerr << "checkbox" << std::endl;
	this->set_changed();
	parent()->set_changed();*/
	//parent()->add(this);
	//parent()->do_callback();

	if (pos < spnPos->value()) { //demoted
		if (pos != count) { 
			for (pos; pos < spnPos->value(); pos++) {
				if (pos != 1) last->next = next;
				next->last = last;
				last = next;
				next = next->next;
				last->next = this;
				if (pos != count - 1) next->last = this;
				last->setPos(pos);	}	}	}
	else if (pos > spnPos->value()) { //promoted
		if (pos != 1) {
			for (pos; pos > spnPos->value(); pos--)	{
				if (pos != count) next->last = last;
				last->next = next;
				next = last;
				last = last->last;
				next->last = this;
				if (pos != 2) last->next = this;
				next->setPos(pos);	}	}	}
	else {} //false alarm
}
void SpinnerBox::changeWhen(uchar w)
{
	this->when(w);
}

SpinnerBox::SpinnerBox(const char *name, const char *color, int position) : Fl_Pack(0, 0, 160, 35, 0)
{
	pos = position;

	this->box(FL_UP_FRAME);

	fraSpi[0] = new Fl_Pack(0, 0, 160, 20, 0);
	fraSpi[0]->type(Fl_Pack::HORIZONTAL);
	lblName = new Fl_Output(6, 15, 80, 20, 0);
	lblName->box(FL_NO_BOX);
	lblName->insert(name);
	fraSpi[0]->end();

	fraSpi[1] = new Fl_Pack(0, 0, 160, 20, 0);
	fraSpi[1]->type(Fl_Pack::HORIZONTAL);
	txtColor = new Fl_Input(6, 1, 80, 20, 0);
	txtColor->insert(color);
	txtColor->when(FL_WHEN_ENTER_KEY);
	btnColor = new Fl_Button(88, 1, 20, 20, 0);
	setColor();
	spnPos = new Fl_Spinner(100, 1, 50, 20, 0);
	spnPos->value(position);
	spnPos->maximum(count);
	fraSpi[1]->end();

	txtColor->callback(cb_setColor, this);
	btnColor->callback(cb_changeColor, this);
	spnPos->callback(cb_updatePos, this);
	this->end();
}
