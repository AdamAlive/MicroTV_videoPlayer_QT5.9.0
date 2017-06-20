#include "tv_view.h"
#include "ui_tv_view.h"
#include <QTimer>
#include <iostream>
#include <QDialog>
#include <QLabel>
#include <QFont>
#include "qdebug.h"
#include "videoplayer.h"
#include <iostream>
#include "Account.h"
#include "User.h"
#include "Administrator.h"
#include <string>
#include <QStandardItemModel>
using namespace std;

QStandardItemModel *list_model = new QStandardItemModel();

TV_view::TV_view(QWidget *parent, User *u ) :
    QMainWindow(parent),
    ui(new Ui::TV_view)
{
    usernow = *u;

    ui->setupUi(this);
    this->initForm();

    /*QImage* img=new QImage;
    img->load("D:/QTProject/MicroTV/0.png");
    ui->bg00->setPixmap(QPixmap::fromImage(*img));

    QImage* img2=new QImage;
    img2->load("D:/QTProject/MicroTV/1.png");
    ui->bg01->setPixmap(QPixmap::fromImage(*img2));

    QImage* img3=new QImage;
    img3->load("D:/QTProject/MicroTV/2.png");
    ui->bg02->setPixmap(QPixmap::fromImage(*img3));

    QImage* img4=new QImage;
    img4->load("D:/QTProject/MicroTV/3.png");
    ui->bg03->setPixmap(QPixmap::fromImage(*img4));*/

    Timer = new QTimer(this);
    int a = startTimer(10);
    //Timer->startTimer(1000);
    //connect(Timer,SIGNAL(timeout()),this,SLOT(picflowEvent()));

    //ui->tableView->show();
    //ui->openbutton->show();
    //ui->deletebutton->show();
    //下面是管理员按钮是否显示
    //ui->adminbutton->show();

    connect(ui->openbutton, SIGNAL(clicked(bool)), this, SLOT(openVideo()));
    connect(ui->adminbutton, SIGNAL(clicked(bool)),this, SLOT(fresh()));
    connect(ui->deletebutton, SIGNAL(clicked(bool)), this, SLOT(filmOfUser()));
    connect(ui->freshButton, SIGNAL(clicked(bool)), this, SLOT(fresh()));


    list_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Owner")));
    list_model->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Location")));

    ui->tableView->setModel(list_model);
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,100);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    fresh();
}

TV_view::~TV_view()
{
    delete ui;
}

int x1 = 0;
int x2 = 1026;
int x3 = 2052;

void TV_view::timerEvent(QTimerEvent *event)
{


    if(x1 <= -1026)
    {
        x1 = 2052;
        ui->bg01->setGeometry(x1,0,1026,590);
    }
    else
    {
    x1 = ui->bg01->geometry().x();
    ui->bg01->setGeometry(x1-3,0,1026,590);
    }

    if(x2 <= -1026)
    {
        x2 = 2052;
        ui->bg02->setGeometry(x2,0,1026,590);
    }
    else
    {
    x2 = ui->bg02->geometry().x();
    ui->bg02->setGeometry(x2-3,0,1026,590);
    }

    if(x3 <= -1026)
    {
        x3 = 2052;
        ui->bg03->setGeometry(x3,0,1026,590);
    }
    else
    {
    x3 = ui->bg03->geometry().x();
    ui->bg03->setGeometry(x3-3,0,1026,590);
    }
}

void picflowEvent()
{

}

void TV_view::initForm()
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

    setBtnQss(ui->openbutton, "#34495E", "#FFFFFF", "#4E6D8C", "#F0F0F0", "#2D3E50", "#B8C6D1");
    //setBtnQss(ui->openbutton, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    setBtnQss(ui->deletebutton, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    setBtnQss(ui->adminbutton, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");

    //setTxtQss(ui->lineEdit_account, "#DCE4EC", "#34495E");
    //setTxtQss(ui->lineEdit_password, "#DCE4EC", "#1ABC9C");
    //setTxtQss(ui->txt3, "#DCE4EC", "#3498DB");
    //setTxtQss(ui->lineEdit_password, "#DCE4EC", "#E74C3C");

    //setBarQss(ui->bar1, "#E8EDF2", "#E74C3C");
    //setBarQss(ui->bar2, "#E8EDF2", "#1ABC9C");

    //setSliderQss(ui->slider1, "#E8EDF2", "#1ABC9C", "#1ABC9C");
    //setSliderQss(ui->slider2, "#E8EDF2", "#E74C3C", "#E74C3C");
    //setSliderQss(ui->slider1, "#E8EDF2", "#34495E", "#1ABC9C");
    //setSliderQss(ui->slider2, "#E8EDF2", "#3498DB", "#E74C3C");
}

void TV_view::setBtnQss(QPushButton *btn,
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

void TV_view::setTxtQss(QLineEdit *txt, QString normalColor, QString focusColor)
{
    QStringList qss;
    qss.append(QString("QLineEdit{border-style:none;padding:6px;border-radius:5px;border:2px solid %1;}").arg(normalColor));
    qss.append(QString("QLineEdit:focus{border:2px solid %1;}").arg(focusColor));
    txt->setStyleSheet(qss.join(""));
}

void TV_view::setBarQss(QProgressBar *bar, QString normalColor, QString chunkColor)
{
    int barHeight = 8;
    int barRadius = 8;

    QStringList qss;
    qss.append(QString("QProgressBar{font:9pt;height:%2px;background:%1;border-radius:%3px;text-align:center;border:1px solid %1;}").arg(normalColor).arg(barHeight).arg(barRadius));
    qss.append(QString("QProgressBar:chunk{border-radius:%2px;background-color:%1;}").arg(chunkColor).arg(barRadius));
    //bar->setStyleSheet(qss.join(""));
}

void TV_view::setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor)
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

void TV_view::openVideo()
{
    VideoPlayer *player = new VideoPlayer(0,&usernow);
    player->resize(800,500);
    player->show();
    //filelocation = player->refilename;
    //filmtemp.setTitle(filelocation);


}

void TV_view::fresh()
{
    std::ifstream ifile("Films.txt",std::ios::in);
    if(!ifile)
    {
       //qDebug()<<"Open file failed!";
    }
    char ch;
    int i;
    int sizess=0;
    string lots[100];
    for(int i = 0; i < 100;++i)
    {
        string location;
        if(!ifile.get(ch))
        {
                 qDebug()<<"文件已读取完毕！";
                 break;
        }
        while(ch != '@')
        {
            location += ch;
            ifile.get(ch);
        }
        while(ch == '@')
        {
            ifile.get(ch);
            continue;
        }
        lots[sizess] = location;
        sizess++;
        if(!ifile.get(ch))
        {
                  qDebug()<<"File has been loaded.";
                  break;//continue;
        }

    }

    for(int i = 0;i < sizess; i++)
    {
        if(i/2*2 == i)
        {
            user_film[i/2][0] = lots[i];
        }
        else
        {
            user_film[i/2][1] = lots[i];
        }
    qDebug() << QString::fromStdString(lots[i]) << "   ";
    }

    for(int j = 0;j < sizess/2; j++)
    {
        list_model->setItem(j, 0, new QStandardItem(QString::fromStdString(user_film[j][1])));
        list_model->setItem(j, 1, new QStandardItem(QString::fromStdString(user_film[j][0])));
    }
    ui->tableView->setModel(list_model);
    ui->tableView->setColumnWidth(0,100);
    ui->tableView->setColumnWidth(1,100);

    qDebug() << sizess;
}

void TV_view::filmOfUser()
{
    char ch;
    bool fExist = 0;
    int numOfFilm = 0;
    std::ofstream ofile("ftemp.txt",std::ios::out);
        if(!ofile)
        {
            qDebug()<<"Open ftemp failed!";
        }
    std::ifstream ifile("Films.txt",std::ios::in);
        if(!ifile)
        {
            qDebug()<<"Open file failed!";
        }
        for (int i=0;i<100;i++)//读取数目
        {
            std::string s_name,s_id;
            bool b_isdeleted;
            bool flag;
            int count = 0;
            if(!ifile.get(ch))
            {
                 //qDebug()<<"文件已读取完毕！";
                 break;
            }
            //qDebug()<<count;
            while (ch!='@'&&(count%4!=0||count==0))//读取路径
            {
                s_name+=ch;
                ifile.get(ch);
            }
            count++;
            //qDebug()<<count;
            ifile.get(ch);
            while (ch!='@'&&(count%4!=0||count==0))//
            {
                if(ch == '0')
                {
                    b_isdeleted=false;
                }
                else
                {
                    b_isdeleted = true;
                }
                ifile.get(ch);

            }
            count++;
            //qDebug()<<count;
            ifile.get(ch);
            while(ch!='@'&&(count%4!=0||count==0))//
            {
                 s_id+=ch;
                 ifile.get(ch);
            }
            count++;
            //qDebug()<<count;
            //qDebug()<<ch;

            while(ch=='@'&&count==3)//读取
            {
                //qDebug()<<"OK";

                 ifile.get(ch);
                 count++;
                 if(ch == '0')
                 {
                    flag=false;
                 }
                 else
                 {
                    flag=true;
                 }
                 //qDebug()<<flag;
                 if(!ifile.get(ch))
                 {
                     //qDebug()<<"File has been loaded.";
                     break;//continue;
                 }
            }

            /*Film temp;
            temp.setTitle(s_name);
            QString temp1 = QString::fromStdString(s_id);
            temp.setUploaderstr(s_id);
            temp.set_deleted(b_isdeleted);
            temp.set_free(flag);
            qDebug()<< QString::fromStdString(temp.getTitle()) <<" " <<QString::fromStdString(temp.getUploaderstr());*/
            //lst.push_back(temp);
            if(s_id == usernow.getName())
            {
                ofile  << s_name << "@";
                fExist = 1;
                numOfFilm++;
            }
            if(fExist)
            {
                std::ifstream ifile("ftemp.txt",std::ios::in);
                    if(!ifile)
                    {
                        //qDebug()<<"Open file failed!";
                    }
                    char ch;
                    int i;
                    for (i=0;i<100;i++)//读取数目
                    {
                        std::string s_id;
                        if(!ifile.get(ch))
                        {
                             //qDebug()<<"文件已读取完毕！";
                             break;
                        }
                        qDebug()<<count;
                        while (ch!='@')//读取路径
                        {
                            s_id+=ch;
                            ifile.get(ch);
                        }
                        //在此处列出电影!!!!!!!!!!!!


                  }
            }
      }

}

void TV_view::open()
{


    int row= ui->tableView->currentIndex().row();

    QAbstractItemModel *model = ui->tableView->model ();

    QModelIndex index = model->index(row,1);//选中行第一列的内容

    QVariant data = model->data(index);

}
