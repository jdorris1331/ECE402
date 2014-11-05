#include "guiview.h"
#include "ctrlgui.h"
//#include "..\include\ctrlgraph.h"
#include "ctrlsliders.h"
#include "ctrlcmd.h"

#include "sliderbox.h"
#include <sstream>
#include <iomanip>

void GUIView::cb_launchGraph(Fl_Widget *w, void *data) { ((GUIView*)data)->launchGraph(); }
void GUIView::launchGraph()
{
	graph = new Graphics();
   // graph = new Graphics();
	//graph->RunThread();
}

GUIView::GUIView(const char *sFile) : Fl_Window(900, 700, "PDER Control Panel")
{
	fraFrame = new Fl_Pack(0, 0, 900, 700, 0);
	fraFrame->spacing(1);
	launchGraph();
	mb = new CtrlMenuBar();
	std::cout << "Creating Windows\n";
	fraMain[0] = new CtrlGui(graph);
	std::cout << "Created graph\n";
	fraMain[1] = new CtrlSliders(sFile);
	//fraMain[2] = new CtrlCmd();
	for (int ct = 0; ct < 2; ct++)
	{
		fraFrame->add(fraMain[ct]);
	}

	fraFrame->end();
	this->resizable(fraMain[1]);
	fraFrame->show();

	this->end();
	
	
}
