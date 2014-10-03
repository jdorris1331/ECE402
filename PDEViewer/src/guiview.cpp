#include <QGridLayout>
#include <QHBoxLayout>
#include "..\include\guiview.h"
#include "..\include\ctrlgui.h"
#include "..\include\ctrlgraph.h"
#include "..\include\ctrlsliders.h"
#include "..\include\ctrlcmd.h"

GUIView::GUIView(QWidget *parent) : QMainWindow(parent)
{
    fraFrame = new QFrame(this);
    fraFrame->setLayout(new QVBoxLayout);
    fraFrame->layout()->setSpacing(1);
    fraFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mb = new CtrlMenuBar(this);
    fraFrame->layout()->addWidget(mb);

    fraMain[0] = new CtrlGui(fraFrame);
    fraMain[1] = new QFrame(fraFrame);
    fraMain[1]->setLayout(new QHBoxLayout);
    fraGraph = new CtrlGraph(fraMain[1]);
    fraSliders = new CtrlSliders(fraMain[1]);
    fraMain[1]->layout()->addWidget(fraGraph);
    fraMain[1]->layout()->addWidget(fraSliders);
    fraMain[2] = new CtrlCmd(fraFrame);
    //fraMain[1]->setStyleSheet("border: 1px inset gray");
    fraMain[1]->setFrameShadow(QFrame::Raised);
    fraMain[2]->setFrameShadow(QFrame::Raised);

    fraGraph->layout()->update();
    fraGraph->adjustSize();
    fraSliders->layout()->update();
    fraSliders->adjustSize();
    for (int ct = 0; ct < 3; ct++)
    {
        fraMain[ct]->layout()->update();
        fraMain[ct]->adjustSize();
        fraFrame->layout()->addWidget(fraMain[ct]);
    }

    fraFrame->layout()->update();
    fraFrame->adjustSize();
    this->setCentralWidget(fraFrame);
    this->adjustSize();
}
