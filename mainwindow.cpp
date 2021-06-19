#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login_ui.h"
#include "admin_menu.h"
#include "admin_sign_in.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    hide();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Sign_in_clicked()
{
    Login_UI login;
    close();
    login.setModal(true);
    login.exec();
}


void MainWindow::on_Sign_up_clicked()
{
    sign_up sign;
    close();
    sign.setModal(true);
    sign.exec();
}


void MainWindow::on_Admin_Sign_clicked()
{
    admin_sign_in admin;
    close();
    admin.setModal(true);
    admin.exec();
}

