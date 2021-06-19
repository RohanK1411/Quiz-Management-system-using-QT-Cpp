#include "login_ui.h"
#include "ui_login_ui.h"
#include "menu.h"
#include "mainwindow.h"

Login_UI::Login_UI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_UI)
{
    ui->setupUi(this);
}

Login_UI::~Login_UI()
{
    delete ui;
}

void Login_UI::on_pushButton_clicked()
{

        if(connOpen())
        {
            username = ui->lineEdit_username->text();
            password = ui->lineEdit_password->text();
            //u1=username.toStdString();

            QSqlQuery qry;
            qry.prepare("select * from student where username='"+username+"' and password='"+password+"'");

            if(qry.exec()){
                int count=0;
                while(qry.next())
                {
                 count=1;
                }
                if(count==1){
                    Menu menu;
                    close();
                    menu.accept(username);
                    menu.setModal(true);
                    connClose();
                    menu.exec();
                }
                else{
                   QMessageBox::information(this,"Warning","Invalid username or Password");
                }

            }
        }else
        {
            QMessageBox::information(this,"Connection","Not Connected");
        }

        db.close();


}


void Login_UI::on_pushButton_2_clicked()
{
    this->hide();
    MainWindow *w = new MainWindow();
    w->show();
}

