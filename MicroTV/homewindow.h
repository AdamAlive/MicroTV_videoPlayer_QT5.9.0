#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include<QMainWindow>
#include<vector>
#include<QString>
#include"user.h"
#include <iostream>
#include "mysql.h"
#include <QtSql>

class QPushButton;
class QLineEdit;
class QProgressBar;
class QSlider;

namespace Ui
{
class HomeWindow;
}

class HomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomeWindow(QWidget *parent = 0);
    ~HomeWindow();
    void pushUser(User);
    //void keyPressEvent(QKeyEvent *event);
    std::string accounttemp;
    std::string passwordtemp;
    User Usernow;
    User users[100];
    int userSize = 0;
    void timerEvent(QTimerEvent *event);


private:
    Ui::HomeWindow *ui;



private slots:
    void initForm();
    void setBtnQss(QPushButton *btn,
                   QString normalColor, QString normalTextColor,
                   QString hoverColor, QString hoverTextColor,
                   QString pressedColor, QString pressedTextColor);
    void setTxtQss(QLineEdit *txt, QString normalColor, QString focusColor);
    void setBarQss(QProgressBar *bar, QString normalColor, QString chunkColor);
    void setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor);
    void closeWindow();
    void login();
    void autologin();
    void registerA();


};


#endif // HOMEWINDOW_H
