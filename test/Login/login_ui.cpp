#include "login_ui.h"
#include "ui_login_ui.h"
#include "mainsignup.h"
#include "DbManager.h"
#include <QMessageBox>
#include <QDebug>
static const QString path = "/home/huihao/Desktop/newclone/Appointment_System/test/Login/provider.db";


Login_UI::Login_UI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login_UI)
{
    ui->setupUi(this);
}

Login_UI::~Login_UI()
{
    delete ui;
}


void Login_UI::on_signup_btn_clicked()
{
    //SecDialog signup;
    //signup.setModal(true);
    //signup.exec();
    mainsignup = new MainSignup(this);
    mainsignup->show();


}

void Login_UI::on_login_btn_clicked()
{
    DbManager db(path);

    QString loginID = ui->id_entry->text();
    QString password = ui->password_entry->text();
    qDebug() << loginID;

    if(db.loginAccount(loginID, password)) {
        mainwindow = new MainWindow(this);
        mainwindow->show();
        this->hide();
        //QMessageBox::information(this, "Login", "Login Successful");
    }else{
        QMessageBox::warning(this, "Login", "ID or Password is incorrect");
    }

}
