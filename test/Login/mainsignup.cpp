#include "mainsignup.h"
#include "ui_mainsignup.h"
#include "DbManager.h"
#include <QMessageBox>
#include <iostream>

static const QString path = "/home/huihao/Desktop/newclone/Appointment_System/test/Login/provider.db";
MainSignup::MainSignup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSignup)
{
    ui->setupUi(this);
}

MainSignup::~MainSignup()
{
    delete ui;
}


void MainSignup::on_signup_btn_clicked()
{

    DbManager db(path);
    QString name = ui->signup_name_entry->text();
    QString password = ui->signup_password_entry->text();
    QString loginID = ui->signup_loginID_entry->text();

    if(db.signupAccount(name,loginID, password)) {
        QMessageBox::information(this, "Sign Up", "Sign Up Successful");
    }else{
        QMessageBox::warning(this, "Sign Up", "Sign Up Unsuccessful");
    }

}
