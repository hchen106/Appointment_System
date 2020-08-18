#include "src/view/UI.h"
#include "ui_signup.h"
#include "src/controller/DbManager.h"
#include <QMessageBox>
#include <iostream>

static const QString path = "/home/huihao/Desktop/myDB/Appointment_System/Appointment_System/src/controller/provider.db";
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
    int open_hour = ui->open_time_entry->time().hour();
    int open_min = ui->open_time_entry->time().minute();
    int close_hour = ui->close_time_entry->time().hour();
    int close_min = ui->close_time_entry->time().minute();
    QString gap_time = ui->gap_time_entry->text();
    //qDebug() << open_hour;
    //qDebug() << open_min;
    if(db.signupAccount(name,loginID, password, open_hour, open_min, close_hour, close_min, gap_time)) {
        QMessageBox::information(this, "Sign Up", "Sign Up Successful");
    }else{
        QMessageBox::warning(this, "Sign Up", "Sign Up Unsuccessful");
    }
}
