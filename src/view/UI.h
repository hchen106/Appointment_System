#ifndef UI_H
#define UI_H

#include <QMainWindow>

#include <iostream>
#include "src/controller/LoginUIController.h"
//#include "src/view/signupUI.h"
//#include "src/view/mainwindow.h"
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginUI; class MainWindow; class signup;}
QT_END_NAMESPACE

class signup : public QMainWindow
{
    Q_OBJECT

    public:
        explicit signup(QWidget *parent = nullptr);
        ~signup();

    private slots:
        void on_signup_btn_clicked();

    private:
        Ui::signup *ui;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void on_logout_btn_clicked();

    private:
        Ui::MainWindow *ui;
};

class LoginUI : public QMainWindow
{
    Q_OBJECT

    public:
        LoginUI(QWidget *parent = nullptr);
        ~LoginUI();

    private slots:
            void on_login_btn_clicked();

            void on_signup_btn_clicked();

    private:
            std::string IP;
            int PORT;
            Ui::LoginUI *ui;
            signup *signupui;
            MainWindow *mainwindow;
};









#endif // UI_H


