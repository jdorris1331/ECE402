#include "..\include\ctrlcmd.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QLineEdit>
#include <QTextEdit>

QLabel *lblCommandCenter, *lblObserver;
QPushButton *btnSwitch, *btnClear;
QToolButton *btnHistory;
QLineEdit *txtCmd;
QTextEdit *txtLog;

CtrlCmd::CtrlCmd(QWidget *parent) : QFrame(parent)
{
    //this->setStyleSheet("background-color:rgb(200,200,230);");
    this->setLayout(new QVBoxLayout);
    this->layout()->setSpacing(1);
    for (int ct = 0; ct < 3; ct++)
    {
        fraCtrlCmd[ct] = new QFrame(this);
        fraCtrlCmd[ct]->setLayout(new QHBoxLayout);
        this->layout()->addWidget(fraCtrlCmd[ct]);
    }

    lblCommandCenter = new QLabel(QString::fromStdString("Command Center"), fraCtrlCmd[0]);
    btnSwitch = new QPushButton(QIcon(), NULL, fraCtrlCmd[0]);
    btnClear = new QPushButton(QString::fromStdString("Clear"), fraCtrlCmd[0]);
    fraCtrlCmd[0]->layout()->addWidget(lblCommandCenter);
    fraCtrlCmd[0]->layout()->addWidget(btnSwitch);
    fraCtrlCmd[0]->layout()->addWidget(btnClear);

    txtLog = new QTextEdit(fraCtrlCmd[1]);
    txtLog->setReadOnly(true);
    fraCtrlCmd[1]->layout()->addWidget(txtLog);

    lblObserver = new QLabel(QString::fromStdString("observer>"), fraCtrlCmd[2]);
    txtCmd = new QLineEdit(fraCtrlCmd[2]);
    btnHistory = new QToolButton(fraCtrlCmd[2]);
    fraCtrlCmd[2]->layout()->addWidget(lblObserver);
    fraCtrlCmd[2]->layout()->addWidget(txtCmd);
    fraCtrlCmd[2]->layout()->addWidget(btnHistory);

    btnSwitch->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnClear->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    txtLog->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    txtCmd->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    btnHistory->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    for (int ct = 0; ct < 3; ct++)
    {
        fraCtrlCmd[ct]->layout()->update();
        fraCtrlCmd[ct]->adjustSize();
    }
}
