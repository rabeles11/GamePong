#include "paddle.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "QDebug"
Paddle::Paddle(QWidget *p)
{
    parent = p;

    QRect rct = parent->rect();

}

void Paddle::draw(QPainter &painter)
{
    painter.drawRect(x, y, width, height);
}


void Paddle::RedrawLeft()
{
    QRect rct = parent->rect();
    if(x-10 < rct.x()){
    }
    else {
       x -= 10;
    }
    parent->update();
}

void Paddle::RedrawRight()
{
    QRect rct = parent->rect();
    if(x+10 >= rct.width()-width){
    }
    else {
       x += 10;
    }
    parent->update();
}
