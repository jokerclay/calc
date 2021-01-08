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

    // Declare a constructor and by passing 0 we state this widget
    // has no parent
    explicit Calc(QWidget *parent = 0);
    ~Calc();

private:
    Ui::Calc *ui;

    // These slots are executed when a signal is
    // submitted (Ex. Number button is clicked)
private slots :
    void NumPressed();
    void MathButtonPressed();
    void EqualButtonPressed();
    void ChangeNumberSign();
};

#endif // CALC_H

