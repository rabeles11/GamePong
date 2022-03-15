#include "paddle.h"
#include "QMessageBox"
#include "mainwindow.h"
#include "QDebug"
Paddle::Paddle(QWidget *p)
{
    parent = p;

    QRect rct = parent->rect();

}
/**
 * This is function draw our Paddle
 *
 *
 * @param there is no parameters
 */
void Paddle::draw(QPainter &painter)
{
    painter.drawRect(x, y, width, height);
}

/**
 * This is function will move with our paddle to the left and redraw it on window
 *
 *
 * @param there is no parameters
 */

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

/**
 * This is function will move with our paddle to the right and redraw it on window
 *
 *
 * @param there is no parameters
 */

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
