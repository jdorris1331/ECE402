#include "..\include\initview.h"
#include "..\include\guiview.h"
#include <QString>

InitView::InitView(QWidget *parent) : QMainWindow(parent)
{
    fraView = new QFrame(this);

    fraView->setLayout(new QGridLayout);

    txtFile = new QLineEdit(fraView);
    btnBrowse = new QPushButton(QString::fromStdString("Browse"), fraView);
    btnOpen = new QPushButton(QString::fromStdString("Open"), fraView);

    btnBrowse->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnOpen->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    fraView->layout()->addWidget(txtFile);
    fraView->layout()->addWidget(btnBrowse);
    fraView->layout()->addWidget(btnOpen);

    fraView->layout()->update();
    fraView->adjustSize();

    connect(btnBrowse, SIGNAL(clicked()), this, SLOT(pickFile()));
    connect(btnOpen, SIGNAL(clicked()), this, SLOT(launchControls()));
}

void InitView::pickFile()
{
    QString sFile = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Files (*.*)"));
    txtFile->setText(sFile);
}

void InitView::launchControls()
{
    GUIView *gui = new GUIView(txtFile->text(), this);
    vGui.push_back(gui);
    this->hide();
    gui->show();
}
