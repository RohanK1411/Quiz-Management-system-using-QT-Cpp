#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include <QDialog>
#include <QtSql>
#include <QtGlobal>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QString>
#include <iostream>
#include <string>
#include <string.h>
#include <QString>

using namespace std;

namespace Ui {
class Login_UI;
}

class Login_UI : public QDialog
{
    Q_OBJECT

public:
    explicit Login_UI(QWidget *parent = nullptr);
    ~Login_UI();
    QString username;
    QSqlDatabase db;
    void connClose()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("Your file location");
        if(db.open())
        {
            qDebug() <<("Connected Successfully.");
            return true;
        }
        else
        {
            qDebug() <<("Not Connected Successfully.");
            return false;
        }
    }



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Login_UI *ui;
    QString password;

};

#endif // LOGIN_UI_H
