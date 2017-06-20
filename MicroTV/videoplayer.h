#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QMediaPlayer>
#include <QMovie>
#include <QWidget>
#include <fstream>
#include "film.h"
#include "User.h"
#include "Administrator.h"

QT_BEGIN_NAMESPACE
class QAbstractButton;
class QSlider;
QT_END_NAMESPACE

class VideoPlayer : public QWidget
{
    Q_OBJECT

public:
    VideoPlayer(QWidget *parent = 0, User *u = new User);
    ~VideoPlayer();
    std::string refilename;
    Film filmtemp;
    User usernow;

public slots:
    void openFile();
    void play();

private slots:
    void mediaStateChanged(QMediaPlayer::State state);
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void setPosition(int position);

private:
    QMediaPlayer mediaPlayer;
    QAbstractButton *playButton;
    QSlider *positionSlider;
};

#endif // VIDEOPLAYER_H
