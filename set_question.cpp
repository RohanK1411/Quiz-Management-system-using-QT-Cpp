#include "set_question.h"
#include "ui_set_question.h"
#include <QString>
#include <stdio.h>
#include <QDebug>
#include <QtDebug>
#include <QtGlobal>



Set_question::Set_question(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Set_question)
{
    ui->setupUi(this);
}

Set_question::~Set_question()
{
    delete ui;
}

string Set_question::encryption(string temp)
{
    for(int i = 0;temp[i] != '\0'; i++)
    temp[i] = temp[i] + 2; //the key for encryption is 3 that is added to ASCII value
    return temp;

}

void Set_question::on_pushButton_clicked()
{
    QString Question = ui->Question_3->text();
    QString Option1 = ui->Option_5->text();
    QString Option2 = ui->Option_6->text();
    QString Option3 = ui->Option_7->text();
    QString Option4 = ui->Option_8->text();
    bool a=ui->Option_9->text().isEmpty();
    QString Answer = ui->Option_9->text();

    if (a==1)
    {
        close();
        Set_question set;
        set.setModal(true);
        set.exec();
    }

    ofstream myfile;
    ofstream myans;
    myfile.open("C:/Users/Rohan Katta/Documents/Files/myfile.dat",ios::out|ios::app);

        myfile << encryption(Question.toStdString()) << endl;
        myfile << encryption(Option1.toStdString()) << endl;
        myfile << encryption(Option2.toStdString()) << endl;
        myfile << encryption(Option3.toStdString()) << endl;
        myfile << encryption(Option4.toStdString()) << endl;
        myfile.close();
        myans.open("C:/Users/Rohan Katta/Documents/Files/myans.dat",ios::out|ios::app);
        myans << encryption(Answer.toStdString()) << endl;
        myfile.close();

    hide();
}

