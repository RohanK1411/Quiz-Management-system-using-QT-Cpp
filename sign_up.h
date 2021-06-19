#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDialog>

using namespace std;

namespace Ui {
class sign_up;
}

class sign_up : public QDialog
{
    Q_OBJECT

public:
    explicit sign_up(QWidget *parent = nullptr);
    ~sign_up();

private slots:
    void on_sign_up_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::sign_up *ui;
    QString fname,lname,uname,adress,contact,password;
};

#endif // SIGN_UP_H
