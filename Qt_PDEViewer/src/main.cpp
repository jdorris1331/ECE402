#include "..\include\initview.h"
#include "..\include\guiview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    InitView init;
    init.show();

    //GUIView gui;
    //gui.show();

    return a.exec();
}
