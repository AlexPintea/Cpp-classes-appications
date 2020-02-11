#ifndef CODEMATE_H
#define CODEMATE_H

#include <QMainWindow>

namespace Ui {
class CodeMate;
}

class CodeMate : public QMainWindow
{
    Q_OBJECT

public:
    explicit CodeMate(QWidget *parent = 0);
    ~CodeMate();

private slots:
    void on_QtButton_clicked();

    void on_QtButton_2_clicked();

    void on_CloseButton_clicked();

    void on_HtmlCombo_currentIndexChanged(const QString &arg1);

    void on_tabWidget_currentChanged(int index);

    void on_CssCombo_currentIndexChanged(const QString &arg1);

private:
    Ui::CodeMate *ui;
};

#endif // CODEMATE_H
