#include "..\include\ctrlgui.h"

CtrlGui::CtrlGui() : Fl_Pack(0, 0, 500, 30, 0)
{
	this->type(Fl_Pack::HORIZONTAL);

    fraCtrlGui[0] = new Fl_Pack(0, 0, 500, 30, 0);
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
	fraCtrlGui[0]->end();

	fraCtrlGui[1] = new Fl_Pack(0, 0, 500, 30, 0);
	fraCtrlGui[1]->type(Fl_Pack::HORIZONTAL);
	sldSpeed = new Fl_Slider(0, 0, 100, 30, "Speed");
	sldSpeed->type(HORIZONTAL);
	chkViewUpdates = new Fl_Check_Button(0, 0, 100, 30, "View Updates");
	cmbUpdateFreq = new Fl_Choice(0, 0, 100, 30, 0);
	Fl_Menu_Item cmbItems1[] = {
		{ "Continuous" },
		{ "On Tick" },
		{ 0 } };
	cmbUpdateFreq->copy(cmbItems1);
	fraCtrlGui[1]->end();

	fraCtrlGui[2] = new Fl_Pack(0, 0, 500, 30, 0);
	btnSettings = new Fl_Button(0, 0, 100, 30, "Settings");
    fraCtrlGui[2]->end();
}
