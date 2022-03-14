#include "sprite.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "QDebug"
Sprite::Sprite(QWidget *p)
{
    parent = p;

    QRect rct = parent->rect();
    x = rand() % rct.width();
    y = 15;
    //y = rand() % rct.height();
    kx = rand() % 10;
    ky = rand() % 10;

    start(20);
}

void Sprite::draw(QPainter &painter)
{
    painter.drawEllipse(x, y, 15, 15);
}

void Sprite::timerEvent(QTimerEvent *)
{
    QRect rct = parent->rect();
    MainWindow * mw = MainWindow::getMainWinPtr();

    if (x>mw->p->x && x<mw->p->x+mw->p->width && y>=mw->p->y){
        this->deleteLater();
        mw->IncreaseScore();
        qDebug("Trefaaaaaaaaaa");
        qDebug() << mw->timer->interval();
    }
    else if(y>mw->p->y+mw->p->height){
        this->deleteLater();
        mw->DecreaseScore();
        qDebug("Misssssssssss");
    }

    if(x<0 || x>rct.width()) kx *= -1;
    //if(y<0 || y>rct.height()) ky *= -1;

    x += kx;
    y += ky;

    parent->update();
}
