#include "show_database.h"
#include "ui_show_database.h"
#include "login_ui.h"
#include <QDebug>
#include <QtGlobal>
#include "admin_menu.h"

Show_database::Show_database(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show_database)
{
    ui->setupUi(this);
}

Show_database::~Show_database()
{
    delete ui;
}

void Show_database::on_pushButton_clicked()
{
    Login_UI conn;

    if(conn.connOpen())
    {

       QSqlQueryModel * modal = new QSqlQueryModel();


       QSqlQuery* qry = new QSqlQuery(conn.db);
        qry->prepare("select * from student");
        qry->exec();
        modal->setQuery(*qry);

        modal->setHeaderData(0, Qt::Horizontal, "         User Name         ");
        modal->setHeaderData(1, Qt::Horizontal, "First Name");
        modal->setHeaderData(2, Qt::Horizontal, "Last Name");
        modal->setHeaderData(3, Qt::Horizontal, "Address");
        modal->setHeaderData(4, Qt::Horizontal, "Contact Number");
        modal->setHeaderData(5, Qt::Horizontal, "Password");
        modal->setHeaderData(6, Qt::Horizontal, "Marks");
        modal->setHeaderData(7, Qt::Horizontal, "Total");


        ui->tableView->setModel(modal);
        conn.connClose();
        qDebug() << (modal->rowCount());

    }
}


void Show_database::on_back_clicked()
{
    Admin_Menu admin;
    close();
    admin.setModal(true);
    admin.exec();
}

