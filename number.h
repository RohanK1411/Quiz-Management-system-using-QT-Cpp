#ifndef NUMBER_H
#define NUMBER_H

#include <QDialog>

namespace Ui {
class Number;
}

class Number : public QDialog
{
    Q_OBJECT

public:
    explicit Number(QWidget *parent = nullptr);
    ~Number();
    int Get_number();
    int Get_point();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Number *ui;
    int number;
    int point1;
};

#endif // NUMBER_H
