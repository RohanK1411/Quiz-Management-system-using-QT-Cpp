#include "number.h"
#include "ui_number.h"

Number::Number(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Number)
{
    ui->setupUi(this);
}

Number::~Number()
{
    delete ui;
}

int Number::Get_number()
{
    return number;
}

int Number::Get_point(){
    return point1;
}

void Number::on_pushButton_clicked()
{
    QString no;
    QString point;
    no = ui->Number_2->text();
    point = ui->point->text();

    number=no.toInt();
    point1=point.toInt();
    hide();
   // return s;
}

