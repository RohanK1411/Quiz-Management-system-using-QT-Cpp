#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include <iostream>
#include <fstream>
#include <QtDebug>
#include <QtGlobal>
#include <string>
#include <string.h>
#include <stdio.h>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDialog>
#include <QString>

using namespace std;

namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    string decryption(string temp);
    QString accept(QString temp);


private slots:

    void on_Proceed_clicked();

    void on_Result_clicked();

    void on_back_clicked();

private:
    Ui::Menu *ui;
    int cou=0;
    QString user1;
    QString u2;
    int re=0;
    int total=0;

};

#endif // MENU_H
