#include "UI.h"
#include "ui_mainsignup.h"
//#include "DbManager.h"
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

    

}
