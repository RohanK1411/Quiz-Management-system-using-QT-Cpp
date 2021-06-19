#include "delete_user.h"
#include "ui_delete_user.h"
#include "login_ui.h"
#include "admin_menu.h"

Delete_user::Delete_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete_user)
{
    ui->setupUi(this);
}

Delete_user::~Delete_user()
{
    delete ui;
}

void Delete_user::on_delete_2_clicked()
{
    Login_UI conn;
    QString username1;

    username1 = ui->username->text();

    if(conn.connOpen())
    {
        QSqlQuery qry;
        qry.prepare("Delete from student where username='"+username1+"'");
        if(qry.exec())
        {
            QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
            conn.connClose();
        }
        else
        {
            QMessageBox::critical(this,tr("Delete"),tr("Username is Not Exist."));
        }
    }
    else
    {
        QMessageBox::critical(this,"Delete","Database is Not Connected.");
    }
}


void Delete_user::on_back_clicked()
{
    Admin_Menu admin;
    close();
    admin.setModal(true);
    admin.exec();
}

