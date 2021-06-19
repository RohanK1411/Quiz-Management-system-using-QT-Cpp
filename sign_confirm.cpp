#include "sign_confirm.h"
#include "ui_sign_confirm.h"
#include "mainwindow.h"
#include "login_ui.h"

sign_confirm::sign_confirm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_confirm)
{
    ui->setupUi(this);
}

sign_confirm::~sign_confirm()
{
    delete ui;
}

void sign_confirm::on_Home_clicked()
{
    this->close();
    MainWindow *w = new MainWindow();
    w->show();
}


void sign_confirm::on_pushButton_2_clicked()
{
    Login_UI login;
    close();
    login.setModal(true);
    login.exec();

}

