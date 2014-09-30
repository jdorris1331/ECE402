#ifndef INITVIEW_H
#define INITVIEW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QFileDialog>
#include <QFrame>
#include <vector>
#include "guiview.h"

class InitView : public QMainWindow
{
    Q_OBJECT

public:
    InitView(QWidget *parent = 0);
    QPushButton *btnOpen, *btnBrowse;
    QLineEdit *txtFile;
    std::vector<GUIView*> vGui;
    QFrame *fraView;

signals:
    void clicked();

public slots:
    void pickFile();
    void launchControls();
};

#endif // INITVIEW_H
