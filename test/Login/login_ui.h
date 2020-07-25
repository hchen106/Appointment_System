#ifndef LOGIN_UI_H
#define LOGIN_UI_H

#include <QMainWindow>
#include <QString>
#include "mainsignup.h"
#include "mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login_UI; }
QT_END_NAMESPACE

class Login_UI : public QMainWindow
{
    Q_OBJECT

public:
    Login_UI(QWidget *parent = nullptr);
    ~Login_UI();

private slots:
    void on_signup_btn_clicked();

    void on_login_btn_clicked();

private:
    Ui::Login_UI *ui;
    MainSignup *mainsignup;
    MainWindow *mainwindow;

};
#endif // LOGIN_UI_H
