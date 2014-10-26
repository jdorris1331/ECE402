#include "..\include\guiview.h"
#include "..\include\ctrlgui.h"
//#include "..\include\ctrlgraph.h"
#include "..\include\ctrlsliders.h"
#include "..\include\ctrlcmd.h"

GUIView::GUIView(const char *sFile) : Fl_Window(500, 50, "PDER Control Panel")
{
	fraFrame = new Fl_Pack(0, 0, 500, 50, 0);
	fraFrame->spacing(1);
	
	mb = new CtrlMenuBar();
	
	fraMain[0] = new CtrlGui();
	fraMain[1] = new CtrlSliders(sFile);
	fraMain[2] = new CtrlCmd();
	fraMain[1]->setFrameShadow(QFrame::Raised);
	fraMain[2]->setFrameShadow(QFrame::Raised);

	for (int ct = 0; ct < 3; ct++)
	{
		fraFrame->add(fraMain[ct]);
	}
	
	fraFrame->end();
	this->resizable(fraFrame);
	fraFrame->show();
}
