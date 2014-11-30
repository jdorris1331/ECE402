#include "ctrlgui.h"

void CtrlGui::cb_toggleGraph(Fl_Widget *w, void *data)
{
	((CtrlGui*)data)->toggleGraph();
}
void CtrlGui::toggleGraph()
{
	std::cout << "calling toggle\n";
	
	graph->toggleAnimation();
	sleep(1);
	//graph->Run();
	std::cout << btnStart->label() << std::endl;
	if (btnStart->label() == "Start") { btnStart->label("Pause"); }
	else { btnStart->label("Start"); }

}

CtrlGui::CtrlGui(Graphics *myGraph) : Fl_Pack(0, 0, 900, 30, 0)
{
	graph = myGraph;

	this->type(Fl_Pack::HORIZONTAL);
	this->spacing(1);

    /*fraCtrlGui[0] = new Fl_Pack(0, 0, 900, 30, 0);
	fraCtrlGui[0]->type(Fl_Pack::HORIZONTAL);
	btnEdit = new Fl_Button(0, 0, 100, 30, "Edit");
	btnDelete = new Fl_Button(0, 0, 100, 30, "Delete");
	btnAdd = new Fl_Button(0, 0, 100, 30, "Add");
	cmbAdd = new Fl_Choice(0, 0, 100, 30, 0);
	Fl_Menu_Item cmbItems0[] = {
		{ "Button" },
		{ "Slider" },
		{ "Switch" },
		{ "Chooser" },
		{ "Input" },
		{ "Monitor" },
		{ "Plot" },
		{ "Output" },
		{ "Note" },
		{ 0 } };
	cmbAdd->copy(cmbItems0);
	fraCtrlGui[0]->end();*/

	fraCtrlGui[1] = new Fl_Pack(0, 0, 900, 30, 0);
	fraCtrlGui[1]->type(Fl_Pack::HORIZONTAL);
	btnStart = new Fl_Button(0, 0, 100, 30, "Start");
	sldSpeed = new Fl_Hor_Nice_Slider(0, 0, 100, 10, "Speed");
	chkViewUpdates = new Fl_Check_Button(0, 0, 110, 30, "View Updates");
	cmbUpdateFreq = new Fl_Choice(0, 0, 100, 30, 0);
	Fl_Menu_Item cmbItems1[] = {
		{ "Continuous" },
		{ "On Tick" },
		{ 0 } };
	cmbUpdateFreq->copy(cmbItems1);
	fraCtrlGui[1]->end();

	fraCtrlGui[2] = new Fl_Pack(0, 0, 100, 30, 0);
	btnSettings = new Fl_Button(0, 0, 100, 30, "Settings");
    fraCtrlGui[2]->end();

	//this->resizable(fraCtrlGui[1]);
	//fraCtrlGui[1]->resizable(sldSpeed);

	btnStart->callback(cb_toggleGraph, this);
}
