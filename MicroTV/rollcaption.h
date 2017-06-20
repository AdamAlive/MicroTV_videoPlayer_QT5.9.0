#ifndef ROLLCAPTION_H

#define ROLLCAPTION_H

#include <QWidget>

class RollCaption : public QWidget

{

Q_OBJECT

Q_PROPERTY(QString text READ text WRITE setText)

public:

explicit RollCaption(QWidget *parent = 0);

void setText(const QString &newText);

QString text() const

{

return myText;

}

QSize sizeHint() const;

void setSpeed(const int timer = 50);

void setcolor(QColor);

protected:

void paintEvent(QPaintEvent *event);

void timerEvent(QTimerEvent *event);

void showEvent(QShowEvent *event);

void hideEvent(QHideEvent *event);

private:

QString myText;

int offset;

int myTimerId;

int myTimer;

QPalette palette;

};

#endif // ROLLCAPTION_H
