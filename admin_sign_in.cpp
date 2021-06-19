#include "admin_sign_in.h"
#include "ui_admin_sign_in.h"
#include "admin_menu.h"
#include <QMessageBox>
#include "mainwindow.h"

admin_sign_in::admin_sign_in(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_sign_in)
{
    ui->setupUi(this);
}

admin_sign_in::~admin_sign_in()
{
    delete ui;
}

void admin_sign_in::on_pushButton_clicked()
{
    QString username,password;
    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(username=="Admin" && password=="Admin")
    {
        Admin_Menu menu;
        close();
        menu.setModal(true);
        menu.exec();
    }
    else
    {
        QMessageBox::information(this,"ALERT","INVALID USERNAME OR PASSWORD.");
    }
}


void admin_sign_in::on_back_clicked()
{
    this->hide();
    MainWindow *w = new MainWindow();
    w->show();
}

