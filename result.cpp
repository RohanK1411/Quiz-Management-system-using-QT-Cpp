#include "result.h"
#include "ui_result.h"
#include <QString>
#include "menu.h"
#include "mainwindow.h"

Result::Result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Result)
{
    ui->setupUi(this);
}

Result::~Result()
{
    delete ui;
}

QString Result::accept(int count,int total1, QString temp)
{
    cou1 = count;
    total= total1;
    return temp;
}

void Result::on_result_clicked()
{

    QString cou2 = QString::number(cou1);
    ui->cou->setPlainText(cou2);
    QString total3 = QString::number(total);
    ui->total1->setPlainText(total3);
}


void Result::on_home_clicked()
{
    Menu menu;
    close();
    menu.setModal(true);
    menu.exec();

}


void Result::on_log_out_clicked()
{
    this->hide();
    MainWindow *w = new MainWindow();
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
}

