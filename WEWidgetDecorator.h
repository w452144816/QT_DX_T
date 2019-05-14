#ifndef WEWIDGETDECORATOR_H
#define WEWIDGETDECORATOR_H

#include "QWidget"

class WEWidgetDecorator : public QWidget
{
    Q_OBJECT
public:
    explicit WEWidgetDecorator(QWidget *parent = nullptr);

    // QObject interface
    virtual bool eventFilter(QObject *watched, QEvent *event) override;
public slots:
    void sourceWidgetMoved();
    void sourceWidgetResized();
    void sourceWidgetShowed();
    void sourceWidgetHidden();
protected:
    //virtual bool eventFilter(QObject *obj, QEvent *event);
    virtual bool nativeEvent(const QByteArray &eventType, void *message, long *result);
protected:
    QWidget *mSourceWidget = nullptr;
};

#endif // WEWIDGETDECORATOR_H
