#include "..\include\ctrlgui.h"

CtrlGui::CtrlGui(QWidget *parent) : QFrame(parent)
{
    this->setLayout(new QHBoxLayout);
    for (int ct = 0; ct < 3; ct++)
    {
        fraCtrlGui[ct] = new QFrame(this);
        fraCtrlGui[ct]->setLayout(new QHBoxLayout);
        this->layout()->addWidget(fraCtrlGui[ct]);
    }

    btnEdit = new QPushButton(QIcon(), QString::fromStdString("Edit"), fraCtrlGui[0]);
    btnDelete = new QPushButton(QIcon(), QString::fromStdString("Delete"), fraCtrlGui[0]);
    btnAdd = new QPushButton(QIcon(), QString::fromStdString("Add"), fraCtrlGui[0]);
    cmbAdd = new QComboBox(fraCtrlGui[0]);
    cmbAdd->addItem(QIcon(), QString::fromStdString("Button"), NULL);
    cmbAdd->addItem(QIcon(), QString::fromStdString("Slider"), NULL);
    cmbAdd->addItem(QIcon(), QString::fromStdString("Switch"), NULL);
    cmbAdd->addItem(QIcon(), QString::fromStdString("Chooser"), NULL);
    cmbAdd->addItem(QIcon(), QString::fromStdString("Input"), NULL);
    cmbAdd->addItem(QIcon(), QString::fromStdString("Monitor"), NULL);
    cmbAdd->addItem(QIcon(), QString::fromStdString("Plot"), NULL);
    cmbAdd->addItem(QIcon(), QString::fromStdString("Output"), NULL);
    cmbAdd->addItem(QIcon(), QString::fromStdString("Note"), NULL);
    fraCtrlGui[0]->layout()->addWidget(btnEdit);
    fraCtrlGui[0]->layout()->addWidget(btnDelete);
    fraCtrlGui[0]->layout()->addWidget(btnAdd);
    fraCtrlGui[0]->layout()->addWidget(cmbAdd);

    sldSpeed = new QSlider(Qt::Horizontal, fraCtrlGui[1]);
    chkViewUpdates = new QCheckBox(QString::fromStdString("View Updates"), fraCtrlGui[1]);
    cmbUpdateFreq = new QComboBox(fraCtrlGui[1]);
    cmbUpdateFreq->addItem(QString::fromStdString("Continuous"));
    cmbUpdateFreq->addItem(QString::fromStdString("On Tick"));
    fraCtrlGui[1]->layout()->addWidget(sldSpeed);
    fraCtrlGui[1]->layout()->addWidget(chkViewUpdates);
    fraCtrlGui[1]->layout()->addWidget(cmbUpdateFreq);

    btnSettings = new QPushButton(QString::fromStdString("Settings"), fraCtrlGui[2]);
    fraCtrlGui[2]->layout()->addWidget(btnSettings);

    for (int ct = 0; ct < 3; ct++)
    {
        fraCtrlGui[ct]->layout()->update();
        fraCtrlGui[ct]->adjustSize();
    }
}
