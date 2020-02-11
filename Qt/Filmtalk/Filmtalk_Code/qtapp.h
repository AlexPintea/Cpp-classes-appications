#ifndef QTAPP_H
#define QTAPP_H

#include "QtGui"
#include "QMainWindow"

namespace Ui {
class QtApp;
}

class QtApp : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtApp(QWidget *parent = 0);
    ~QtApp();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_MoreBtn_clicked();

    void on_LessBtn_clicked();

    void on_MoreBtn_released();

    void on_LessBtn_released();

private:
    Ui::QtApp *ui;
};

#endif // QTAPP_H
