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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow * getMainWinPtr();

    Paddle *p;

    void IncreaseScore();

    void DecreaseScore();
    QTimer *timer;

signals:
    void draw(QPainter &painter);

private slots:
    void on_actionQuitGame_triggered();

    void on_actionStartGame_triggered();

    void myfunction();

    void keyPressEvent(QKeyEvent * event);

private:
    QList<SpritePtr> sprites;
    Ui::MainWindow *ui;
    //QTimer *timer;
    static MainWindow * pMainWindow;
    int score = 0;
    int timing = 5000;



protected:
    virtual void paintEvent(QPaintEvent *);
};
#endif // MAINWINDOW_H
