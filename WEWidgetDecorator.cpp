#include "WEWidgetDecorator.h"
#include <QResizeEvent>
#include <QDebug>
#include <Windows.h>
#include <QApplication>
#include <QEvent>
WEWidgetDecorator::WEWidgetDecorator(QWidget *parent)
    : QWidget(parent)
    , mSourceWidget(parent)
{
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setFocusPolicy(Qt::NoFocus);
    setStyleSheet("QWidget{background:transparent;}");
    //setAttribute(Qt::WA_InputMethodEnabled,false );
    setBaseSize(parent->baseSize());
    mSourceWidget->installEventFilter(this);

//    connect(mSourceWidget,&PDNWidget::resized,this,&WEWidgetDecorator::sourceWidgetResized);
//    connect(mSourceWidget,&PDNWidget::moved,this,&WEWidgetDecorator::sourceWidgetMoved);
//    connect(mSourceWidget,&PDNWidget::showed,this,&WEWidgetDecorator::sourceWidgetShowed);
//    connect(mSourceWidget,&PDNWidget::hidden,this,&WEWidgetDecorator::sourceWidgetHidden);
    //connect(mSourceWidget,&PDWidget,this,&WEWidgetDecorator::sourceWidgetHidden);
}


void WEWidgetDecorator::sourceWidgetMoved()
{
    this->move(mSourceWidget->mapToGlobal(QPoint(0,0)));
}

void WEWidgetDecorator::sourceWidgetResized()
{
    this->resize(mSourceWidget->size());
    this->move(mSourceWidget->mapToGlobal(QPoint(0,0)));
}

void WEWidgetDecorator::sourceWidgetShowed()
{
    this->setVisible(true);
    this->move(mSourceWidget->mapToGlobal(QPoint(0,0)));
    this->resize(mSourceWidget->size());
}

void WEWidgetDecorator::sourceWidgetHidden()
{
    this->setVisible(false);
}

/*
bool WEWidgetDecorator::eventFilter(QObject *obj, QEvent *event)
{
    if(obj == mSourceWidget)
    {
        if(event->type() == QEvent::Resize)
        {
            QResizeEvent *rEvent = static_cast<QResizeEvent *>(event);
            if(rEvent)
            {
                this->resize(rEvent->size().width(),rEvent->size().height());

            }
        }
        else if(event->type() == QEvent::Move)
        {
            QMoveEvent *rEvent = static_cast<QMoveEvent *>(event);
            if(rEvent)
            {
                this->move(mSourceWidget->mapToGlobal(QPoint(0,0)));
                qDebug() << "mSourceWidget mapToGlobal:" << mSourceWidget->mapToGlobal(QPoint(0,0));
                //this->move(0,0);
            }
        }
        else if(event->type() == QEvent::Show)
        {
            QShowEvent *sEvent = static_cast<QShowEvent *>(event);
            if(sEvent)
            {
                this->move(mSourceWidget->mapToGlobal(QPoint(0,0)));
                qDebug() << "mSourceWidget mapToGlobal:" << mSourceWidget->mapToGlobal(QPoint(0,0));
                //this->move(0,0);
            }
        }
    }
    return PDWidget::eventFilter(obj,event);
}*/

bool WEWidgetDecorator::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    if (eventType == "windows_generic_MSG" || eventType == "windows_dispatcher_MSG") {
            MSG* msg = static_cast<MSG *>(message);
            switch (msg->message)
            {
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:
                {
                    if ((VK_F4 == msg->wParam) && (::GetKeyState(VK_MENU) & 0xF000))
                    {
                        qDebug() << "alt + f4";
                        qApp->quit();
                        return true;
                    }
                }
                break;
            default:
                break;
            }
        }
    return QWidget::nativeEvent(eventType, message, result);
}



bool WEWidgetDecorator::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == mSourceWidget)
    {
        if(event->type() == QEvent::Show)
        {
            sourceWidgetShowed();
        }
        else if(event->type() == QEvent::Move)
        {
            sourceWidgetMoved();
        }
        else if(event->type() == QEvent::Resize)
        {
            sourceWidgetResized();
        }
        else if(event->type() == QEvent::Hide)
        {
            sourceWidgetHidden();
        }
        else
        {
            return false;
        }
    }
    else
        return QWidget::eventFilter(watched, event);
}
