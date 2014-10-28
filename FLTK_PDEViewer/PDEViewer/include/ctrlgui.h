#ifndef CTRLGUI_H
#define CTRLGUI_H

#include <Windows.h>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Hor_Nice_Slider.H>
#include <FL/Fl_Check_Button.H>

class CtrlGui : public Fl_Pack
{
private:
	Fl_Pack *fraCtrlGui[3];
	Fl_Button *btnEdit, *btnDelete, *btnAdd, *btnSettings;
	Fl_Choice *cmbAdd, *cmbUpdateFreq;
	Fl_Hor_Nice_Slider *sldSpeed;
	Fl_Check_Button *chkViewUpdates;
	//Fl_Menu_Item *cmbItems;

public:
    CtrlGui();
};

#endif // CTRLGUI_H
