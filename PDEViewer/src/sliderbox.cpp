#include "..\include\sliderbox.h"
#include <iomanip>

SliderBox::SliderBox(std::string name, int min, int max, int val,
                     double scl, int prc, QWidget *parent) : QFrame(parent)
{
    iPrc = prc;
    dblScl = scl;
    dblVal = val/scl;
    ss.clear();
    ss.str("");
    ss << std::fixed << std::setprecision(prc) << dblVal;
    sVal = ss.str();

    this->setFixedSize(160,35);
    this->setFrameShadow(QFrame::Raised);
    this->setStyleSheet("background-color: rgb(0, 170, 255);");

    lblName = new QLabel(QString::fromStdString(name), this);
    lblName->setGeometry(6,15,50,15);
    lblVal = new QLabel(QString::fromStdString(sVal), this);
    lblVal->setGeometry(105,15,50,15);
    lblVal->setAlignment(Qt::AlignRight);
    sld = new QSlider(Qt::Horizontal, this);
    sld->setGeometry(5,1,150,15);
    sld->setMinimum(min);
    sld->setMaximum(max);
    sld->setValue(val);

    connect(sld, SIGNAL(valueChanged(int)), this, SLOT(update(int)));
}

void SliderBox::update(int val)
{
    dblVal = val/dblScl;
    ss.clear();
    ss.str("");
    ss << std::fixed << std::setprecision(iPrc) << dblVal;
    sVal = ss.str();
    lblVal->setText(QString::fromStdString(sVal));
}
