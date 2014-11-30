#include "ctrlsliders.h"

CtrlSliders::CtrlSliders(Graphics *myGraph, cont_data *myDat) : Fl_Pack(0, 0, 160, 30, 0)
{
    graph = myGraph;
	dat = myDat;

	fraSliders[0] = new Fl_Pack(0, 0, 160, 30, 0);
	//fraSliders[0]->label("Constants");
	fraSliders[0]->align(FL_ALIGN_LEFT);
	fraSliders[0]->spacing(2);
    omega = new SliderBox("omega", 0, 100, 10, 10.0, 1);
    theta_BA = new SliderBox("theta_BA", 0, 10, 5, 10.0, 1);
    theta_BP = new SliderBox("theta_BP", 0, 10, 5, 10.0, 1);
    D_BAM = new SliderBox("D_BAM", 0, 100, 50, 10000.0, 4);
    D_BPM = new SliderBox("D_BPM", 0, 100, 50, 10000.0, 4);
    theta_C = new SliderBox("theta_C", 0, 100, 90, 100.0, 2);
    T_BA = new SliderBox("T_BA", 0, 100, 10, 10.0, 1);
    T_BC = new SliderBox("T_BC", 0, 100, 50, 10.0, 1);
    T_BAM = new SliderBox("T_BAM", 0, 100, 10, 10.0, 1);
    T_BPM = new SliderBox("T_BPM", 0, 100, 30, 10.0, 1);

	/*SliderBox *slidersN[] = { omega, theta_BA, theta_BP,
		D_BAM, D_BPM, theta_C, T_BA, T_BC,
		T_BAM, T_BPM };
	for (int ct = 0; ct < 10; ct++) {
		fraSliders[0]->add(slidersN[ct]);
	}*/

	fraSliders[0]->end();

	this->resizable(fraSliders[0]);
}
