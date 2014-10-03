<<<<<<< HEAD:PDEViewer/src/main.cpp
#include "..\include\initview.h"
#include "..\include\guiview.h"
=======
#include "guiview.h"
>>>>>>> parent of 79f3b53... Initial load dialog added:PDEViewer/main.cpp
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    GUIView gui;
    gui.show();

    return a.exec();
}
