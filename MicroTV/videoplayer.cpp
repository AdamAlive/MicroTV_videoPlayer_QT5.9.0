#include "videoplayer.h"

#include "videowidget.h"

#include <QtWidgets>
#include <qvideosurfaceformat.h>



VideoPlayer::VideoPlayer(QWidget *parent, User *u)
    : QWidget(parent)
    , mediaPlayer(0, QMediaPlayer::VideoSurface)
    , playButton(0)
    , positionSlider(0)
{
    usernow = *u;

    VideoWidget *videoWidget = new VideoWidget;

    QAbstractButton *openButton = new QPushButton(tr("Open"));
    connect(openButton, SIGNAL(clicked()), this, SLOT(openFile()));

    playButton = new QPushButton;
    playButton->setEnabled(false);
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    connect(playButton, SIGNAL(clicked()),
            this, SLOT(play()));

    positionSlider = new QSlider(Qt::Horizontal);
    positionSlider->setRange(0, 0);

    connect(positionSlider, SIGNAL(sliderMoved(int)),
            this, SLOT(setPosition(int)));

    QBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(openButton);
    controlLayout->addWidget(playButton);
    controlLayout->addWidget(positionSlider);

    QBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(videoWidget);
    layout->addLayout(controlLayout);

    setLayout(layout);

    mediaPlayer.setVideoOutput(videoWidget->videoSurface());
    connect(&mediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),
            this, SLOT(mediaStateChanged(QMediaPlayer::State)));
    connect(&mediaPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    connect(&mediaPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));
}

VideoPlayer::~VideoPlayer()
{
}

void VideoPlayer::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Movie"),QDir::homePath());

    if (!fileName.isEmpty()) {
        mediaPlayer.setMedia(QUrl::fromLocalFile(fileName));

        playButton->setEnabled(true);
        refilename = fileName.toStdString();

        std::ofstream outFilms("Films.txt", std::ios::app);

        if(!outFilms)
        {
            qDebug() << "can't open the file.";
        }

        outFilms  << refilename << "@" << filmtemp.is_deleted() << "@" << usernow.getName() << "@" << filmtemp.is_free()<< "@";


    }

    /*QFont ft;
    ft.setPointSize(20);
    bool available = true;

    std::ifstream ifile("Films.txt", std::ios::in);
    std::ofstream outFilms("Films.txt", std::ios::app);
    if(!ifile)
    {
        qDebug()<<"Open file failed";
    }


    std::string upzhu,name;
    bool isvip;
    bool isExist = 0;
    char ch;
    bool flag;
    bool flag2;
    for (int i=0;i<100;i++)//读取数目
       {
           std::string s_location,s_id,s_passpord;

           int count = 0;
           if(!ifile.get(ch))
           {
                qDebug()<<"文件已读取完毕！";
                break;
           }
        while (ch!='@'&&(count%4!=0||count==0))//读取姓名
        {
            s_location+=ch;
            ifile.get(ch);
        }
        count++;
        ifile.get(ch);
        while (ch!='@'&&(count%4!=0||count==0))//读取密码
        {
            s_passpord+=ch;
            ifile.get(ch);
            if(ch == '0')
            {
               flag=false;
            }
            else
            {
               flag=true;
            }
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
                flag2=false;
             }
             else
             {
                flag2=true;
             }
             if(!ifile.get(ch))
             {
                 qDebug()<<"File has been loaded.";
                 break;//continue;
             }
        }
        if(name==s_location)
        {
            isExist = 1;
            upzhu = s_id;
            break;
        }
      }
    if(!isExist)
    {
        Film filmTemp;
        filmTemp.setTitle(name);
        filmTemp.set_deleted(flag2);
        filmTemp.setUploaderstr(upzhu);

        outFilms  << refilename << "@" << filmtemp.is_deleted() << "@" << usernow.getName() << "@" << filmtemp.is_free()<< "@";

        //qDebug()<< "data has been inputted." <<QString::fromStdString(user1.getName()) << "@" << QString::fromStdString(user1.getpassport()) ;
    }
    else
    {

    }

    this->close();*/
    }

void VideoPlayer::play()
{
    switch(mediaPlayer.state()) {
    case QMediaPlayer::PlayingState:
        mediaPlayer.pause();
        break;
    default:
        mediaPlayer.play();
        break;
    }
}

void VideoPlayer::mediaStateChanged(QMediaPlayer::State state)
{
    switch(state) {
    case QMediaPlayer::PlayingState:
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    default:
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
}

void VideoPlayer::positionChanged(qint64 position)
{
    positionSlider->setValue(position);
}

void VideoPlayer::durationChanged(qint64 duration)
{
    positionSlider->setRange(0, duration);
}

void VideoPlayer::setPosition(int position)
{
    mediaPlayer.setPosition(position);
}
