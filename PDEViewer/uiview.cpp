#include "uiview.h"
#include "ui_uiview.h"

UIView::UIView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIView)
{
    ui->setupUi(this);
}

UIView::~UIView()
{
    delete ui;
}

//void UIView::on_slideOmega_sliderMoved(int position)
//{

//}
