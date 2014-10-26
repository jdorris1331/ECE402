#ifndef CTRLCMD_H
#define CTRLCMD_H

#include <Fl/Fl_Pack.H>

class CtrlCmd : public Fl_Pack
{
public:
    CtrlCmd(int x, int y, int w, int h, const char *label = 0);

private:
    Fl_Pack *fraCtrlCmd[3];
};

#endif // CTRLCMD_H
