#include "calc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // 运行计算器功能
    Calc w;
    w.show();

    return a.exec();
}
