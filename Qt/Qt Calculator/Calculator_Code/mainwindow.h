#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void on_B_1_clicked();

  void on_B_2_clicked();

  void on_B_3_clicked();

  void on_B_4_clicked();

  void on_B_5_clicked();

  void on_B_6_clicked();

  void on_B_7_clicked();

  void on_B_8_clicked();

  void on_B_9_clicked();

  void on_B_0_clicked();

  void on_pushButton_Plus_clicked();

  void on_pushButton_Minus_clicked();

  void on_pushButton_Multiply_clicked();

  void on_pushButton_Divide_clicked();

  void on_pushButton_Clear_clicked();

  void on_pushButton_Enter_clicked();

  void on_pushButton_Clear_Everything_clicked();

  void on_pushButton_Pi_clicked();

  void on_pushButton_e_clicked();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
