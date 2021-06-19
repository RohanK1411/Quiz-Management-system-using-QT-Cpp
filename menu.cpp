#include "menu.h"
#include "ui_menu.h"
#include "show_user_question.h"
#include "login_ui.h"
#include "result.h"
#include "mainwindow.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

QString Menu::accept(QString temp)
{
    user1=temp;
    return temp;

}

string Menu:: decryption(string temp)
{
    for(int i = 0; (temp[i] != '\0'); i++)
    temp[i] = temp[i] - 2; //the key for encryption is 3 that is subtracted to ASCII value
    return temp;
}

void Menu::on_Proceed_clicked()
{
    if(user1==u2)
    {
        re++;
    }
    re++;
    if(re==1)
    {
        Show_user_question user;
        ifstream infile;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/Rohan Katta/Downloads/DB/Mydb.sqlite");



        ifstream inans;

        infile.open("C:/Users/Rohan Katta/Documents/Files/myfile.dat");
        inans.open("C:/Users/Rohan Katta/Documents/Files/myans.dat");
        string data;
        string data1;
        string question,op1,op2,op3,op4,ans;
        QString User_ans;

        ifstream out;
        out.open("C:/Users/Rohan Katta/Documents/Files/myque.dat");
        int n1,n2;
        out >> n1;
        out >> n2;
        total = n1*n2;
        QString p;
         for(int i=0;i<n1;i++)
        {
             infile >> question;
             infile >> op1;
             infile >> op2;
             infile >> op3;
             infile >> op4;
            inans >> ans;
            Show_user_question view;
            view.get_info(decryption(question),decryption(op1),decryption(op2),decryption(op3),decryption(op4));
            hide();
            view.setModal(true);
            view.exec();
            p = QString::fromStdString(decryption(ans));
            User_ans=view.u_ans;

            if (p == User_ans)
            {
                cou = cou + n2;
            }
        }
        //qDebug(qUtf8Printable(user1));
        if(db.open()){
            QSqlQuery qry;
            qry.prepare("update student set Subject_1= :cou where username = :username");
            qry.bindValue(":cou",cou);
            qry.bindValue(":username",user1);
            if(qry.exec())
            {
                cout << "good";
            }
            qry.prepare("update student set Out_of= :mark where username = :user1");
            qry.bindValue(":mark",total);
            qry.bindValue(":user1",user1);
            if(qry.exec())
            {
                Result r;
                u2 = r.accept(cou,total,user1);
                r.setModal(true);
                close();
                r.exec();
            }
        }

        infile.close();
        cout << total << endl;
        cout <<cou << endl;
        inans.close();
        out.close();
        db.close();
    }
    else{
        QMessageBox::information(this,"Warning","No More Chances.");
    }
}



void Menu::on_Result_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Rohan Katta/Downloads/DB/Mydb.sqlite");
    if(db.open()){
        QSqlQuery qry;
        qry.exec("select * from student");
        while (qry.next())
        {
             if(user1 == qry.value("username").toString())
             {
                 total= qry.value("Out_of").toInt();
                 cou = qry.value("Subject_1").toInt();
                 break;

             }
        }


    }

    Result re;
    re.accept(cou,total,user1);
    re.setModal(true);
    close();
    re.exec();
    db.close();


}


void Menu::on_back_clicked()
{
    this->hide();
    MainWindow *w = new MainWindow();
    w->show();
}

