#ifndef VIEW_QUESTION_H
#define VIEW_QUESTION_H

#include <QDialog>
#include <iostream>
#include <fstream>
#include <QString>
#include <QDebug>
#include <QtGlobal>
#include<QTextEdit>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QApplication>
#include <QLabel>

using namespace std;

namespace Ui {
class view_question;
}

class view_question : public QDialog
{
    Q_OBJECT

public:
    explicit view_question(QWidget *parent = nullptr);
    ~view_question();
    void  get_info(string que,string op1,string op2,string op3,string op4,string ans);

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    QString question,o1,o2,o3,o4,answer;

    Ui::view_question *ui;
};

#endif // VIEW_QUESTION_H
