#ifndef TIPWIN_H
#define TIPWIN_H

#include <QMainWindow>

namespace Ui {
class TipWin;
}

class TipWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit TipWin(QWidget *parent = 0);
    ~TipWin();

private:
    Ui::TipWin *ui;
};

#endif // TIPWIN_H
