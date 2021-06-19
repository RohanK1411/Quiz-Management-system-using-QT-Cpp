#ifndef SET_QUESTION_H
#define SET_QUESTION_H

#include <QDialog>
#include <iostream>
#include <fstream>
#include <QApplication>
#include <QFile>
#include <QTextStream>

using namespace std;

namespace Ui {
class Set_question;
}

class Set_question : public QDialog
{
    Q_OBJECT

public:
    explicit Set_question(QWidget *parent = nullptr);
    ~Set_question();
    string encryption(string temp);
    string decryption(string temp);


private slots:
    void on_pushButton_clicked();

private:
    Ui::Set_question *ui;
    int b=0;
};

#endif // SET_QUESTION_H
