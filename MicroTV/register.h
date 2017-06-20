#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include <QTimerEvent>
#include<QString>
#include"user.h"
#include "film.h"
#include <iostream>
#include<QPushButton>
#include<QLineEdit>
#include<QProgressBar>
#include<QSlider>


namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();
    bool vip = false;

private:
    Ui::Register *ui;
    std::string Name;
    std::string Passport;
    bool isVip;

private slots:
    void registered();
    void isvip1();
    void isvip2();
    void initForm();
    void setBtnQss(QPushButton *btn,
                   QString normalColor, QString normalTextColor,
                   QString hoverColor, QString hoverTextColor,
                   QString pressedColor, QString pressedTextColor);
    void setTxtQss(QLineEdit *txt, QString normalColor, QString focusColor);
    void setBarQss(QProgressBar *bar, QString normalColor, QString chunkColor);
    void setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor);
};

#endif // REGISTER_H


