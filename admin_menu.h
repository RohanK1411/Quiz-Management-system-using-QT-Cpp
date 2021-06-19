#ifndef ADMIN_MENU_H
#define ADMIN_MENU_H

#include <QDialog>
#include <iostream>
#include <fstream>
#include "view_question.h"

using namespace std;

namespace Ui {
class Admin_Menu;
}

class Admin_Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Menu(QWidget *parent = nullptr);
    ~Admin_Menu();
    string decryption(string temp);

private slots:

    void on_set_question_clicked();

    void on_view_qestion_clicked();

    void on_Show_database_clicked();

    void on_delete_2_clicked();

    void on_back_clicked();

private:
    Ui::Admin_Menu *ui;
};

#endif // ADMIN_MENU_H
