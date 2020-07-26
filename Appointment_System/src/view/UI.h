#ifndef UI_H
#define UI_H

#include <QMainWindow>

#include <iostream>
#include "src/controller/LoginUIController.h"
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginUI; }
QT_END_NAMESPACE

class LoginUI : public QMainWindow
{
    Q_OBJECT

    public:
        LoginUI(QWidget *parent = nullptr);
        ~LoginUI();

    private slots:
        void on_login_btn_clicked();

    private:
        std::string IP;
        int PORT;
        Ui::LoginUI *ui;
        Controller::LoginUIController *controller;
        std::string get_text(QString);
    
};

//TODO: MainWindowUI



#endif // UI_H
