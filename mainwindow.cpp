#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "WET1.h"
#include "wedxt1.h"
#include "QHBoxLayout"
#include <QDebug>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    mwedxt1 = new WEDXT1(this);
    mwidget1 = new WET1(mwedxt1);

    QHBoxLayout *mainlayout = new QHBoxLayout(this);
    mainlayout->addWidget(mwedxt1);
    mainlayout->addWidget(mwidget1);
    setLayout(mainlayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}




