#ifndef WET1_H
#define WET1_H

#include "WEWidgetDecorator.h"
#include <QProgressBar>
#include <QPushButton>
class QPixmap;

class WET1 : public WEWidgetDecorator
{
    Q_OBJECT
public:
    explicit WET1(QWidget *parent);

    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void slotVolumeSet(int val);

protected:
    void paintEvent(QPaintEvent *event);
private:
    QProgressBar *mProgressBar;

    QPushButton *mbtn1;
    QPushButton *mbtn2;
    QPushButton *mbtn3;
    double     mVolume;
};

#endif // WET1_H
