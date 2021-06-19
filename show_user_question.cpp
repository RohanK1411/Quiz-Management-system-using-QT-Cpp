#include "show_user_question.h"
#include "ui_show_user_question.h"

Show_user_question::Show_user_question(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show_user_question)
{
    ui->setupUi(this);
}

void Show_user_question::get_info(string que,string op1,string op2,string op3,string op4)
{
    this->question= QString::fromStdString(que);
    this->o1= QString::fromStdString(op1);
    this->o2= QString::fromStdString(op2);
    this->o3= QString::fromStdString(op3);
    this->o4= QString::fromStdString(op4);
}

Show_user_question::~Show_user_question()
{
    delete ui;
}

QString Show_user_question::get_ans(){

    return u_ans;
}

void Show_user_question::on_pushButton_clicked()
{
    ui->Question_2->setPlainText(question);
    ui->op1_2->setPlainText(o1);
    ui->op2_2->setPlainText(o2);
    ui->op3_2->setPlainText(o3);
    ui->op4->setPlainText(o4);

}


void Show_user_question::on_pushButton_2_clicked()
{
    u_ans = ui->lineEdit->text();
    //qDebug(qUtf8Printable(u_ans));
    close();
}

