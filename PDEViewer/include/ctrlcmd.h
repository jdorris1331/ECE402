#ifndef CTRLCMD_H
#define CTRLCMD_H

#include <QFrame>

class CtrlCmd : public QFrame
{
public:
    CtrlCmd(QWidget *parent = 0);

private:
    QFrame *fraCtrlCmd[3];
};

#endif // CTRLCMD_H
