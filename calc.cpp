#include "calc.h"
#include "ui_calc.h"

// 计算机的默认值
double calcVal = 0.0;

// 触发器
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

// 构造函数
Calc::Calc(QWidget *parent) :

    // 构造函数
    QMainWindow(parent),

    // 创建UI 类
    ui(new Ui::Calc)
{

    // 设置UI
    ui->setupUi(this);

    // 将 0.0  设为默认值 显示
    ui->Display->setText(QString::number(calcVal));

    // 创建 10 个按键数字
    QPushButton *numButtons[10];

    // 循环定位按钮
    for(int i = 0; i < 10; ++i){
        // 按键0-按键9 button0~button9
        QString butName = "Button" + QString::number(i);

        // 根据名字获取特定的 widget 并添加到数组
        numButtons[i] = Calc::findChild<QPushButton *>(butName);

        // 当按钮松开，调用数字被按下 函数
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPressed()));
    }

    // 将 release 信号与 槽函数 连接起来
    connect(ui->Add, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Subtract, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Multiply, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));
    connect(ui->Divide, SIGNAL(released()), this,
            SLOT(MathButtonPressed()));

    // 连接等于键
    connect(ui->Equals, SIGNAL(released()), this,
            SLOT(EqualButtonPressed()));

    // 连接改变符号键
    connect(ui->ChangeSign, SIGNAL(released()), this,
            SLOT(ChangeNumberSign()));


}
// ======================当数字键被按下========================
Calc::~Calc()
{
    delete ui;
}

void Calc::NumPressed(){

    QPushButton *button = (QPushButton *)sender();

    // 获取按键UI 上的值
    QString butVal = button->text();

    // 获取展示框中的值
    QString displayVal = ui->Display->text();
    // 如果展示框内是 0 或 0.0 , 就把按键的值显示出来
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){

        ui->Display->setText(butVal);

    } else {
        // 将新数放右边
        QString newVal = displayVal + butVal;

        // 数的 Double 型
        double dblNewVal = newVal.toDouble();

        // 最多显示16 个数字
        ui->Display->setText(QString::number(dblNewVal, 'g', 16));

    }
}
// ======================当运算符被按下========================
void Calc::MathButtonPressed(){

    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;

    // 获取存储在展示中当前的值
    QString displayVal = ui->Display->text();
    calcVal = displayVal.toDouble();


    QPushButton *button = (QPushButton *)sender();

    // 从按键上获取运算符
    QString butVal = button->text();

    if(QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divTrigger = true;
    } else if(QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        multTrigger = true;
    } else if(QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    } else {
        subTrigger = true;
    }

    // 清空展示框
    ui->Display->setText("");

}

// ======================当等于号被按下========================
void Calc::EqualButtonPressed(){

    // 将值恢复为0.0
    double solution = 0.0;

    // 获取展示框里的值
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();

    // 确认运算符按键被按下
    if(addTrigger || subTrigger || multTrigger || divTrigger ){
        if(addTrigger){
            solution = calcVal + dblDisplayVal;
        } else if(subTrigger){
            solution = calcVal - dblDisplayVal;
        } else if(multTrigger){
            solution = calcVal * dblDisplayVal;
        } else {
            solution = calcVal / dblDisplayVal;
        }
    }

    // 展示结果
    ui->Display->setText(QString::number(solution));

}

// ======================改变符号函数==========================
void Calc::ChangeNumberSign(){

    // 获取展示框里的值
    QString displayVal = ui->Display->text();

    // 正则表达式检查是否是一个数
    // 添加符号
    QRegExp reg("[-+]?[0-9.]*");

    // 如果是一个数字，改变他的符号
    if(reg.exactMatch(displayVal)){
        double dblDisplayVal = displayVal.toDouble();
        double dblDisplayValSign = -1 * dblDisplayVal;

        // 将结果展示出来
        ui->Display->setText(QString::number(dblDisplayValSign));
    }

}
