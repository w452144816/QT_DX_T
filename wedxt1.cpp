#include "wedxt1.h"
#include <QDebug>
#include <QTimer>
WEDXT1::WEDXT1(QWidget *parent)
    :QWidget(parent)
{
    HWND hWnd = (HWND)this->winId();
    //初始化Direct3D
    if (SUCCEEDED(InitD3D(hWnd)))
    {
        //创建场景图形
        if (SUCCEEDED(InitGeometry()))
        {
            //显示窗口
            ShowWindow(hWnd, SW_SHOWDEFAULT);
            UpdateWindow(hWnd);


        }
    }
    QTimer *mtimer = new QTimer(this);
    mtimer->start();
    connect(mtimer, SIGNAL(timeout()),this, SLOT(timeslots()));

    connect(parent, SIGNAL(moveSignal(QMoveEvent*)),this,SLOT(moves(QMoveEvent*)));

}

void WEDXT1::resizeEvent(QResizeEvent *event)
{
    qDebug()<<"chongzhi";
}

void WEDXT1::moveEvent(QMoveEvent *event)
{
    qDebug()<<"wemove";
}

//void WEDXT1::paintEvent(QPaintEvent *event)
//{
//    qDebug() << "1";
//    QWidget::paintEvent(event);
//    setGeometry(0,0, 500, 400);
//    //进入消息循环

//    if (msg.message != WM_QUIT)
//    {
//        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
//        {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//        else
//        {
//            qDebug() << "2  ";
//            Render();  //渲染图形
//        }
//    }
//}

void WEDXT1::timeslots()
{
    ZeroMemory(&msg, sizeof(msg));
    Render();  //渲染图形
    //repaint();
}

void WEDXT1::moves(QMoveEvent *event)
{
    moveSignal(event);
}
