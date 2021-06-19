#include "sign_up.h"
#include "ui_sign_up.h"
#include "sign_confirm.h"
#include "mainwindow.h"

sign_up::sign_up(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign_up)
{
    ui->setupUi(this);
}

sign_up::~sign_up()
{
    delete ui;
}


void sign_up::on_sign_up_2_clicked()
{
    QSqlDatabase pq = QSqlDatabase::addDatabase("QSQLITE");
    pq.setDatabaseName("C:/Users/Rohan Katta/Downloads/DB/Mydb.sqlite");
    if(pq.open())
    {
        fname = ui->firstname->text();
        lname = ui->lastname->text();
        uname = ui->Username->text();
        password = ui->password->text();
        adress = ui->address->text();
        contact = ui->phone->text();

        QSqlQuery qry;
        qry.prepare("INSERT INTO student(firstname,lastname,username,address,phone,password) VALUES (?,?,?,?,?,?)");
        qry.addBindValue(fname);
        qry.addBindValue(lname);
        qry.addBindValue(uname);
        qry.addBindValue(adress);
        qry.addBindValue(contact);
        qry.addBindValue(password);

        if(qry.exec()){
            sign_confirm sign;
            close();
            sign.setModal(true);
            sign.exec();
        }
        else{
            QMessageBox::information(this,"Not Inserted","User Already Exist.");
        }

    }else
    {
        QMessageBox::information(this,"Connection","Not Connected");
    }
    pq.close();

}


void sign_up::on_pushButton_clicked()
{
    this->hide();
    MainWindow *w = new MainWindow();
    w->show();
}

