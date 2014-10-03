#ifndef CTRLMENUBAR_H
#define CTRLMENUBAR_H

#include <QMenuBar>
#include <QMenu>
#include <QAction>

class CtrlMenuBar : public QMenuBar
{
public:
    CtrlMenuBar(QWidget *parent = 0);

private:
    QMenu *file, *edit, *tools, *zoom, *help;
};

#endif // CTRLMENUBAR_H
