#ifndef PADDLE_H
#define PADDLE_H

#include <QTimer>
#include <QWidget>
#include <QPainter>
#include "QObject"
#include <memory>


class Paddle : public QTimer{
    Q_OBJECT
public:
    Paddle(QWidget *p);
    int x = 350;                                    ///< X position of Paddle on screen
    int y = 550;                                    ///< Y position of Paddle on screen
    int width = 75;                                 ///< Width of Paddle on screen
    int height = 15;                                ///< Height of Paddle on screen

public slots:
    void draw(QPainter &painter);                   ///< Slot that allow us to draw new paddle on Screen
    void RedrawLeft();                              ///< Slot that allow us to redraw paddle when key is pressed
    void RedrawRight();                             ///< Slot that allow us to redraw paddle when key is pressed
protected:
    QWidget *parent = NULL;
    //float kx = 1;
    //float ky = 1;

};


#endif // PADDLE_H
