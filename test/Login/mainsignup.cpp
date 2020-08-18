#include "mainsignup.h"
#include "ui_mainsignup.h"
#include "DbManager.h"
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QTimeEdit>

static const QString path = "/home/huihao/Desktop/myDB/Appointment_System/test/Login/provider.db";
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
    int open_hour = ui->open_time_entry->time().hour();
    int open_min = ui->open_time_entry->time().minute();
    int close_hour = ui->close_time_entry->time().hour();
    int close_min = ui->close_time_entry->time().minute();
    QString gap_time = ui->gap_time_entry->text();
    qDebug() << open_hour;
    qDebug() << open_min;
    if(db.signupAccount(name,loginID, password, open_hour, open_min, close_hour, close_min, gap_time)) {
        QMessageBox::information(this, "Sign Up", "Sign Up Successful");
    }else{
        QMessageBox::warning(this, "Sign Up", "Sign Up Unsuccessful");
    }

}
