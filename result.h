#ifndef RESULT_H
#define RESULT_H

#include <QDialog>
#include <QString>

namespace Ui {
class Result;
}

class Result : public QDialog
{
    Q_OBJECT

public:
    explicit Result(QWidget *parent = nullptr);
    ~Result();
    QString accept(int count,int total,QString temp);


private slots:
    void on_result_clicked();

    void on_home_clicked();

    void on_log_out_clicked();

private:
    Ui::Result *ui;
    int cou1,total;
    QString user,cou2,total3;
};

#endif // RESULT_H
