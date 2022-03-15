#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QList"
#include "sprite.h"
#include "QTimer"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "paddle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);    ///< Null pointer to MW that let us change the objects from another window.
    ~MainWindow();
    static MainWindow * getMainWinPtr();      ///< Static pointer to function GetMainWinPtr that allows us control object from another window.

    Paddle *p;                                ///< Pointer to paddle class

    void IncreaseScore();                     ///< Header of Increase Score

    void DecreaseScore();                     ///< Header of Decrease score
    QTimer *timer;                            ///< Pointer to our timer
    QList<SpritePtr> sprites;                 ///< QList that store our sprites

signals:
    void draw(QPainter &painter);             ///< Signal draw that draws our object on window like paddle and sprite

private slots:
    void on_actionQuitGame_triggered();       ///< Slot to button QuitGame

    void on_actionStartGame_triggered();      ///< Slot to button StartGame

    void myfunction();                        ///< Slot for the timer to periodic generate sprites

    void keyPressEvent(QKeyEvent * event);    ///< Slot to register our keypress

private:
    //QList<SpritePtr> sprites;
    Ui::MainWindow *ui;
    //QTimer *timer;
    static MainWindow * pMainWindow;
    int score = 0;                           ///< Score counter
    int timing = 5000;                       ///< Timer speed



protected:
    virtual void paintEvent(QPaintEvent *);          ///< Override function that allow us to draw custom objects
};
#endif // MAINWINDOW_H
