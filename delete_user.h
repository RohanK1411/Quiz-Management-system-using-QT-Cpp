#ifndef DELETE_USER_H
#define DELETE_USER_H

#include <QDialog>

namespace Ui {
class Delete_user;
}

class Delete_user : public QDialog
{
    Q_OBJECT

public:
    explicit Delete_user(QWidget *parent = nullptr);
    ~Delete_user();

private slots:
    void on_delete_2_clicked();

    void on_back_clicked();

private:
    Ui::Delete_user *ui;
};

#endif // DELETE_USER_H
