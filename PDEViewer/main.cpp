#include "guiview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GUIView gui;
    gui.show();

    return a.exec();
}
