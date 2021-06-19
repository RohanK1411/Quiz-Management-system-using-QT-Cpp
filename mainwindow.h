#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sign_up.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Sign_in_clicked();

    void on_Sign_up_clicked();

    void on_Admin_Sign_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
