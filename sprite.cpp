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
/**
 * This is function will draw our sprites
 *
 *
 * @param QPainter -> Expecting address of our object to draw
 */
void Sprite::draw(QPainter &painter)
{
    painter.drawEllipse(x, y, 15, 15);
}

/**
 * This function runs periodically and checks if the Sprites is out of our window
 * Or if the sprite hit our platfrom
 * Or if the sprite hit the edge of screen
 *
 * @param QTimerEvent * -> Tick of timer
 */

void Sprite::timerEvent(QTimerEvent *)
{
    QRect rct = parent->rect();
    MainWindow * mw = MainWindow::getMainWinPtr();

    if (x>mw->p->x && x<mw->p->x+mw->p->width && y>=mw->p->y){
        //mw->sprites.removeOne(this->);
        this->deleteLater();
        mw->IncreaseScore();
        qDebug("Trefaaaaaaaaaa");
        //mw->sprites.removeFirst();
        qDebug() << mw->timer->interval();
    }
    else if(y>mw->p->y+mw->p->height){
        this->deleteLater();
        mw->DecreaseScore();
        //mw->sprites.removeFirst();
        //mw->sprites.removeOne(this);
        qDebug("Misssssssssss");
    }

    if(x<0 || x>rct.width()) kx *= -1;
    //if(y<0 || y>rct.height()) ky *= -1;

    x += kx;
    y += ky;


    parent->update();
}
