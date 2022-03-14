#ifndef SPRITE_H
#define SPRITE_H

#include <QTimer>
#include <QWidget>
#include <QPainter>
#include "QObject"
#include <memory>

class Sprite : public QTimer
{
    Q_OBJECT

public:
    Sprite(QWidget *p);

public slots:
    void draw(QPainter &painter);
protected:
    QWidget *parent = NULL;
    int x = 0;
    int y = 0;
    float kx = 1;
    float ky = 1;

    virtual void timerEvent(QTimerEvent *);
};

typedef std::shared_ptr<Sprite> SpritePtr;

#endif // SPRITE_H
