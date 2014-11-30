#include "ctrlspinners.h"

void CtrlSpinners::cb_updatePos(Fl_Widget *w, void *data) { ((CtrlSpinners*)data)->updatePos(); }
void CtrlSpinners::updatePos()
{
	SpinnerBox *spinhold;
	int ct, oldpos, newpos;
	oldpos = -1; newpos = -1;

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

CtrlSpinners::CtrlSpinners(Graphics *myGraph, cont_data *myDat) : Fl_Pack(0, 0, 520, 30, 0)
{
    graph = myGraph;
	dat = myDat;
	
	std::string sColors[] =
	{
	  "0xff0000", "0x00ff00", "0x0000ff", "0xffff00", "0x00ffff"
	  "0xff00ff", "0xff6600", "0x990099", "0x663333", "0x000000"
	};

	this->callback(cb_updatePos, this);

	this->spacing(5);

	fraRows[0] = new Fl_Pack(0, 0, 260, 30, 0);
	fraRows[0]->type(Fl_Pack::HORIZONTAL);
	fraRows[0]->spacing(5);
	fraSpinners[0] = new Fl_Pack(0, 0, 260, 30, 0);
	//fraSpinners[0]->label("Variables");
	//fraSpinners[0]->align(FL_ALIGN_LEFT);
	fraSpinners[0]->spacing(5);
	std::vector<int> vSca, vVec;
	for (int i = 0; i < dat->vList->var.size(); i++)
	{
	  if (dat->vList->var[i].get_type() == 1) {
	    vSca.push_back(i); }
	  else if (dat->vList->var[i].get_type() == 2) {
	    vVec.push_back(i); }
	}
	spinners.push_back(new SpinnerBox(-1, "red", "0xff0000", 1));
	spinners.push_back(new SpinnerBox(-1, "green", "0x00ff00", 2));
	spinners.push_back(new SpinnerBox(-1, "blue", "0x0000ff", 3));
	spinners.push_back(new SpinnerBox(-1, "yellow", "0xffff00", 4));
	spinners.push_back(new SpinnerBox(-1, "cyan", "0x00ffff", 5));
	fraSpinners[0]->end();

	fraSpinners[1] = new Fl_Pack(0, 0, 260, 30, 0);
	fraSpinners[1]->spacing(5);
	spinners.push_back(new SpinnerBox(-1, "magenta", "0xff00ff", 6, 1));
	spinners.push_back(new SpinnerBox(-1, "orange", "0xff6600", 7, 1));
	spinners.push_back(new SpinnerBox(-1, "purple", "0x990099", 8, 1));
	spinners.push_back(new SpinnerBox(-1, "brown", "0x663333", 9, 1));
	spinners.push_back(new SpinnerBox(-1, "black", "0x000000", 10, 1));
	fraSpinners[1]->end();
	fraRows[0]->end();

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
	

	this->resizable(fraSpinners[0]);
}
