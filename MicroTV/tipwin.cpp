#include "tipwin.h"
#include "ui_tipwin.h"

TipWin::TipWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TipWin)
{
    ui->setupUi(this);
}

TipWin::~TipWin()
{
    delete ui;
}
