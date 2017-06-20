#include "homewindow.h"
#include "ui_homewindow.h"
#include "account.h"
#include "User.h"
#include "tv_view.h"
#include "register.h"

#include <iostream>
#include <QDialog>
#include <QLabel>
#include <QFont>
#include <QDebug>

HomeWindow::HomeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomeWindow)
{

    ui->setupUi(this);
    this->initForm();
    connect(ui->botton_login, SIGNAL(clicked(bool)), this, SLOT(login()));
    connect(ui->botton_register, SIGNAL(clicked(bool)), this, SLOT(registerA()));
    //connect(ui->readByfileBtn,                    SIGNAL(clicked(bool)),  this,   SLOT(readStuMsgFormFile()));
    connect(ui->checkBox_autologin, SIGNAL(clicked(bool)), this, SLOT(autologin()));
    //QVector<User>UserList;
    //QString accounttemp;
    //QString passwordtemp;
    //QGraphicsScene *scene;
    //QString bgfilename = "login.png";
    //image->load(bgfileName);
    //QImage *image;
    //image->load("./login.png");
    //QGraphicsScene *scene = new QGraphicsScene;
    //scene->addPixmap(QPixmap::fromImage(*image));
    //QPixmap *pixmap = new QPixmap("./login.png");
    //ui->graphicsView = new QGraphicsView( scene,this );
    //scene->addPixmap(QPixmap("./login.png") );
    //↑以上是打开图片失败的尝试。。。

    //QImage* img=new QImage;
    //img->load("D:/QTProject/MicroTV/login.png");
    //ui->bg->setPixmap(QPixmap::fromImage(*img));

    /*QImage* img2=new QImage;
    img2->load("D:/QTProject/MicroTV/obj1.png");//D:/QTProject/MicroTV/obj1.png
    ui->obj1->setPixmap(QPixmap::fromImage(*img2));

    QImage* img3=new QImage;
    img3->load("D:/QTProject/MicroTV/obj2.png");
    ui->obj2->setPixmap(QPixmap::fromImage(*img3));

    QImage* img4=new QImage;
    img4->load("D:/QTProject/MicroTV/obj3.png");
    ui->obj3->setPixmap(QPixmap::fromImage(*img4));*/

    int a = startTimer(20);
}

HomeWindow::~HomeWindow()
{
    delete ui;
}


void HomeWindow::initForm()
{
    /*
    ui->bar1->setRange(0, 100);
    ui->bar2->setRange(0, 100);
    ui->slider1->setRange(0, 100);
    ui->slider2->setRange(0, 100);

    connect(ui->slider1, SIGNAL(valueChanged(int)), ui->bar1, SLOT(setValue(int)));
    connect(ui->slider2, SIGNAL(valueChanged(int)), ui->bar2, SLOT(setValue(int)));
    ui->slider1->setValue(30);
    ui->slider2->setValue(30);

    */
    this->setStyleSheet("*{outline:0px;}QWidget#frmMain{background:#FFFFFF;}");

    //setBtnQss(ui->botton_login, "#34495E", "#FFFFFF", "#4E6D8C", "#F0F0F0", "#2D3E50", "#B8C6D1");
    setBtnQss(ui->botton_login, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    setBtnQss(ui->botton_register, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    //setBtnQss(ui->btn4, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");

    setTxtQss(ui->lineEdit_account, "#DCE4EC", "#34495E");
    //setTxtQss(ui->lineEdit_password, "#DCE4EC", "#1ABC9C");
    //setTxtQss(ui->txt3, "#DCE4EC", "#3498DB");
    setTxtQss(ui->lineEdit_password, "#DCE4EC", "#E74C3C");

    //setBarQss(ui->bar1, "#E8EDF2", "#E74C3C");
    //setBarQss(ui->bar2, "#E8EDF2", "#1ABC9C");

    //setSliderQss(ui->slider1, "#E8EDF2", "#1ABC9C", "#1ABC9C");
    //setSliderQss(ui->slider2, "#E8EDF2", "#E74C3C", "#E74C3C");
    //setSliderQss(ui->slider1, "#E8EDF2", "#34495E", "#1ABC9C");
    //setSliderQss(ui->slider2, "#E8EDF2", "#3498DB", "#E74C3C");
}

void HomeWindow::setBtnQss(QPushButton *btn,
                        QString normalColor, QString normalTextColor,
                        QString hoverColor, QString hoverTextColor,
                        QString pressedColor, QString pressedTextColor)
{
    QStringList qss;
    qss.append(QString("QPushButton{border-style:none;padding:10px;border-radius:5px;color:%1;background:%2;}").arg(normalTextColor).arg(normalColor));
    qss.append(QString("QPushButton:hover{color:%1;background:%2;}").arg(hoverTextColor).arg(hoverColor));
    qss.append(QString("QPushButton:pressed{color:%1;background:%2;}").arg(pressedTextColor).arg(pressedColor));
    btn->setStyleSheet(qss.join(""));
}

void HomeWindow::setTxtQss(QLineEdit *txt, QString normalColor, QString focusColor)
{
    QStringList qss;
    qss.append(QString("QLineEdit{border-style:none;padding:6px;border-radius:5px;border:2px solid %1;}").arg(normalColor));
    qss.append(QString("QLineEdit:focus{border:2px solid %1;}").arg(focusColor));
    txt->setStyleSheet(qss.join(""));
}

void HomeWindow::setBarQss(QProgressBar *bar, QString normalColor, QString chunkColor)
{
    int barHeight = 8;
    int barRadius = 8;

    QStringList qss;
    qss.append(QString("QProgressBar{font:9pt;height:%2px;background:%1;border-radius:%3px;text-align:center;border:1px solid %1;}").arg(normalColor).arg(barHeight).arg(barRadius));
    qss.append(QString("QProgressBar:chunk{border-radius:%2px;background-color:%1;}").arg(chunkColor).arg(barRadius));
    //bar->setStyleSheet(qss.join(""));
}

void HomeWindow::setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor)
{
    int sliderHeight = 8;
    int sliderRadius = 4;
    int handleWidth = 13;
    int handleRadius = 6;
    int handleOffset = 3;

    QStringList qss;
    qss.append(QString("QSlider::groove:horizontal,QSlider::add-page:horizontal{height:%2px;border-radius:%3px;background:%1;}").arg(normalColor).arg(sliderHeight).arg(sliderRadius));
    qss.append(QString("QSlider::sub-page:horizontal{height:%2px;border-radius:%3px;background:%1;}").arg(grooveColor).arg(sliderHeight).arg(sliderRadius));
    qss.append(QString("QSlider::handle:horizontal{width:%2px;margin-top:-%3px;margin-bottom:-%3px;border-radius:%4px;"
                       "background:qradialgradient(spread:pad,cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0.6 #FFFFFF,stop:0.8 %1);}")
               .arg(handleColor).arg(handleWidth).arg(handleOffset).arg(handleRadius));
    slider->setStyleSheet(qss.join(""));
}

void HomeWindow::closeWindow()
{
    this->hide();
}

void HomeWindow::login()
{
    QString ac = ui->lineEdit_account->text();
    QString pass = ui->lineEdit_password->text();
    QFont ft;
    ft.setPointSize(20);



    if(ac == "")
    {
        QLabel *tips = new QLabel;
        //tips->resize(300,80);
        tips->setWindowTitle(QObject::tr("Log in fail."));
        tips->setText(QObject::tr("Please enter your account."));
        tips->setFont(ft);
        tips->show();
    }
    else if(pass == "")
    {
        QLabel *tips = new QLabel;
        //tips->resize(300,80);
        tips->setWindowTitle(QObject::tr("Log in fail."));
        tips->setText(QObject::tr("Please enter your password."));
        tips->setFont(ft);
        tips->show();
    }
    else
    {
        bool iflogin = false;
        for(int i = 0; i < userSize;++i)
        {
        if(ac == QString::fromStdString(users[i].getName()) && pass == QString::fromStdString(users[i].getpassport()))
        {
            QLabel *tips = new QLabel;
            tips->resize(300,60);
            tips->setWindowTitle(QObject::tr("Success!"));
            tips->setText(QObject::tr("You have logged in."));
            tips->setFont(ft);
            Usernow.setName(ac.toStdString());
            Usernow.setpassport(pass.toStdString());
            Usernow.setID(88888888);
            Usernow.setVip();

            TV_view *tv = new TV_view(0,&Usernow);
            tv->setWindowTitle(QObject::tr("Micro-TV   TV view"));
            tv->show();
            tips->show();
            this->close();
            iflogin = true;
            break;
        }
        }

        if(iflogin == false)
        {
        QLabel *tips = new QLabel;
        //tips->resize(300,80);
        tips->setWindowTitle(QObject::tr("Log in fail."));
        tips->setText(QObject::tr("Wrong password, please check again."));
        tips->setFont(ft);
        tips->show();
        }
    }

    /*QLabel *test = new QLabel;
    test->setText(QString::number(QString::compare(ac,pass),10));
    test->show();

    QLabel *test2 = new QLabel;
    test2->setText(ac);
    test2->show();

    QLabel *test3 = new QLabel;
    test3->setText(pass);
    test3->show();*/
}

/*void inputStuMsg::getStuMsg()
{

    QByteArray a =ui->stuIdLineText->text().toLatin1();
    QByteArray b = ui->stuNameLineText->text().toLatin1();
    char* str1 = a.data();
    char* str2 = b.data();
    int n = ui->stuScore1LineText->text().toInt();
    int m = ui->stuScore2LineText->text().toInt();
    Student stu(str2, str1, n, m);
    lst.push_back(stu);

    this->close();
}*/

void HomeWindow::autologin()
{
    ui->checkBox_rememberpassword->setChecked(Qt::Checked);
}

void HomeWindow::pushUser(User temp)
{
    //UserList[0].setName(temp.getName());
    //UserList[0].setpassport(temp.getpassport());
    //UserList[0].setID(temp.getID());
    //test00.push_back(5);
    //UserList[0] = temp;
}

void HomeWindow::registerA()
{
    Register *r = new Register;
    r->setWindowTitle(QObject::tr("Micro-TV   Rrgister"));
    r->show();
    this->close();
}


int ys1;
int ys2;
int ys3;
bool up1 =true;
bool up2 =false;
bool up3 =true;

void HomeWindow::timerEvent(QTimerEvent *event)
{
    //qDebug() << "counting";

//120 430 760
    if(up1)
    {
        ys1 = ui->obj1->geometry().y();
        ui->obj1->setGeometry(120,ys1 - 3,128,128);
        if(ys1 <= 20)
        {
            up1 =false;
        }
    }
    else
    {
    ys1 = ui->obj1->geometry().y();
    ui->obj1->setGeometry(120,ys1 + 3,128,128);
    if(ys1 >=140)
    {
        up1 = true;
    }
    }

    if(up2)
    {
        ys2 = ui->obj2->geometry().y();
        ui->obj2->setGeometry(430,ys2 - 3,128,128);
        if(ys2 <= 20)
        {
            up2 =false;
        }
    }
    else
    {
    ys2 = ui->obj2->geometry().y();
    ui->obj2->setGeometry(430,ys2 + 3,128,128);
    if(ys2 >=140)
    {
        up2 = true;
    }
    }

    if(up3)
    {
        ys3 = ui->obj3->geometry().y();
        ui->obj3->setGeometry(760,ys3 - 3,128,128);
        if(ys3 <= 20)
        {
            up3 =false;
        }
    }
    else
    {
    ys3 = ui->obj3->geometry().y();
    ui->obj3->setGeometry(760,ys3 + 3,128,128);
    if(ys3 >=140)
    {
        up3 = true;
    }
    }


}
