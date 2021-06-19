#include "view_question.h"
#include "ui_view_question.h"

view_question::view_question(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::view_question)
{
    ui->setupUi(this);

}

view_question::~view_question()
{
    delete ui;
}

void view_question::get_info(string que,string op1,string op2,string op3,string op4,string ans)
{
    this->question= QString::fromStdString(que);
    this->o1= QString::fromStdString(op1);
    this->o2= QString::fromStdString(op2);
    this->o3= QString::fromStdString(op3);
    this->o4= QString::fromStdString(op4);
    this->answer= QString::fromStdString(ans);
}
void view_question::on_pushButton_clicked()
{
    ui->Question_2->setPlainText(question);
    ui->op1_2->setPlainText(o1);
    ui->op2_2->setPlainText(o2);
    ui->op3_2->setPlainText(o3);
    ui->op4->setPlainText(o4);
    ui->op4_2->setPlainText(answer);

    //QLabel *label = new QLabel(question);
    //label->show();
    //hide();
}


void view_question::on_pushButton_2_clicked()
{
    close();
}

