#include "..\include\guiview.h"
#include "..\include\ctrlgui.h"
//#include "..\include\ctrlgraph.h"
#include "..\include\ctrlsliders.h"
#include "..\include\ctrlcmd.h"

GUIView::GUIView(const char *sFile) : Fl_Window(900, 700, "PDER Control Panel")
{
	fraFrame = new Fl_Pack(0, 0, 900, 50, 0);
	fraFrame->spacing(1);
	
	mb = new CtrlMenuBar();
	
	fraMain[0] = new CtrlGui();
	fraMain[1] = new CtrlSliders(sFile);
	fraMain[2] = new CtrlCmd();

	for (int ct = 0; ct < 3; ct++)
	{
		fraFrame->add(fraMain[ct]);
	}
	
	fraFrame->end();
	this->resizable(fraMain[1]);
	fraFrame->show();
}
