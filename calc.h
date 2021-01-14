#ifndef CALC_H
#define CALC_H

#include <QMainWindow>

// 使用 .ui file
namespace Ui {
class Calc;
}

class Calc : public QMainWindow
{
    // 声明我们的类是以 Q_OBJECT 为基类
    Q_OBJECT

public:

    // widget 没有 parent
    explicit Calc(QWidget *parent = 0);
    ~Calc();

private:
    Ui::Calc *ui;

    // 当信号被提交时，槽会被执行
private slots :
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
};

#endif // CALC_H

