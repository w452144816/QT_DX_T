#include "WET1.h"
#include <QEvent>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPainter>
WET1::WET1(QWidget *parent)
    :WEWidgetDecorator(parent)
{
    mVolume = 20;
    mProgressBar = new QProgressBar(this);
    mProgressBar->setBaseSize(20, 0.3 * parent->height());
    mProgressBar->setRange(0,255);
    mProgressBar->setValue(mVolume);
    mProgressBar->setOrientation(Qt::Vertical);
    mProgressBar->setTextVisible(false);
    mProgressBar->setStyleSheet("QProgressBar{background-color: transparent;border: none solid grey;border-radius: 5px;text-align: center;}"
                                "QProgressBar::chunk{background-color: #40FFD4;border-radius:3px;height: 6px;margin: 1px;}");

    mbtn1 = new QPushButton(this);
    mbtn2 = new QPushButton(this);
    mbtn3 = new QPushButton(this);
    mbtn1->setText("1111");
    mbtn2->setText("2222");
    mbtn3->setText("3333");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(4);
    mainLayout->addStretch();

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->setSpacing(3);
    hLayout->addStretch();
    hLayout->addWidget(mProgressBar);
    hLayout->addWidget(mbtn1);
    hLayout->addWidget(mbtn2);
    hLayout->addWidget(mbtn3);
    mainLayout->addLayout(hLayout);
    setLayout(mainLayout);

    connect(mbtn1, SIGNAL(clicked(bool)), this, SLOT(slotBtn1Click()));
    connect(mbtn2, SIGNAL(clicked(bool)), this, SLOT(slotBtn2Click()));
}

void WET1::slotVolumeSet(int val)
{
    mVolume = val;
    mProgressBar->setValue(val);
    repaint();
}

void WET1::slotBtn1Click()
{
    mVolume+=10;
    slotVolumeSet(mVolume);
}

void WET1::slotBtn2Click()
{
    mVolume-=10;
    slotVolumeSet(mVolume);
}

void WET1::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
}


bool WET1::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == mSourceWidget)
    {
        if(event->type() == QEvent::Show)
        {
            //qDebug()<<"chongzhi";
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

