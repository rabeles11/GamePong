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
    int x = 350;
    int y = 550;
    int width = 75;
    int height = 15;

public slots:
    void draw(QPainter &painter);
    void RedrawLeft();
    void RedrawRight();
protected:
    QWidget *parent = NULL;
    //float kx = 1;
    //float ky = 1;

};


#endif // PADDLE_H
