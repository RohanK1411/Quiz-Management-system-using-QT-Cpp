#ifndef SIGN_CONFIRM_H
#define SIGN_CONFIRM_H

#include <QDialog>

namespace Ui {
class sign_confirm;
}

class sign_confirm : public QDialog
{
    Q_OBJECT

public:
    explicit sign_confirm(QWidget *parent = nullptr);
    ~sign_confirm();

private slots:
    void on_Home_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sign_confirm *ui;
};

#endif // SIGN_CONFIRM_H
