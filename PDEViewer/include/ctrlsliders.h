#ifndef CTRLSLIDERS_H
#define CTRLSLIDERS_H

#include <QFrame>
#include <QGridLayout>
#include <QScrollArea>
#include "sliderbox.h"
#include "MglWrapper/MglWrapper.h"

class CtrlSliders : public QScrollArea
{
public:
    CtrlSliders(QString sFile, QWidget *parent = 0);

private:
    MglWrapper *mgl;
    QFrame *fraGraph, *fraSliders[5], *fraButtons[2];
    SliderBox *omega, *theta_BA, *theta_BP, *D_BAM, *D_BPM,
            *theta_C, *T_BA, *T_BC, *T_BAM, *T_BPM;
};

#endif // CTRLSLIDERS_H
