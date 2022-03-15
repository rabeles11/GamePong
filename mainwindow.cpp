#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include "paddle.h"

MainWindow * MainWindow::pMainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pMainWindow = this;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    p = new Paddle(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * This is function that quit game it just close the window with game
 *
 *
 * @param there is no parameters
 */
void MainWindow::on_actionQuitGame_triggered()
{
    this->close();
}

/**
 * This is function is getting Pointer to MainWindow that allow us to operate with UI elements from another windows
 *
 *
 * @param there is no parameters
 */
MainWindow *MainWindow::getMainWinPtr()
{
    return pMainWindow;
}


/**
 * This is function is painting our custom objects on window
 *
 *
 * @param QPaintEvent -> Basic input from original Function
 */
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), QBrush(QColor(Qt::white)));

    painter.setPen(Qt::black);
    painter.setBrush(QBrush(QColor(Qt::black)));

    emit draw(painter);

    p->draw(painter);
}

/**
 * This is function will launch our game it just create a new Sprite and start generating anothers after time.
 *
 *
 * @param No params
 */

void MainWindow::on_actionStartGame_triggered()
{
    SpritePtr sprite = SpritePtr(new Sprite(this));
    sprites.append(sprite);

    connect(this, &MainWindow::draw, sprite.get(), &Sprite::draw);
    timer->start(timing);
}

/**
 * This is function will just create new sprite and connect it on our draw function that just show our sprites on window.
 *
 *
 * @param No params
 */
void MainWindow::myfunction()
{
    SpritePtr sprite = SpritePtr(new Sprite(this));
    sprites.append(sprite);

    connect(this, &MainWindow::draw, sprite.get(), &Sprite::draw);
    qDebug() << QString::number(sprites.count());
}
/**
 * This is function will just increase our score and speed up the game.
 *
 *
 * @param No params
 */
void MainWindow::IncreaseScore()
{
    if(timer > 0){
        timer->setInterval(timer->interval() - 1000);
    }
    score += 1;
    ui->label_Points->setText(QString::number(score));
}

/**
 * This is function will just decrease our game and slow down the game.
 *
 *
 * @param No params
 */

void MainWindow::DecreaseScore()
{
    if(timer > 0){
        timer->setInterval(timer->interval() + 1000);
    }
    score -= 1;
    ui->label_Points->setText(QString::number(score));
}

/**
 * This is function is there to register key press and based on it it moves with paddle to the left or right
 *
 *
 * @param QkeyEvent * event -> Registred pressed key
 */


void MainWindow::keyPressEvent( QKeyEvent * event )
{
    if( event->key() == Qt::Key_A )
    {
        p->RedrawLeft();
        //qDebug() << "Mackam A";
    }
    else if( event->key() == Qt::Key_D)
    {
        p->RedrawRight();
        //qDebug() << "Mackam D";
    }
}

