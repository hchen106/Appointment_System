#include "src/view/UI.h"
#include "ui_signup.h"
#include "src/controller/DbManager.h"
#include <QMessageBox>
#include <iostream>

static const QString path = "/home/huihao/Desktop/master/Appointment_System/Appointment_System/src/controller/provider.db";
Signup::Signup(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}


void Signup::on_signup_btn_clicked()
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
