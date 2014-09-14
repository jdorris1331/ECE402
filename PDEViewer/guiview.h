#ifndef GUIVIEW_H
#define GUIVIEW_H

#include <QMainWindow>
#include <QFrame>
#include <QScrollArea>
#include "ctrlmenubar.h"

class GUIView : public QMainWindow
{
    Q_OBJECT

public:
    GUIView(QWidget *parent = 0);
    //void repaint();
    //void resizeEvent(QResizeEvent *event);

private:
    CtrlMenuBar *mb;
    QFrame *fraFrame, *fraMain[3], *fraGraph, *fraSliders;
    QScrollArea *scrMain;

};

#endif // GUIVIEW_H
