#ifndef TV_VIEW_H
#define TV_VIEW_H

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
class TV_view;
}

class TV_view : public QMainWindow
{
    Q_OBJECT

public:
    explicit TV_view(QWidget *parent = 0, User *u = new User);
    ~TV_view();
    void picflowEvent();
    void timerEvent(QTimerEvent *event);
    QTimer *Timer;
    User usernow;
    Film filmtemp;
    std::string user_film[100][2];

private:
    Ui::TV_view *ui;
    std::string filelocation;

private slots:
    void initForm();
    void setBtnQss(QPushButton *btn,
                   QString normalColor, QString normalTextColor,
                   QString hoverColor, QString hoverTextColor,
                   QString pressedColor, QString pressedTextColor);
    void setTxtQss(QLineEdit *txt, QString normalColor, QString focusColor);
    void setBarQss(QProgressBar *bar, QString normalColor, QString chunkColor);
    void setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor);
    void fresh();
    void openVideo();
    void filmOfUser();
    void open();
};

#endif // TV_VIEW_H
