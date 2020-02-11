#include "qtapp.h"
#include "ui_qtapp.h"

QtApp::QtApp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtApp)
{
    ui->setupUi(this);
}

QtApp::~QtApp()
{
    delete ui;
}

void QtApp::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

int Numbr=0;

void QtApp::on_MoreBtn_clicked()
{
    Numbr=Numbr+1;
///    ui->MoreBtn->setStyleSheet("background-color: #FBFBFB; border-radius: 14px;");
    ui->Numbr->setText(QString::number(Numbr));
}

void QtApp::on_LessBtn_clicked()
{
    Numbr=Numbr-1;
///    ui->LessBtn->setStyleSheet("background-color: #FBFBFB; border-radius: 14px;");
    ui->Numbr->setText(QString::number(Numbr));
}

void QtApp::on_MoreBtn_released()
{
///    ui->MoreBtn->setStyleSheet("background-color: gray; border-radius: 14px;");
}

void QtApp::on_LessBtn_released()
{
///    ui->LessBtn->setStyleSheet("background-color: gray; border-radius: 14px;");
}
