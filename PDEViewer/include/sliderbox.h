#ifndef SLIDERBOX_H
#define SLIDERBOX_H

#include <string>
#include <QFrame>
#include <QLabel>
#include <QSlider>
#include <sstream>
#include "model.h"

class SliderBox : public QFrame
{
    Q_OBJECT

public:
    SliderBox(std::string name, int min, int max, int val,
              double scl, int prc, QWidget *parent = 0);
    QLabel *lblName, *lblVal;
    QSlider *sld;

private:
    double dblScl, dblVal;
    int iPrc;
    std::string sVal;
    std::stringstream ss;

signals:
    void moved(int pos);

public slots:
    void update(int val);
};

#endif // SLIDERBOX_H
