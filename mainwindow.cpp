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

void MainWindow::on_actionQuitGame_triggered()
{
    this->close();
}

MainWindow *MainWindow::getMainWinPtr()
{
    return pMainWindow;
}



void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.fillRect(rect(), QBrush(QColor(Qt::white)));

    painter.setPen(Qt::black);
    painter.setBrush(QBrush(QColor(Qt::black)));

    emit draw(painter);

    p->draw(painter);
}

void MainWindow::on_actionStartGame_triggered()
{
    SpritePtr sprite = SpritePtr(new Sprite(this));
    sprites.append(sprite);

    connect(this, &MainWindow::draw, sprite.get(), &Sprite::draw);
    timer->start(timing);
}


void MainWindow::myfunction()
{
    SpritePtr sprite = SpritePtr(new Sprite(this));
    sprites.append(sprite);

    connect(this, &MainWindow::draw, sprite.get(), &Sprite::draw);
}

void MainWindow::IncreaseScore()
{
    if(timer > 0){
        timer->setInterval(timer->interval() - 1000);
    }
    score += 1;
    ui->label_Points->setText(QString::number(score));
}

void MainWindow::DecreaseScore()
{
    if(timer > 0){
        timer->setInterval(timer->interval() + 1000);
    }
    score -= 1;
    ui->label_Points->setText(QString::number(score));
}

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

