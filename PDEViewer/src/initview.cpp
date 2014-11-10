#include "..\include\initview.h"

void InitView::cb_pickFile(Fl_Widget *w, void *data) { ((InitView*)data)->pickFile(); }
void InitView::pickFile()
{
	char *sFile = fl_file_chooser("Open File", "Formatted Equation Files (*.csv)", "", 0);
	txtFile->value(sFile);
}

void InitView::cb_launchControls(Fl_Widget *w, void *data)
{
	InitView *loc = (InitView*)data;
	loc->launchControls(loc->launchGraph());
}
void InitView::launchControls(Graphics graph)
{
	GUIView *gui = new GUIView(graph, txtFile->value());
	vGui.push_back(gui);
	this->hide();
	gui->show();
}
Graphics InitView::launchGraph()
{
	Graphics test;
	std::cout << "Hello.cpp\n";
	//std::cout << "pthread: " << MGL_HAVE_PTHREAD  << std::endl;

	//test.beginAnimation();
	sleep(2);
	test.Run();

	return test;
}

InitView::InitView() : Fl_Window(500, 30, "PDER Launcher")
{
    fraView = new Fl_Pack(0, 0, 500, 30, 0);
	fraView->type(Fl_Pack::HORIZONTAL);
	fraView->spacing(1);

    txtFile = new Fl_Input(0, 0, 300, 30, 0);
	fraBut = new Fl_Pack(0, 0, 200, 30, 0);
	fraBut->type(Fl_Pack::HORIZONTAL);
    btnBrowse = new Fl_Button(0, 0, 100, 30, "Browse");
	btnOpen = new Fl_Button(0, 0, 100, 30, "Open");
	fraBut->end();

	fraView->resizable(txtFile);
	fraView->end();
	this->resizable(fraView);
	fraView->show();

	btnBrowse->callback(cb_pickFile, this);
	btnOpen->callback(cb_launchControls, this);
}
