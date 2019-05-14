#ifndef WEDXT1_H
#define WEDXT1_H

#include <QWidget>
#include <dx_t.h>
class WEDXT1 : public QWidget
{
    Q_OBJECT
public:
    explicit WEDXT1(QWidget *parent);

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void timeslots();
private:
    MSG msg;
};

#endif // WEDXT1_H
