#include "..\include\ctrlspinners.h"
#include <iostream>

void CtrlSpinners::cb_updatePos(Fl_Widget *w, void *data) { ((CtrlSpinners*)data)->updatePos(); }
void CtrlSpinners::updatePos()
{
	std::cerr << "checkupdate" << std::endl;

	SpinnerBox *spinhold;
	int ct, oldpos, newpos;

	for (ct = 0; ct < spinners.size(); ct++)
	{
		if (ct + 1 != spinners[ct]->getPos())
		{
			oldpos = ct + 1;
			newpos = spinners[ct]->getPos();
			break;
		}
	}

	if (oldpos < newpos) //demoted
	{
		spinhold = spinners[oldpos - 1];
		for (ct = oldpos - 1; ct < newpos - 1; ct++)
		{
			spinners[ct] = spinners[ct + 1];
			spinners[ct]->setPos(ct + 1);
		}
		spinners[newpos - 1] = spinhold;
		spinners[newpos - 1]->setPos(newpos);
		redrawSpinners();
	}
	else if (oldpos > newpos) //promoted
	{
		spinhold = spinners[oldpos - 1];
		for (ct = oldpos - 1; ct > newpos - 1; ct--)
		{
			spinners[ct] = spinners[ct - 1];
			spinners[ct]->setPos(ct - 1);
		}
		spinners[newpos - 1] = spinhold;
		spinners[newpos - 1]->setPos(newpos);
		redrawSpinners();
	}
	else {} //false alarm
}
void CtrlSpinners::redrawSpinners()
{
	int ct;

	for (ct = 0; ct < spinners.size(); ct++)
	{
		this->remove(spinners[ct]);
		spinners[ct]->hide();
	}

	for (ct = 0; ct < spinners.size(); ct++)
	{
		this->add(spinners[ct]);
		spinners[ct]->show();
	}

	this->redraw();
}

CtrlSpinners::CtrlSpinners(const char *sFile) : Fl_Pack(0, 0, 160, 30, 0)
{
	this->callback(cb_updatePos, this);

	fraSpinners[0] = new Fl_Pack(0, 0, 160, 30, 0);
	fraSpinners[0]->label("Constants");
	fraSpinners[0]->align(FL_ALIGN_LEFT);
	fraSpinners[0]->spacing(2);
	spinners.push_back(new SpinnerBox("red", "0xff0000", 1));
	spinners.push_back(new SpinnerBox("green", "0x00ff00", 2));
	spinners.push_back(new SpinnerBox("blue", "0x0000ff", 3));
	spinners.push_back(new SpinnerBox("yellow", "0xffff00", 4));
	spinners.push_back(new SpinnerBox("cyan", "0x00ffff", 5));
	spinners.push_back(new SpinnerBox("magenta", "0xff00ff", 6));
	spinners.push_back(new SpinnerBox("orange", "0xff6600", 7));
	spinners.push_back(new SpinnerBox("purple", "0x990099", 8));
	spinners.push_back(new SpinnerBox("brown", "0x663333", 9));
	spinners.push_back(new SpinnerBox("black", "0x000000", 10));

	spinners[0]->last = NULL;
	spinners[0]->next = spinners[1];
	for (int ct = 1; ct < 9; ct++)
	{
		spinners[ct]->last = spinners[ct - 1];
		spinners[ct]->next = spinners[ct + 1];
	}
	spinners[9]->last = spinners[8];
	spinners[9]->next = NULL;

	/*SliderBox *slidersN[] = { omega, theta_BA, theta_BP,
		D_BAM, D_BPM, theta_C, T_BA, T_BC,
		T_BAM, T_BPM };
	for (int ct = 0; ct < 10; ct++) {
		fraSliders[0]->add(slidersN[ct]);
	}*/

	for (int ct = 0; ct < spinners.size(); ct++)
	{
		spinners[ct]->callback(cb_updatePos, this);
	}

	fraSpinners[0]->end();

	

	this->resizable(fraSpinners[0]);
}
