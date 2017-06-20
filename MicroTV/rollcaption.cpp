#include "rollcaption.h"

#include <QPainter>

#include <qcoreevent.h>

RollCaption::RollCaption(QWidget *parent) :

QWidget(parent)

{

this->offset = 0;

this->myTimerId = 0;

this->myTimer = 50;

}

void RollCaption::setText(const QString &newText)

{

this->myText = newText;

this->update();

this->updateGeometry();

}

QSize RollCaption::sizeHint() const

{

return this->fontMetrics().size(0,text());

}

void RollCaption::paintEvent(QPaintEvent *)

{

QPainter painter(this);

QFont wordFont = this->font();

wordFont.setBold(false);

wordFont.setPixelSize(24);

wordFont.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));

this->setFont(wordFont);

int textWidth = fontMetrics().width(this->text());

if(textWidth < 1)

{

return;

}

int x= -this->offset;

while(x < width())

{

painter.drawText(x,0,textWidth,height(),

Qt::AlignLeft | Qt::AlignVCenter,text());

x += textWidth;

}

}

void RollCaption::showEvent(QShowEvent *)

{

this->myTimerId = startTimer(this->myTimer);

}

void RollCaption::timerEvent(QTimerEvent *event)

{

if (event->timerId() == this->myTimerId)

{

++this->offset;

if (this->offset >= this->fontMetrics().width(this->text())) {

this->offset = 0;

}

this->scroll(-1, 0);

}else

{

QWidget::timerEvent(event);

}

}

void RollCaption::hideEvent(QHideEvent * )

{

killTimer(myTimerId);

this->myTimerId = 0;

}

void RollCaption::setSpeed(int timer)

{

this->myTimer = timer;

}

void RollCaption::setcolor(QColor color)

{

palette.setColor(QPalette::WindowText,color);

setPalette(palette);

}
