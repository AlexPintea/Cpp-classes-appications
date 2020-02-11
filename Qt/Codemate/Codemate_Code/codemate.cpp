#include "codemate.h"
#include "ui_codemate.h"

CodeMate::CodeMate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CodeMate)
{
    ui->setupUi(this);
    on_HtmlCombo_currentIndexChanged("body");
}

CodeMate::~CodeMate()
{
    delete ui;
}

void CodeMate::on_QtButton_clicked()
{

}

void CodeMate::on_QtButton_2_clicked()
{

}

void CodeMate::on_CloseButton_clicked()
{
    int i;
    for (i=1;i<=10;i=i+1){
        delete ui;
    }
}

void CodeMate::on_HtmlCombo_currentIndexChanged(const QString &arg1)
{
    if (arg1=="body"){
        ui->Description->setText(" Html has a head and a body. The body is visible.");
        ui->Code->setText(" &lt;body&gt; &lt;/body&gt;");
        ui->Precisations->setText("-");
        ui->Attributes->setText(" background-color= \n font-size= \n Este Bine>? ");
    }
}

void CodeMate::on_CssCombo_currentIndexChanged(const QString &arg1)
{
    if (arg1=="body"){
        ui->Description->setText(" Html has a head and a body. The body is visible.");
        ui->Code->setText(" &lt;body&gt; &lt;/body&gt;");
        ui->Precisations->setText("-");
        ui->Attributes->setText(" background-color: \n font-size: \n  ");
    }
}
