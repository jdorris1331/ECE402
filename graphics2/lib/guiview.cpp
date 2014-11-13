#include "guiview.h"
#include "ctrlgui.h"
#include "ctrlspinners.h"
#include "ctrlsliders.h"
#include "ctrlcmd.h"

#include "sliderbox.h"
#include <sstream>
#include <iomanip>
#include <iostream>

void GUIView::cb_launchGraph(Fl_Widget *w, void *data) { ((GUIView*)data)->launchGraph(); }
void GUIView::launchGraph()
{
	graph = new Graphics();
	//graph->RunThread();
}

GUIView::GUIView(const char *sFile) : Fl_Window(900, 700, "PDER Control Panel")
{
	fraFrame = new Fl_Pack(0, 0, 900, 700, 0);
	fraFrame->spacing(1);

	Graphics *graph = new Graphics();
	
	launchGraph();
	
	mb = new CtrlMenuBar();
	
	fraMain[0] = new CtrlGui(graph);
	fraMain[0]->end();
	fraMain[1] = new Fl_Pack(0, 0, 900, 700, 0);
	fraMain[1]->type(Fl_Pack::HORIZONTAL);
	fraMain[1]->spacing(20);
	fraMain[1]->end();
	//fraMain[2] = new CtrlCmd();
	//fraMain[2]->end();

	fraMain[1]->add(new CtrlSpinners(sFile));
	fraMain[1]->add(new CtrlSliders(sFile));

	fraFrame->end();
	this->resizable(fraMain[1]);
	fraFrame->show();
	this->end();
	
	fraFrame->add(mb);
	fraFrame->add(fraMain[0]);
	fraFrame->add(fraMain[1]);
}
