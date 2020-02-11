#include "codemate.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CodeMate w;
    w.show();

    return a.exec();
}
