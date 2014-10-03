#include "..\include\ctrlsliders.h"

CtrlSliders::CtrlSliders(QWidget *parent) : QFrame(parent)
{
    this->setLayout(new QGridLayout);


    mgl = new MglWrapper();
    mgl->loadData(0, NULL, NULL, NULL, NULL);
    mgl->plot();


    for (int ct = 0; ct < 5; ct++)
    {
        fraSliders[ct] = new QFrame(this);
        fraSliders[ct]->setLayout(new QGridLayout);
        this->layout()->addWidget(fraSliders[ct]);
    }

    omega = new SliderBox("omega", 0, 100, 10, 10.0, 1, fraSliders[0]);
    theta_BA = new SliderBox("theta_BA", 0, 10, 5, 10.0, 1, fraSliders[0]);
    theta_BP = new SliderBox("theta_BP", 0, 10, 5, 10.0, 1, fraSliders[0]);
    D_BAM = new SliderBox("D_BAM", 0, 100, 50, 10000.0, 4, fraSliders[0]);
    D_BPM = new SliderBox("D_BPM", 0, 100, 50, 10000.0, 4, fraSliders[0]);
    theta_C = new SliderBox("theta_C", 0, 100, 90, 100.0, 2, fraSliders[0]);
    T_BA = new SliderBox("T_BA", 0, 100, 10, 10.0, 1, fraSliders[0]);
    T_BC = new SliderBox("T_BC", 0, 100, 50, 10.0, 1, fraSliders[0]);
    T_BAM = new SliderBox("T_BAM", 0, 100, 10, 10.0, 1, fraSliders[0]);
    T_BPM = new SliderBox("T_BPM", 0, 100, 30, 10.0, 1, fraSliders[0]);

    SliderBox *slidersN[] = { omega, theta_BA, theta_BP,
             D_BAM, D_BPM, theta_C, T_BA, T_BC,
             T_BAM, T_BPM };
    for (int ct = 0; ct < 10; ct++) {
        fraSliders[0]->layout()->addWidget(slidersN[ct]); }

    fraSliders[0]->layout()->setSpacing(2);
    for (int ct = 0; ct < 5; ct++)
    {
        fraSliders[ct]->layout()->update();
        fraSliders[ct]->adjustSize();
    }
}
