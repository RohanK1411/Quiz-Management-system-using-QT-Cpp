#ifndef SHOW_DATABASE_H
#define SHOW_DATABASE_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDialog>


namespace Ui {
class Show_database;
}

class Show_database : public QDialog
{
    Q_OBJECT

public:
    explicit Show_database(QWidget *parent = nullptr);
    ~Show_database();

private slots:
    void on_pushButton_clicked();


    void on_back_clicked();

private:

    Ui::Show_database *ui;
};

#endif // SHOW_DATABASE_H
