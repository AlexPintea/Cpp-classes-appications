#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  ui->input1->setReadOnly(true);
  ui->output->setReadOnly(true);
}

MainWindow::~MainWindow()
{
  delete ui;
}




int a, b, rez, z1, z2;
char c;

void MainWindow::on_B_1_clicked()
{  //ui->B_1->setShortcut(QKeySequence(Qt::Key_1));
    a=ui->input1->text().toDouble();
    a=a*10+1;
    ui->input1->setText(QString::number(a));
    //ui->B_1->setIcon(QIcon("../Images/Button.png"));

}

void MainWindow::on_B_2_clicked()
{  //ui->B_2->setShortcut(QKeySequence(Qt::Key_2));
   a=ui->input1->text().toDouble();
   a=a*10+2;
   ui->input1->setText(QString::number(a));
}

void MainWindow::on_B_3_clicked()
{  //ui->B_3->setShortcut(QKeySequence(Qt::Key_3));
   a=ui->input1->text().toDouble();
   a=a*10+3;
   ui->input1->setText(QString::number(a));
}

void MainWindow::on_B_4_clicked()
{  //ui->B_4->setShortcut(QKeySequence(Qt::Key_4));
   a=ui->input1->text().toDouble();
   a=a*10+4;
   ui->input1->setText(QString::number(a));
}

void MainWindow::on_B_5_clicked()
{  //ui->B_5->setShortcut(QKeySequence(Qt::Key_5));
   a=ui->input1->text().toDouble();
   a=a*10+5;
   ui->input1->setText(QString::number(a));
}

void MainWindow::on_B_6_clicked()
{  //ui->B_6->setShortcut(QKeySequence(Qt::Key_6));
   a=ui->input1->text().toDouble();
   a=a*10+6;
   ui->input1->setText(QString::number(a));
}

void MainWindow::on_B_7_clicked()
{  //ui->B_7->setShortcut(QKeySequence(Qt::Key_7));
   a=ui->input1->text().toDouble();
   a=a*10+7;
   ui->input1->setText(QString::number(a));
}

void MainWindow::on_B_8_clicked()
{  //ui->B_8->setShortcut(QKeySequence(Qt::Key_8));
   a=ui->input1->text().toDouble();
   a=a*10+8;
   ui->input1->setText(QString::number(a));
}

void MainWindow::on_B_9_clicked()
{  //ui->B_9->setShortcut(QKeySequence(Qt::Key_9));
   a=ui->input1->text().toDouble();
   a=a*10+9;
   ui->input1->setText(QString::number(a));
}

void MainWindow::on_B_0_clicked()
{  //ui->B_0->setShortcut(QKeySequence(Qt::Key_0));
   a=ui->input1->text().toDouble();
   a=a*10;
   ui->input1->setText(QString::number(a));
}

void MainWindow::on_pushButton_Plus_clicked()
{  //ui->pushButton_Plus->setShortcut(QKeySequence(Qt::Key_Plus));
   ui->input1->setText("+");
   c='+';
   b=a;
   a=0;
}

void MainWindow::on_pushButton_Minus_clicked()
{  //ui->pushButton_Minus->setShortcut(QKeySequence(Qt::Key_Minus));
   ui->input1->setText("-");
   c='-';
   b=a;
   a=0;
}

void MainWindow::on_pushButton_Multiply_clicked()
{  //ui->pushButton_Multiply->setShortcut(QKeySequence(Qt::Key_multiply));
   ui->input1->setText("x");
   c='x';
   b=a;
   a=0;
}

void MainWindow::on_pushButton_Divide_clicked()
{ //ui->pushButton_Divide->setShortcut(QKeySequence(Qt::Key_division));
  ui->input1->setText("%");
  c='%';
  b=a;
  a=0;
}

int module(int a){
 if (a>=0){
     return a;
   }
 else {
     return -a;
   }
}

/// Not cutting the digit
void cut_digit (double a){
 int count, aint, i;
 count=0;
 while (a!=int(a)){
      a=a*10;
      count=count+1;
   }
 aint=a;
 aint=aint/10;
 for (i=1;i<count;i=i+1){
 a=aint/10;
 }
}
/// Not cutting the digit


void MainWindow::on_pushButton_Clear_clicked()
{ //ui->pushButton_Plus->setShortcut(QKeySequence(Qt::Key_Backspace));
  //ui->pushButton_Plus->setShortcut(QKeySequence(Qt::Key_Delete));
  //a=0;
  //b=0;
  //ui->input1->setText(QString::number(0));
  ///char d[100];
  //if (module(a)>=0){

  //d=char(a);
  //a=strlen(d);
 // d[a]='0';
  //a=int(d);
  ///cut_digit(a);
  //a=int(a);
  a=a/10;
  ui->input1->setText(QString::number(a));
  //}
}


void MainWindow::on_pushButton_Enter_clicked()
{   //ui->pushButton_Enter->setShortcut(QKeySequence(Qt::Key_Enter));
    //ui->pushButton_Enter->setShortcut(QKeySequence(Qt::Key_Equal));
  int verif, q;
  verif=0;
  q=0;
  if (c=='+'){
        rez=a+b;
      }
    if (c=='-'){
        rez=b-a;
      }
    if (c=='x'){
        rez=a*b;
      }
    if (c=='%'){
        if (a==0){
            verif=1;
          }
        else {
        rez=b/a;
        q=b%a;
          }
      }
    if (verif==0){
        if (q!=0){
    ui->output->setText(QString::number(rez)+" reminder="+QString::number(q));
          } else {
    ui->output->setText(QString::number(rez));
          }
    a=rez;
      }
    else {
    ui->output->setText("Impossible");
      }
    verif=0;
}


void MainWindow::on_pushButton_Clear_Everything_clicked()
{
     a=0;
     b=0;
     c=' ';
     ui->input1->setText(QString::number(0));
     ui->output->setText(QString::number(0));
}

void MainWindow::on_pushButton_Pi_clicked()
{
    a=3.1415926535;
    ui->input1->setText(QString::number(3.1415926535));
}

void MainWindow::on_pushButton_e_clicked()
{
    a=2.71828;
    ui->input1->setText(QString::number(2.71828));
}


