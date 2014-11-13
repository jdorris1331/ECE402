#include "spinnerbox.h"
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

void SpinnerBox::cb_vectorExclusive(Fl_Widget *w, void *data) { ((SpinnerBox*)data)->vectorExclusive(); }
void SpinnerBox::vectorExclusive()
{
	SpinnerBox *cr;
	for (cr = this->next; cr != NULL; cr = cr->next) { cr->toggleVector(); }
	for (cr = this->last; cr != NULL; cr = cr->last) { cr->toggleVector(); }
}
void SpinnerBox::toggleVector()
{
	if (vartype == 1) {
		if (radVisible->value() == 1) {
			radVisible->value(0); } }
}

SpinnerBox::SpinnerBox(const char *name, const char *color, int position, int vt) : Fl_Pack(0, 0, 260, 75, 0)
{
	pos = position;
	vartype = vt;

	//this->box(FL_UP_FRAME);
	this->spacing(2);

	fraBox[0] = new Fl_Pack(0, 0, 160, 48, 0);
	fraBox[0]->type(Fl_Pack::HORIZONTAL);
	fraBox[1] = new Fl_Pack(0, 0, 155, 20, 0);
	fraBox[1]->box(FL_UP_FRAME);
	fraSpi[0] = new Fl_Pack(0, 0, 160, 20, 0);
	fraSpi[0]->type(Fl_Pack::HORIZONTAL);
	lblName = new Fl_Output(6, 15, 95, 20, 0);
	lblName->box(FL_NO_BOX);
	lblName->insert(name);
	if (vartype == 1)
	{
		radVisible = new Fl_Radio_Round_Button(0, 15, 60, 20, "Show");
	}
	else
	{
		chkVisible = new Fl_Check_Button(0, 15, 60, 20, "Show");
		chkVisible->value(1);
	}
	fraSpi[0]->end();

	fraSpi[1] = new Fl_Pack(0, 0, 40, 25, 0);
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
	fraBox[1]->end();

	fraBox[2] = new Fl_Pack(0, 0, 105, 25, 0);
	fraBox[2]->box(FL_UP_FRAME);
	lblCrd = new Fl_Output(6, 15, 95, 20, 0);
	lblCrd->box(FL_NO_BOX);
	lblCrd->insert("Coordinates");
	lblXyz = new Fl_Output(6, 15, 95, 25, 0);
	lblXyz->value("\(x, y, z\)");
	fraBox[2]->end();
	fraBox[0]->end();

	fraSpi[2] = new Fl_Pack(0, 0, 160, 25, 0);
	fraSpi[2]->type(Fl_Pack::HORIZONTAL);
	sldMin = new SliderBox("Min", 1, 20, 10, 10.0, 1, 130, 20);
	sldMax = new SliderBox("Max", 1, 20, 10, 10.0, 1, 130, 20);
	fraSpi[2]->end();

	txtColor->callback(cb_setColor, this);
	btnColor->callback(cb_changeColor, this);
	spnPos->callback(cb_updatePos, this);
	if (vartype == 1) { radVisible->callback(cb_vectorExclusive, this); }
	this->end();
}
