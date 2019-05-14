#ifndef WEDXT1_H
#define WEDXT1_H

#include <QWidget>
#include <dx_t.h>
class WEDXT1 : public QWidget
{
    Q_OBJECT
public:
    explicit WEDXT1(QWidget *parent);

signals:
    void moveSignal(QMoveEvent *event);
protected:
    //void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    void moveEvent(QMoveEvent *event);
private slots:
    void timeslots();
    void moves(QMoveEvent *event);
private:
    MSG msg;
};

#endif // WEDXT1_H
