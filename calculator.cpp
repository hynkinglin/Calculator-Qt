#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    state_init();

    connect(ui->zero,SIGNAL(released),this,SLOT(on_zero_released()));
    connect(ui->one,SIGNAL(released),this,SLOT(on_one_released()));
    connect(ui->two,SIGNAL(released),this,SLOT(on_two_released()));
    connect(ui->three,SIGNAL(released),this,SLOT(on_three_released()));
    connect(ui->four,SIGNAL(released),this,SLOT(on_four_released()));
    connect(ui->five,SIGNAL(released),this,SLOT(on_five_released()));
    connect(ui->six,SIGNAL(released),this,SLOT(on_six_released()));
    connect(ui->seven,SIGNAL(released),this,SLOT(on_seven_released()));
    connect(ui->eight,SIGNAL(released),this,SLOT(on_eight_released()));
    connect(ui->nine,SIGNAL(released),this,SLOT(on_nine_released()));
    connect(ui->add,SIGNAL(released),this,SLOT(on_add_released()));
    connect(ui->div,SIGNAL(released),this,SLOT(on_div_released()));
    connect(ui->mul,SIGNAL(released),this,SLOT(on_mul_released()));
    connect(ui->equal,SIGNAL(released),this,SLOT(on_equal_released()));
    connect(ui->clear,SIGNAL(released),this,SLOT(on_clear_released()));
    connect(ui->del,SIGNAL(released),this,SLOT(on_del_released()));
    connect(ui->decimal,SIGNAL(released),this,SLOT(on_decimal_released()));
    /*
    connect(ui->leftParenthesis,SIGNAL(released),this,SLOT(on_leftParenthesis_released()));
    connect(ui->rightParenthesis,SIGNAL(released),this,SLOT(on_rightParenthesis_released()));*/

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::state_init()
{

    state = true;
    equal_state = false;
    cur_sign = NO;
    first = "0";
    second = "0";
    result = "0";
    ui->lineEdit->setText("0");
}


void Calculator::calculate()
{
    double firstNum = first.toDouble();
    double secondNum =second.toDouble();
    double resultNum = 0;
    bool error = false;
    if(cur_sign == ADD)
    {
        resultNum = firstNum + secondNum;
    }

    else if(cur_sign == SUB)
    {
        resultNum = firstNum - secondNum;
    }

    else if(cur_sign == MUL)
    {
        resultNum = firstNum * secondNum;
    }
    else if(cur_sign == DIV)
    {
        if (secondNum == 0)
        {
            error = true;
        }
        else
        {
            resultNum = (firstNum*1.00) / secondNum;
        }

    }
    if(!error)
    {
        result = QString::number(resultNum);
    }
    else
    {
        result = "ERROR";
    }
    display(result);
}

//display the number showing on the lineEdit
void Calculator::display(QString num)
{

    ui->lineEdit->setText(num);
}

//transform the key to value and display
void Calculator::trans(QString key)
{
    //if the equal has been pressed,start a new calculation
    if(equal_state == true)
    {
        state_init();
        equal_state = false;
    }

    //if the state is true,input the first number
    if(state == true)
    {
        //if press the DEL,shorten the first
        if(key == "del")
        {
            if(first == "" || first.length() == 1)
            {

                first = "0";
            }
            else
                first=first.mid(0,first.size()-1);

        }

        else if(key == ".")
        {
            first = first + ".";
        }

        else
        {
            if(first == "0")
            {
                first = key;
            }
            else
            {

                first = first + key;
            }



        }
        display(first);
    }

    //input the second number
    else
    {
        if(key == "del")
        {
            if(second == "" || second.length() == 1)
            {
                second = "0";
            }
            else
                second=second.mid(0,second.size()-1);
                

        }
        else
        {

            if(key == ".")
            {
                second = second + ".";
            }

            else
            {
                if(second == "0")
                {
                    second =key;
                }
                else
                {
                    second = second  + key;
                }

            }

        }
        display(second);
    }

}

//press the digit number
void Calculator::on_one_released()
{
    trans("1");
}
void Calculator::on_two_released()
{
    trans("2");
}
void Calculator::on_three_released()
{
    trans("3");
}
void Calculator::on_four_released()
{
    trans("4");
}
void Calculator::on_five_released()
{
    trans("5");
}
void Calculator::on_six_released()
{
    trans("6");
}
void Calculator::on_seven_released()
{
    trans("7");
}
void Calculator::on_eight_released()
{
    trans("8");
}
void Calculator::on_nine_released()
{
    trans("9");
}
void Calculator::on_zero_released()
{
    trans("0");
}


void Calculator::on_decimal_released()
{
    trans(".");
}

//press the clear
void Calculator::on_clear_released()
{
    ui->lineEdit->setText("0");
    state_init();
}

// a helper method when all operators call
void Calculator::operators()
{
    equal_state = false;//reset the equal state
    if(state == false)//continously click the operator
    {
        calculate();
        first = result;
        second = "0";
    }
    else
    {
        state = false;
    }
}

void Calculator::on_add_released()
{
    operators();
    cur_sign = ADD;//set the cur_sign to ADD
}

void Calculator::on_sub_released()
{
    operators();
    cur_sign = SUB;//set cur_sign to SUB
}


void Calculator::on_mul_released()
{
    operators();
    cur_sign = MUL;//set cur_sign to MUL
}

void Calculator::on_div_released()
{
    operators();
    cur_sign = DIV;//set cur_sign to DIV
}


void Calculator::on_equal_released()
{
    if(equal_state == true)//continously click equal
        first = result;
    calculate();
    equal_state = true;
    //cur_sign = NO;
}

void Calculator::on_del_released()
{
    trans("del");
}

//void Calculator::on_leftParenthesis_released()
//{
//    trans("(");
//}

//void Calculator::on_rightParenthesis_released()
//{
//    trans(")");
//}
