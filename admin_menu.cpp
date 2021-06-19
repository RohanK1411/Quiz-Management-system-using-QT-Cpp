#include "admin_menu.h"
#include "ui_admin_menu.h"
#include "set_question.h"
#include "number.h"
#include <QString>
#include <stdio.h>
#include <QDebug>
#include <QtDebug>
#include <QtGlobal>
#include "show_database.h"
#include "delete_user.h"
#include "mainwindow.h"

Admin_Menu::Admin_Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_Menu)
{
    ui->setupUi(this);
}

Admin_Menu::~Admin_Menu()
{
    delete ui;
}

void Admin_Menu::on_set_question_clicked()
{

    remove("C:/Users/Rohan Katta/Documents/Files/myfile.dat");
    remove("C:/Users/Rohan Katta/Documents/Files/myans.dat");
    remove("C:/Users/Rohan Katta/Documents/Files/myque.dat");
    Number num;
    hide();
    num.exec();

    int n1 = num.Get_number();
    int n2 = num.Get_point();
    ofstream out;
    out.open("C:/Users/Rohan Katta/Documents/Files/myque.dat",ios::out|ios::app);
    out << n1 << endl;
    out << n2 << endl;
    out.close();
    for(int i=0;i<n1;i++)
    {
    Set_question ques;
    hide();
    ques.setModal(true);
    ques.exec();
    }
    Admin_Menu admin;
    admin.exec();
}

string Admin_Menu:: decryption(string temp)
{
    for(int i = 0; (temp[i] != '\0'); i++)
    temp[i] = temp[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value
    return temp;
}

void Admin_Menu::on_view_qestion_clicked()
{
    ifstream infile;
    ifstream inans;
    infile.open("C:/Users/Rohan Katta/Documents/Files/myfile.dat");
    inans.open("C:/Users/Rohan Katta/Documents/Files/myans.dat");

    string question,op1,op2,op3,op4,ans;

    ifstream out;
    out.open("C:/Users/Rohan Katta/Documents/Files/myque.dat");
    int n1;
    out >> n1;
    for(int i=0;i<n1;i++)
    {
        infile >> question;
        infile >> op1;
        infile >> op2;
        infile >> op3;
        infile >> op4;
        inans >> ans;
        view_question view;
        view.get_info(decryption(question),decryption(op1),decryption(op2),decryption(op3),decryption(op4),decryption(ans));
        hide();
        view.setModal(true);
        view.exec();

    }
    infile.close();
    inans.close();
    out.close();
    Admin_Menu admin;
    admin.exec();
}


void Admin_Menu::on_Show_database_clicked()
{
    Show_database show;
    close();
    show.setModal(true);
    show.exec();
}


void Admin_Menu::on_delete_2_clicked()
{
    Delete_user delete1;
    delete1.setModal(true);
    close();
    delete1.exec();

}


void Admin_Menu::on_back_clicked()
{
    this->hide();
    MainWindow *w = new MainWindow();
    w->show();
}

