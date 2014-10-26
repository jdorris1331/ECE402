#ifndef CTRLGUI_H
#define CTRLGUI_H

#include <QFrame>
#include <QPushButton>
#include <QComboBox>
#include <QSlider>
#include <QCheckBox>
#include <QHBoxLayout>

class CtrlGui : public QFrame
{
public:
    CtrlGui(QWidget *parent = 0);

private:
    QFrame *fraCtrlGui[3];
    QPushButton *btnEdit, *btnDelete, *btnAdd, *btnSettings;
    QComboBox *cmbAdd, *cmbUpdateFreq;
    QSlider *sldSpeed;
    QCheckBox *chkViewUpdates;
};

#endif // CTRLGUI_H
