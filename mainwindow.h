#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class WET1;
class WEDXT1;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void moveSignal(QMoveEvent *event);
protected:
    void resizeEvent(QResizeEvent *event);
    void moveEvent(QMoveEvent *event);
private:
    Ui::MainWindow *ui;
    WET1 *mwidget1;
    WEDXT1 *mwedxt1;
};

#endif // MAINWINDOW_H
