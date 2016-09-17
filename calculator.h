#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include<QPushButton>

//const int INIT = 0;
//const int DIGIT = 1;
//const int OPERA = 2;
//const int LEFT = 3;
//const int RIGHT = 4;


namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:

    void on_zero_released();
    void on_one_released();
    void on_two_released();
    void on_three_released();
    void on_four_released();
    void on_five_released();
    void on_six_released();
    void on_seven_released();
    void on_eight_released();
    void on_nine_released();

    //void on_dot_released();
    void on_add_released();
    void on_sub_released();
    void on_mul_released();
    void on_div_released();
    void on_equal_released();
    void on_decimal_released();


//    void on_leftParenthesis_released();
//    void on_rightParenthesis_released();
    void on_clear_released();
    void on_del_released();
//    void on_btnBack_released();
signals:
    void buttonClicked(int type);

private:
    Ui::Calculator *ui;
    //initialization


    void state_init();

    void calculate();
    void operators();

    //display the number on lineEdit
    void display(QString num);

    //transform the input to number
    void trans(QString key);

    //check it's the first or the second number waitiing for input,true for first,false for second
    bool state;

    //check if the equal is pressed
    bool equal_state;

    //check the state of present operation
    enum sign{ADD,SUB,MUL,DIV,NO}cur_sign;

    //store the value of the first input
    QString first;

    //store the value of the second input
    QString second;

    //store the value of result
    QString result;


};

#endif // CALCULATOR_H
