#ifndef ADMIN_SIGN_IN_H
#define ADMIN_SIGN_IN_H

#include <QDialog>

namespace Ui {
class admin_sign_in;
}

class admin_sign_in : public QDialog
{
    Q_OBJECT

public:
    explicit admin_sign_in(QWidget *parent = nullptr);
    ~admin_sign_in();

private slots:
    void on_pushButton_clicked();

    void on_back_clicked();

private:
    Ui::admin_sign_in *ui;
};

#endif // ADMIN_SIGN_IN_H
