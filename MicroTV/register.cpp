#include "register.h"
#include "ui_register.h"
#include <fstream>
#include <QDebug>


Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    connect(ui->vip_yes, SIGNAL(clicked(bool)), this, SLOT(isvip1()));
    connect(ui->vip_no, SIGNAL(clicked(bool)), this, SLOT(isvip2()));
    connect(ui->Button_register, SIGNAL(clicked(bool)), this, SLOT(registered()));
    this->initForm();
    //setTxtQss(ui->text_account, "#66FFCC", "#33CCCC");
    //QImage* img=new QImage;
    //img->load("D:/QTProject/MicroTV/4.png");
    //ui->bg->setPixmap(QPixmap::fromImage(*img));
}

Register::~Register()
{
    delete ui;
}


void Register::registered()
{
    QFont ft;
    ft.setPointSize(20);
    bool available = true;

    qDebug()<<"Registering";
    std::ifstream ifile("Users.txt", std::ios::in);
    std::ofstream ofile("Users.txt", std::ios::app);
    if(!ifile)
    {
        qDebug()<<"Open file failed";
    }

    std::string name = ui->text_account->text().toStdString();         //
    std::string passport = ui->text_password->text().toStdString();     //
    if(name == "" || passport == "")
    {
        QLabel *tips = new QLabel;
        //tips->resize(300,120);
        tips->setWindowTitle(QObject::tr("Incomplete info!"));
        tips->setText(QObject::tr("Please complete the information."));
        //tips->setAlignment(Qt::AlignHCenter);
        //tips->setAlignment(Qt::AlignVCenter);
        tips->setFont(ft);
        tips->show();
        available = false;
        this->close();
    }
    else if(passport.size() < 6)
    {
        QLabel *tips = new QLabel;
        //tips->resize(300,120);
        tips->setWindowTitle(QObject::tr("Short password!"));
        tips->setText(QObject::tr("Your password is less than 6. Try again."));
        //tips->setAlignment(Qt::AlignHCenter);
        //tips->setAlignment(Qt::AlignVCenter);
        tips->setFont(ft);
        tips->show();
        available = false;
        this->close();
    }

    if(available)
    {
    bool isvip;
    bool isExist = 0;
    char ch;
    for (int i=0;i<100;i++)//读取数目
       {
           std::string s_name,s_id,s_passpord;
           bool flag;
           int count = 0;
           if(!ifile.get(ch))
           {
                qDebug()<<"文件已读取完毕！";
                break;
           }
        while (ch!='@'&&(count%4!=0||count==0))//读取姓名
        {
            s_name+=ch;
            ifile.get(ch);
        }
        count++;
        ifile.get(ch);
        while (ch!='@'&&(count%4!=0||count==0))//读取密码
        {
            s_passpord+=ch;
            ifile.get(ch);

        }
        count++;
        ifile.get(ch);
        while(ch!='@'&&(count%4!=0||count==0))//读取ID
        {
             s_id+=ch;
             ifile.get(ch);
        }
        count++;
        while(ch=='@'&&count==3)//读取身份
        {

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
             if(!ifile.get(ch))
             {
                 qDebug()<<"File has been loaded.";
                 break;//continue;
             }
        }
        if(name==s_name)
        {
            isExist = 1;
            break;
        }
      }
    if(!isExist)
    {
        User user1;
        user1.setName(name);
        user1.setpassport(passport);
        user1.setVip(isvip);

        ofile  << user1.getName() << "@" << user1.getpassport() << "@" << user1.getID() << "@" << 1 << "@"  ;

        qDebug()<< "data has been inputted." <<QString::fromStdString(user1.getName()) << "@" << QString::fromStdString(user1.getpassport()) ;
    }
    else
    {
        QLabel *tips = new QLabel;
        //tips->resize(300,120);
        tips->setWindowTitle(QObject::tr("Repeated account!"));
        tips->setText(QObject::tr("Your account has been registered!"));
        //tips->setAlignment(Qt::AlignHCenter);
        //tips->setAlignment(Qt::AlignVCenter);
        tips->setFont(ft);
        tips->show();
        available = false;
        this->close();
    }

    this->close();
    }

}

void Register::isvip1()
{
    ui->vip_no->setChecked(Qt::Unchecked);
    vip = true;


}

void Register::isvip2()
{
    ui->vip_yes->setChecked(Qt::Unchecked);
    vip = false;
}

void Register::initForm()
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

    setBtnQss(ui->Button_register, "#34495E", "#FF3300", "#4E6D8C", "#FFFF33", "#2D3E50", "#CC9933");
    //setBtnQss(ui->openbutton, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    //setBtnQss(ui->deletebutton, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    //setBtnQss(ui->adminbutton, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");

    //setTxtQss(ui->lineEdit_account, "#DCE4EC", "#34495E");
    setTxtQss(ui->text_account, "#DCE4EC", "#1ABC9C");
    setTxtQss(ui->text_password, "#DCE4EC", "#3498DB");
    //setTxtQss(ui->lineEdit_password, "#DCE4EC", "#E74C3C");

    //setBarQss(ui->bar1, "#E8EDF2", "#E74C3C");
    //setBarQss(ui->bar2, "#E8EDF2", "#1ABC9C");

    //setSliderQss(ui->slider1, "#E8EDF2", "#1ABC9C", "#1ABC9C");
    //setSliderQss(ui->slider2, "#E8EDF2", "#E74C3C", "#E74C3C");
    //setSliderQss(ui->slider1, "#E8EDF2", "#34495E", "#1ABC9C");
    //setSliderQss(ui->slider2, "#E8EDF2", "#3498DB", "#E74C3C");
}

void Register::setBtnQss(QPushButton *btn,
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

void Register::setTxtQss(QLineEdit *txt, QString normalColor, QString focusColor)
{
    QStringList qss;
    qss.append(QString("QLineEdit{border-style:none;padding:6px;border-radius:5px;border:2px solid %1;}").arg(normalColor));
    qss.append(QString("QLineEdit:focus{border:2px solid %1;}").arg(focusColor));
    txt->setStyleSheet(qss.join(""));
}

void Register::setBarQss(QProgressBar *bar, QString normalColor, QString chunkColor)
{
    int barHeight = 8;
    int barRadius = 8;

    QStringList qss;
    qss.append(QString("QProgressBar{font:9pt;height:%2px;background:%1;border-radius:%3px;text-align:center;border:1px solid %1;}").arg(normalColor).arg(barHeight).arg(barRadius));
    qss.append(QString("QProgressBar:chunk{border-radius:%2px;background-color:%1;}").arg(chunkColor).arg(barRadius));
    //bar->setStyleSheet(qss.join(""));
}

void Register::setSliderQss(QSlider *slider, QString normalColor, QString grooveColor, QString handleColor)
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
