#ifndef SHOW_USER_QUESTION_H
#define SHOW_USER_QUESTION_H

#include <QDialog>
#include <iostream>
#include <QString>
#include <string>
#include <string.h>
using namespace std;

namespace Ui {
class Show_user_question;
}

class Show_user_question : public QDialog
{
    Q_OBJECT

public:
    explicit Show_user_question(QWidget *parent = nullptr);
    ~Show_user_question();
    QString question,o1,o2,o3,o4,answer;
    void get_info(string que,string op1,string op2,string op3,string op4);
    QString get_ans();
    QString u_ans;



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

    Ui::Show_user_question *ui;
};

#endif // SHOW_USER_QUESTION_H
