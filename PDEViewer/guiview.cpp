#include <QGridLayout>
#include <QHBoxLayout>
#include "guiview.h"
#include "ctrlgui.h"
#include "ctrlgraph.h"
#include "ctrlsliders.h"
#include "ctrlcmd.h"

GUIView::GUIView(QString sFile, QWidget *parent) : QMainWindow(parent)
{
    fraFrame = new QFrame(this);
    fraFrame->setLayout(new QVBoxLayout);
    fraFrame->layout()->setSpacing(1);
    fraFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mb = new CtrlMenuBar(this);
    fraFrame->layout()->addWidget(mb);

    fraMain[0] = new CtrlGui(fraFrame);
    fraMain[1] = new CtrlSliders(sFile, fraFrame);
    fraMain[2] = new CtrlCmd(fraFrame);
    //fraMain[1]->setStyleSheet("border: 1px inset gray");
    fraMain[1]->setFrameShadow(QFrame::Raised);
    fraMain[2]->setFrameShadow(QFrame::Raised);

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
