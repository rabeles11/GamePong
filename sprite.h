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
    void draw(QPainter &painter);           ///< Draw slot that allow us to draw new Sprites
protected:
    QWidget *parent = NULL;
    int x = 0;                          ///< X position of Sprite on screen
    int y = 0;                          ///< Y position of Sprite on screen
    float kx = 1;                       ///< Kx bump of the Sprite on screen
    float ky = 1;                       ///< Ky bump of the Sprite on screen

    virtual void timerEvent(QTimerEvent *);     ///TimerEvent that control tick of timer
};

typedef std::shared_ptr<Sprite> SpritePtr;      ///< Shared pointer type of pointer

#endif // SPRITE_H
