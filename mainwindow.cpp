#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "WET1.h"
#include "wedxt1.h"
#include <QDebug>
#include <QPushButton>
#include <QEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1280,720);

    mwedxt1 = new WEDXT1(this);

    mwidget1 = new WET1(mwedxt1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    mwedxt1->resize(this->width(),this->height());
}

void MainWindow::moveEvent(QMoveEvent *event)
{
    mwedxt1->move(0,0);
    mwedxt1->setGeometry(0,0,this->width(),this->height());
    emit moveSignal(event);
}




